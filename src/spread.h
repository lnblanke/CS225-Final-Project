#pragma once

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stdexcept>

#include "../lib/graph/graph.h"
#include "../lib/graph/city.h"
#include "../lib/algorithm/dijkstra.h"
#include "../lib/algorithm/tarjan.h"
#include "../lib/algorithm/dinic.h"

using std::vector;
using std::set;
using std::map;
using std::queue;
using graph::Graph;
using graph::Vertex;
using graph::Edge;
using graph::City;
using algorithm::dijkstra;
using algorithm::tarjan;
using algorithm::dinic;

#define INF 2e9
#define cast(ptr) static_cast<City*>(ptr)

typedef long long ll;

class Spread {
private:
    Graph graph_;
    Graph infected_;
    City* start_;
    map<City*, pair<City*, double>> prob_;
    map<City*, string> status_;
    size_t timestamp = 0;
    size_t latency_period_;
    double cost = 0;
    queue<pair<size_t, City*>> latency_;

    inline size_t generateLatency() {
        return latency_period_ + (rand() % 4 - 2);
    }

public:
    Spread(const Graph& g, City* start, size_t latency_period) {
        graph_ = g;
        start_ = start;
        latency_period_ = latency_period;

        for (const auto v : graph_.getVertexList()) {
            status_[cast(v)] = "N";
        }

        latency_.push({generateLatency(), start_});
        status_[start_] = "L";
    }

    vector<vector<Vertex*>> intersect() {
        auto groups = tarjan(infected_);

        map<int, vector<Vertex*>> m;

        for (const auto& it : groups) {
            m[it.second].push_back(it.first);
        }

        vector<vector<Vertex*>> ans;

        for (const auto& it : m) {
            if (it.second.size() > 1) 
                ans.push_back(it.second);
        }

        return ans;
    }

    void isolate(const vector<string>& blocking) {
        for (const auto& v : blocking) {
            if (! graph_.getVertex(v))
                throw std::invalid_argument("The city " + v + " is not found");
            if (status_[cast(graph_.getVertex(v))] != "N")
                throw std::invalid_argument("The city " + v + " is infected or blocked");
        }

        Graph calc;
        vector<int> indices;

        calc.addVertex(*(new Vertex("source")));
        calc.addVertex(*(new Vertex("sink")));

        for (const auto& v : blocking)
            status_[cast(graph_.getVertex(v))] = "B";

        for (const auto v : graph_.getVertexList()) {
            if (status_[cast(v)] == "N")
                calc.addVertex(*(new Vertex(*v)));
        }

        auto find = [&](City* v) -> Vertex* {
            if (status_[v] == "B")
                return calc.getVertex("sink");
            if (status_[v] == "N")
                return calc.getVertex(v->getName());
            return calc.getVertex("source");
        };

        for (auto i = 0ul; i < graph_.getEdgeList().size(); i++) {
            const auto& e = graph_.getEdge(i);
            if ((status_[cast(e.u)] == status_[cast(e.v)] && status_[cast(e.u)] != "N") || 
                status_[cast(e.u)] == "I" || status_[cast(e.u)] == "L" || status_[cast(e.v)] == "B")  
                continue;
            
            calc.addEdge(find(cast(e.u)), find(cast(e.v)), e.w);
            indices.push_back(i);
        }

        cost += dinic(calc, calc.getVertex("source"), calc.getVertex("sink"));

        for (auto i = 0ul; i < indices.size(); i++) {
            if (! calc.getEdge(i).w)
                graph_.getEdge(indices[i]).w = 0;
        }
    }

    double getCost() const { return cost; }

    size_t getTimeStamp() const {
        return timestamp;
    }

    map<City*, std::string> getStatus() const {
        return status_;
    }

    void nextStep() {
        timestamp++;

        while (! latency_.empty() && latency_.front().first <= timestamp) {
            auto [_, u] = latency_.front();
            latency_.pop();

            status_[u] = "I";
            
            auto dist = dijkstra(graph_, u);

            for (auto& it : prob_) {
                if (status_[it.first] != "N") continue;
            
                auto v = cast(it.first);
                auto p = u->getPopulation() * pow(v->getPopulation(), 0.5) * dist[v] / (24e11);

                if (it.second.second > p) {
                    it.second = {u, p};
                }
            }

            for (auto i = u->getHead(); i; i = graph_.getEdge(i).next) {
                if (infected_.getVertex(graph_.getEdge(i).v->getName())) {
                    infected_.addEdge(u, graph_.getEdge(i).v, 0);
                    infected_.addEdge(graph_.getEdge(i).v, u, 0);
                }
            }
        }

        for (const auto& it : prob_) {
            if (status_[it.first] != "N") continue;

            if (rand() % 1 <= it.second.second) {
                infected_.addVertex(*(it.first));
                infected_.addEdge(it.second.first, it.first, 0);
                latency_.push({timestamp + generateLatency(), it.first});
                status_[it.first] = "L";
            }
        }
    }
};