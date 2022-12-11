#include "test.h"
#include "../lib/algorithm/bfs.h"

using namespace test;

TEST_CASE("Test small BFS connected", "[bfs]") {
    setVertices(10);

    add_edge(0, 1);
    add_edge(1, 0);
    add_edge(0, 2);
    add_edge(2, 0);
    add_edge(0, 3);
    add_edge(3, 0);
    add_edge(2, 4);
    add_edge(3, 6);
    add_edge(5, 6);
    add_edge(7, 9);
    add_edge(8, 7);
    add_edge(9, 7);
    add_edge(7, 8);
    add_edge(6, 7);
    add_edge(6, 5);

    map<Vertex*, size_t> depth;
    REQUIRE(algorithm::bfs(g, vertex(0), vertex(9), depth));

    size_t true_depth[] = {1, 2, 2, 2, 3, 4, 3, 4, 5, 5};

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[vertex(i)] == true_depth[i]);
    }
}

TEST_CASE("Test small BFS unconnected", "[bfs]") {
    setVertices(10);

    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(5, 6);
    add_edge(7, 9);
    add_edge(8, 7);
    add_edge(9, 7);

    map<Vertex*, size_t> depth;
    size_t true_depth[] = {1, 2, 2, 2, 3, 0, 0, 0, 0, 0};

    REQUIRE(! algorithm::bfs(g, vertex(0), vertex(9), depth));

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[vertex(i)] == true_depth[i]);
    }
}

TEST_CASE("Test small BFS multiple queries", "[bfs]") {
    setVertices(10);

    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(5, 6);
    add_edge(7, 9);
    add_edge(8, 7);
    add_edge(9, 7);

    map<Vertex*, size_t> depth;
    size_t true_depth_1[] = {1, 2, 2, 2, 3, 0, 0, 0, 0, 0};

    REQUIRE(! algorithm::bfs(g, vertex(0), vertex(8), depth));

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[vertex(i)] == true_depth_1[i]);
    }

    add_edge(1, 9);
    add_edge(1, 5);

    size_t true_depth_2[] = {1, 2, 2, 2, 3, 3, 4, 4, 0, 3};
    
    REQUIRE(! algorithm::bfs(g, vertex(0), vertex(8), depth));

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[vertex(i)] == true_depth_2[i]);
    }
}

TEST_CASE("Test middle BFS", "[bfs]") {
    setVertices(10);
    config_adj_matrix({{0., 3., 7., 0., 0., 0., 0., 8., 0., 0.},
       {9., 0., 4., 0., 0., 5., 2., 0., 3., 4.},
       {4., 7., 0., 0., 0., 7., 0., 8., 3., 2.},
       {3., 6., 6., 0., 0., 5., 4., 1., 5., 4.},
       {9., 7., 7., 9., 0., 0., 9., 0., 1., 6.},
       {0., 7., 6., 0., 0., 0., 0., 0., 6., 2.},
       {0., 2., 1., 0., 4., 0., 0., 0., 0., 2.},
       {3., 9., 6., 0., 1., 3., 0., 0., 0., 2.},
       {6., 0., 0., 8., 5., 3., 9., 0., 0., 6.},
       {4., 9., 6., 0., 0., 4., 7., 0., 9., 0.}});

    
    size_t true_depth[] = {1, 2, 2, 4, 3, 3, 3, 2, 3, 3};
    map<Vertex*, size_t> depth;
    
    REQUIRE(algorithm::bfs(g, vertex(0), vertex(9), depth));

    for (int i = 0; i < 10; i++) {
        REQUIRE(depth[vertex(i)] == true_depth[i]);
    }
}

