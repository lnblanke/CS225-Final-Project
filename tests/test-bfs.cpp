#include "test.h"
#include "../lib/algorithm/bfs.h"

using namespace test;

TEST_CASE("Test small BFS connected", "[bfs]") {
    Graph g;

    setVertices(10);

    add_edge(0, 1, 1);
    add_edge(1, 0, 1);
    add_edge(0, 2, 1);
    add_edge(2, 0, 1);
    add_edge(0, 3, 1);
    add_edge(3, 0, 1);
    add_edge(2, 4, 1);
    add_edge(3, 6, 1);
    add_edge(5, 6, 1);
    add_edge(7, 9, 1);
    add_edge(8, 7, 1);
    add_edge(9, 7, 1);
    add_edge(7, 8, 1);
    add_edge(6, 7, 1);
    add_edge(6, 5, 1);

    map<Vertex*, size_t> depth;
    REQUIRE(algorithm::bfs(g, vertex(0), vertex(9), depth));

    size_t true_depth[] = {1, 2, 2, 2, 3, 4, 3, 4, 5, 5};

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[vertex(i)] == true_depth[i]);
    }
}


TEST_CASE("Test small BFS unconnected", "[bfs]") {
    Graph g;

    setVertices(10);

    add_edge(0, 1, 1);
    add_edge(0, 2, 1);
    add_edge(0, 3, 1);
    add_edge(2, 3, 1);
    add_edge(3, 4, 1);
    add_edge(5, 6, 1);
    add_edge(7, 9, 1);
    add_edge(8, 7, 1);
    add_edge(9, 7, 1);

    map<Vertex*, size_t> depth;
    size_t true_depth[] = {1, 2, 2, 2, 3, 0, 0, 0, 0, 0};

    REQUIRE(! algorithm::bfs(g, vertex(0), vertex(9), depth));

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[vertex(i)] == true_depth[i]);
    }
}

TEST_CASE("Test small BFS multiple queries", "[bfs]") {
    Graph g;
    
    setVertices(10);

    add_edge(0, 1, 1);
    add_edge(0, 2, 1);
    add_edge(0, 3, 1);
    add_edge(2, 3, 1);
    add_edge(3, 4, 1);
    add_edge(5, 6, 1);
    add_edge(7, 9, 1);
    add_edge(8, 7, 1);
    add_edge(9, 7, 1);

    map< Vertex*, size_t> depth;
    size_t true_depth_1[] = {1, 2, 2, 2, 3, 0, 0, 0, 0, 0};

    REQUIRE(! algorithm::bfs(g, vertex(0), vertex(8), depth));

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[vertex(i)] == true_depth_1[i]);
    }

    add_edge(1, 9, 1);
    add_edge(1, 5, 1);

    size_t true_depth_2[] = {1, 2, 2, 2, 3, 3, 4, 4, 0, 3};

    REQUIRE(! algorithm::bfs(g, vertex(0), vertex(8), depth));

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[vertex(i)] == true_depth_2[i]);
    }
}