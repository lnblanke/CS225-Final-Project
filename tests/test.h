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

    static void setVertices(size_t num) {}
    static void add_edge(size_t i, size_t j, int w) {}
    static Vertex* vertex(size_t i) {return new Vertex("no");}
}
