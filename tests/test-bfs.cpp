#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>

#include "../lib/algorithm/bfs.h"
#include "../lib/graph/graph.h"

using namespace std;

TEST_CASE("Test small BFS connected", "[bfs]") {
    vector<graph::Node*> nodes;

    for (int i = 0; i < 10; i++) {
        nodes.push_back(new graph::Node(to_string(i)));
    }

    graph::Graph g(nodes);

    g.addEdge(nodes[0], nodes[1], 1);
    g.addEdge(nodes[1], nodes[0], 1);
    g.addEdge(nodes[0], nodes[2], 1);
    g.addEdge(nodes[2], nodes[0], 1);
    g.addEdge(nodes[0], nodes[3], 1);
    g.addEdge(nodes[3], nodes[0], 1);
    g.addEdge(nodes[2], nodes[4], 1);
    g.addEdge(nodes[3], nodes[6], 1);
    g.addEdge(nodes[5], nodes[6], 1);
    g.addEdge(nodes[7], nodes[9], 1);
    g.addEdge(nodes[8], nodes[7], 1);
    g.addEdge(nodes[9], nodes[7], 1);
    g.addEdge(nodes[7], nodes[8], 1);
    g.addEdge(nodes[6], nodes[7], 1);
    g.addEdge(nodes[6], nodes[5], 1);

    map<graph::Node*, size_t> depth;
    REQUIRE(algorithm::bfs(g, nodes[0], nodes[9], depth));

    size_t true_depth[] = {1, 2, 2, 2, 3, 4, 3, 4, 5, 5};

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[nodes[i]] == true_depth[i]);
    }
}


TEST_CASE("Test small BFS unconnected", "[bfs]") {
    vector<graph::Node*> nodes;

    for (int i = 0; i < 10; i++) {
        nodes.push_back(new graph::Node(to_string(i)));
    }

    graph::Graph g(nodes);

    g.addEdge(nodes[0], nodes[1], 1);
    g.addEdge(nodes[0], nodes[2], 1);
    g.addEdge(nodes[0], nodes[3], 1);
    g.addEdge(nodes[2], nodes[3], 1);
    g.addEdge(nodes[3], nodes[4], 1);
    g.addEdge(nodes[5], nodes[6], 1);
    g.addEdge(nodes[7], nodes[9], 1);
    g.addEdge(nodes[8], nodes[7], 1);
    g.addEdge(nodes[9], nodes[7], 1);

    map<graph::Node*, size_t> depth;
    size_t true_depth[] = {1, 2, 2, 2, 3, 0, 0, 0, 0, 0};

    REQUIRE(! algorithm::bfs(g, nodes[0], nodes[8], depth));

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[nodes[i]] == true_depth[i]);
    }
}

TEST_CASE("Test small BFS multiple queries", "[bfs]") {
    vector<graph::Node*> nodes;

    for (int i = 0; i < 10; i++) {
        nodes.push_back(new graph::Node(to_string(i)));
    }

    graph::Graph g(nodes);

    g.addEdge(nodes[0], nodes[1], 1);
    g.addEdge(nodes[0], nodes[2], 1);
    g.addEdge(nodes[0], nodes[3], 1);
    g.addEdge(nodes[2], nodes[3], 1);
    g.addEdge(nodes[3], nodes[4], 1);
    g.addEdge(nodes[5], nodes[6], 1);
    g.addEdge(nodes[7], nodes[9], 1);
    g.addEdge(nodes[8], nodes[7], 1);
    g.addEdge(nodes[9], nodes[7], 1);

    map<graph::Node*, size_t> depth;
    size_t true_depth_1[] = {1, 2, 2, 2, 3, 0, 0, 0, 0, 0};

    REQUIRE(! algorithm::bfs(g, nodes[0], nodes[8], depth));

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[nodes[i]] == true_depth_1[i]);
    }

    g.addEdge(nodes[1], nodes[9], 1);
    g.addEdge(nodes[1], nodes[5], 1);

    size_t true_depth_2[] = {1, 2, 2, 2, 3, 3, 4, 4, 0, 3};

    REQUIRE(! algorithm::bfs(g, nodes[0], nodes[8], depth));

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[nodes[i]] == true_depth_2[i]);
    }
}