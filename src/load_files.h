#ifndef LOAD_FILES_H
#define LOAD_FILES_H

#include "../lib/data/file.h"
#include "../lib/data/table.h"
#include "../lib/graph/graph.h"
#include "../lib/graph/city.h"
#include "../lib/algorithm/kd-tree.h"

#include <string>
#include <map>
#include <vector>

using namespace data;
using std::string;
using std::map;
using std::vector;
using std::set;
using graph::Graph;
using graph::City;
using graph::getDistance;

#define e_vec vector<string>()
#define e_set set<string>()
#define cast_int(ptr) stoi(ptr)
#define cast_double(ptr) stod(ptr)

const size_t road_speed = 120; //km/h
const size_t air_speed = 828; //km/h

const string airport_file_path = "../data/airports.dat";
const string route_file_path = "../data/routes.dat";
const string population_file_path = "../data/uscities.csv";
const string node_file_path = "../data/NA.cnode";
const string edge_file_path = "../data/NA.cedge";

// Transform coordinate to latitude/longitude
const double coeff_x = (440699 - 289286) / (1126.7899 - 7310.1147);
const double bias_x = 440699 - coeff_x * 1126.7899; 
const double coeff_y = (135999 - 94670) / (5243.70711 - 2446.4495);
const double bias_y = 135999 - coeff_y * 5243.70711;

const vector<string> airport_features = {
    "Airport ID",
    "Name",
    "City",
    "Country",
    "IATA",
    "ICAO",
    "Latitude",
    "Longitude",
    "Altitude",
    "Timezone",
    "DST",
    "Tz database time zone",
    "Type",
    "Source"
};

const set<string> airport_drops = {
    "Airport ID",
    "ICAO",
    "Timezone",
    "DST",
    "Tz database time zone",
    "Type",
    "Source"
};

const vector<string> route_features = {
    "Airline",
    "Airline ID",
    "Source airport",
    "Source airport ID",
    "Destination airport",
    "Destination airport ID",
    "Codeshare",
    "Stops",
    "Equipment"
};

const set<string> route_drops = {
    "Airline",
    "Airline ID",
    "Source airport ID",
    "Destination airport ID",
    "Codeshare",
    "Stops",
    "Equipment"
};

const set<string> population_drops = {
    "city_ascii",
    // "state_id",
    "state_name",
    "county_fips",
    "county_name",
    "density",
    "source",
    "military",
    "incorporated",
    "timezone",
    "ranking",
    "id"
};

const vector<string> node_features = {
    "Node ID",
    "Normalized X",
    "Normalized Y",
};

const vector<string> edge_features = {
    "Edge ID", 
    "Start Node ID",
    "End Node ID",
    "L2 distance"
};

Table& process(const string& file, vector<string> features = e_vec,  
const set<string>& drops = e_set, char sep = ',') {
    auto data = read_file(file, sep);

    Table* table = new Table();

    if (features.empty()) {
        for (const auto& item : data[0]) {
            features.push_back(item);
        }

        data.erase(data.begin());
    }

    for (const auto& f : features) {
        table->addColumn(f);
    }    

    table->addRows(data.size());

    for (auto i = 0ul; i < data.size(); i++) {
        for (auto j = 0ul; j < data[i].size(); j++) {
            table->setItem(i, j, data[i][j]);
        }
    }

    for (const auto& drop : drops) {
        table->dropCol(drop);
    }

    return *table;
}

graph::Graph* csv_to_graph() {
    auto airport_table = process(airport_file_path, airport_features, airport_drops);
    auto route_table = process(route_file_path, route_features, route_drops);
    auto city_table = process(population_file_path, e_vec, population_drops);
    auto node_table = process(node_file_path, node_features, {"Node ID"}, ' ');
    auto edge_table = process(edge_file_path, edge_features, {"Edge ID"}, ' ');

    // @TODO
    Graph* g = new Graph();
    vector<City*> v;

    for (auto i = 0ul; i < city_table.getNumRows(); i++) {
        auto insert = new City(city_table["city"][i] + ", " + city_table["state_id"][i], 
                                cast_double(city_table["lat"][i]),
                                cast_double(city_table["lng"][i]),
                                cast_int(city_table["population"][i]));        

        for (const auto& v : g->getVertexList()) {
            auto city = static_cast<City*>(v);
            if (abs(city->getLatitude() - insert->getLatitude()) <= 0.5 && 
                abs(city->getLongitude() - insert->getLongitude()) <= 0.5) {
                (*city) += *insert;
                delete insert;
                insert = 0;
                break;
            }
        }
        
        if (! insert) continue;

        g->addVertex(*insert);
        v.push_back(insert);
    }

    KDTree tree(v);

    map<int, City*> mapping;

    for (auto i = 0ul; i < node_table.getNumRows(); i++) {
        double lng = -(cast_double(node_table["Normalized X"][i]) * coeff_x + bias_x) / 3600;
        double lat = (cast_double(node_table["Normalized Y"][i]) * coeff_y + bias_y) / 3600;

        mapping[i] = tree.findNearestNeighbor({lat, lng});
    }    

    for (auto i = 0ul; i < edge_table.getNumRows(); i++) {
        auto u = cast_int(edge_table["Start Node ID"][i]);
        auto v = cast_int(edge_table["End Node ID"][i]);

        if (mapping[u] != mapping[v]) {
            g->addEdge(mapping[u], mapping[v], getDistance(mapping[u], mapping[v]) / road_speed);
            g->addEdge(mapping[v], mapping[u], getDistance(mapping[u], mapping[v]) / road_speed);
        }
    }

    map<string, City*> airports;
 
    for (auto i = 0ul; i < airport_table.getNumRows(); i++) {
        auto ap = airport_table["IATA"][i];
        if (airport_table["Country"][i] == "United States") {
            airports[ap] = tree.findNearestNeighbor({cast_double(airport_table["Latitude"][i]), 
                                                     cast_double(airport_table["Longitude"][i])
                                                    });
        }
    }

    for (auto i = 0ul; i < route_table.getNumRows(); i++) {
        auto source = route_table["Source airport"][i];
        auto dest = route_table["Destination airport"][i];
        if (airports.find(source) != airports.end() && airports.find(dest) != airports.end())
            g->addEdge(airports[source], airports[dest], 
                       getDistance(airports[source], airports[dest]) / air_speed);
    }

    return g;
}

#endif