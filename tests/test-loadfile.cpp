#include "test.h"
#include "../src/load_files.h"
using namespace test;

TEST_CASE("Test load file", "loadfile") {
    auto Map = *(csv_to_graph());

    set<Vertex*> cities;

    cities.insert(Map.getVertex("Washington,DC"));
    cities.insert(Map.getVertex("Chicago,IL"));
    cities.insert(Map.getVertex("Miami,FL"));
    cities.insert(Map.getVertex("San Francisco,CA"));
    cities.insert(Map.getVertex("Seattle,WA"));
    cities.insert(Map.getVertex("Boston,MA"));
    cities.insert(Map.getVertex("New York,NY"));
    cities.insert(Map.getVertex("Denver,CO"));
    cities.insert(Map.getVertex("Dallas,TX"));
    cities.insert(Map.getVertex("Atlanta,GA"));
    cities.insert(Map.getVertex("Philadelphia,PA"));

    for (auto i = Map.getVertex("Los Angeles,CA")->getHead(); i; i = Map.getEdge(i).next) {
        if (cities.find(Map.getEdge(i).v) != cities.end())
            cities.erase(Map.getEdge(i).v);
    }

    REQUIRE(cities.empty());

    for (const auto v : Map.getVertexList())
        REQUIRE(v->getHead());
}