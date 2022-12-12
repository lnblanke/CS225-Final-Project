#pragma once

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>
#include <stdexcept>
#include <map>
#include <iostream>

#include "../lib/graph/graph.h"

using std::map;
using std::string;
using std::vector;
using std::to_string;
using std::invalid_argument;

using graph::Edge;
using graph::Graph;
using graph::Vertex;

namespace test {
    static Graph g;

    static void setVertices(int num) {
        g = Graph();

        while (--num >= 0) {
            g.addVertex(to_string(num));
        }
    }

    static Vertex* vertex(size_t i) {
        return g.getVertex(to_string(i));
    }

    static void add_edge(size_t i, size_t j, double w) {
        g.addEdge(vertex(i), vertex(j), w);
    }

    static void add_edge(size_t i, size_t j) {
        g.addEdge(vertex(i), vertex(j), 1);
    }

    static void config_adj_matrix(vector<vector<double>> weights) {
        for (auto i = 0ul; i < weights.size(); i++) {
            for (auto j = 0ul; j < weights[i].size(); j++) {
                if (weights[i][j])
                    add_edge(i, j, weights[i][j]);
            }
        }
    }
}