TEST_CASE("Test large BFS", "[bfs]") {
    setVertices(20);
    config_adj_matrix({{ 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  3.,  0.,  0.,  0.,  0.,
         1.,  0.,  0.,  1.,  0.,  0.,  0.},
       { 0.,  0.,  0.,  0., 10.,  0.,  0.,  0.,  8.,  0.,  0.,  3.,  0.,
         0., 14.,  0.,  9., 11.,  0.,  0.},
       { 7.,  0.,  0., 14.,  0.,  3.,  0.,  0.,  0.,  0., 10.,  0.,  0.,
        15.,  0.,  0.,  0.,  0.,  0., 12.},
       { 7.,  0.,  0.,  0.,  0., 12., 19.,  0.,  0.,  0.,  0.,  0., 17.,
         0.,  4.,  0.,  0.,  0.,  5.,  2.},
       { 0., 17.,  0.,  0.,  0.,  0.,  0., 18.,  0.,  0.,  0.,  0.,  0.,
         8., 15.,  0.,  2.,  0.,  0.,  0.},
       { 0.,  0.,  0., 16.,  0.,  0.,  0.,  0.,  0.,  0., 19.,  0.,  0.,
         0.,  0.,  0.,  0., 18.,  0.,  0.},
       { 0.,  0.,  0.,  0., 16.,  0.,  0.,  0.,  0.,  3.,  0.,  0.,  0.,
         0.,  0.,  0.,  7.,  0.,  0.,  0.},
       {12.,  0.,  0., 16.,  5.,  0.,  0.,  0., 17.,  0., 16.,  0., 15.,
         0.,  0.,  0.,  0.,  0.,  0., 18.},
       { 0.,  0.,  0.,  0.,  0.,  0., 10.,  0.,  0.,  0.,  0.,  0.,  0.,
         0., 13.,  0.,  0.,  0.,  0., 17.},
       {16.,  0.,  0.,  0.,  0.,  0.,  6., 19.,  0.,  0.,  0.,  4.,  0.,
         0.,  0.,  0.,  7.,  0.,  0.,  0.},
       { 0.,  4.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,
         0.,  0.,  0., 10.,  0.,  0.,  0.},        
       { 0.,  0.,  0.,  0.,  0., 15.,  0.,  0., 11.,  0.,  0.,  0.,  6.,
         0.,  0.,  0., 15.,  9.,  0.,  0.},
       { 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0., 18.,  0.,  0.,  0.,  0.,
        13.,  0.,  0.,  0.,  6.,  0., 17.},
       { 0., 16., 10.,  0.,  0., 14.,  0.,  0.,  0.,  0.,  0.,  0., 19.,
         0.,  0., 11.,  0.,  0.,  0.,  0.},
       { 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,
         0.,  0.,  0.,  0.,  0.,  0., 15.},
       { 0.,  6.,  0.,  0.,  0.,  0.,  2., 10.,  7.,  0.,  3.,  0.,  0.,
         0.,  0.,  0.,  0.,  0.,  0., 15.},
       { 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,
         0.,  0.,  0.,  0.,  0.,  0.,  0.},
       {17.,  0.,  2.,  0.,  0.,  0.,  0., 11.,  0.,  0.,  0., 11.,  0.,
         0.,  0.,  8.,  0.,  0.,  0.,  0.},
       {16.,  0.,  5.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0., 16.,
         0.,  3.,  0.,  0.,  9.,  0., 13.},
       { 0.,  0.,  0.,  0., 18.,  0., 17.,  0.,  0.,  0.,  0.,  3.,  0.,
         0.,  0.,  0.,  7.,  0.,  0.,  0.}});

    
    size_t true_depth[] = {1, 3, 3, 4, 4, 3, 3, 4, 2, 4, 4, 4, 3, 2, 3, 3, 2, 4, 5, 3};
    map<Vertex*, size_t> depth;
    
    REQUIRE(algorithm::bfs(g, vertex(0), vertex(19), depth));

    for (int i = 0; i < 20; i++) {
        REQUIRE(depth[vertex(i)] == true_depth[i]);
    }
}

TEST_CASE("Test BFS real", "[bfs]") {
    initializeMap();

    map<Vertex*, size_t> depth;
    
    REQUIRE(algorithm::bfs(Map, Map.getVertex("Chicago,IL"), Map.getVertex("Seattle,WA"), depth));

    REQUIRE(depth[Map.getVertex("Champaign,IL")] == 2);
    REQUIRE(depth[Map.getVertex("Dallas,TX")] == 2);
    REQUIRE(depth[Map.getVertex("Miami,FL")] == 2);
    REQUIRE(depth[Map.getVertex("Washington,DC")] == 2);
}