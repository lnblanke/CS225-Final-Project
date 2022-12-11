#include "../lib/algorithm/dijkstra.h"
#include "test.h"

using namespace test;

TEST_CASE("Test Dijkstra simple unweighted", "[dijkstra]") {
    setVertices(5);
    add_edge(0, 2);
    add_edge(0, 4);
    add_edge(1, 0);
    add_edge(1, 4);
    add_edge(2, 0);
    add_edge(2, 3);
    add_edge(2, 4);
    add_edge(4, 3);

    auto result = algorithm::dijkstra(g, vertex(0));
    double ans[] = {0, -1, 1, 2, 1};

    for (int i = 0; i < 5; i++) 
        REQUIRE(result[vertex(i)] == ans[i]);
}

TEST_CASE("Test Dijkstra small weighted", "[dijkstra]") {
    setVertices(5);
    add_edge(0, 1, 3);
    add_edge(0, 4, 1);
    add_edge(1, 4, 2);
    add_edge(1, 2, 6);
    add_edge(2, 3, 1);
    add_edge(2, 0, 4);
    add_edge(3, 0, 5);
    add_edge(4, 3, 10);

    auto result = algorithm::dijkstra(g, vertex(0));
    double ans[] = {0, 3, 9, 10, 1};

    for (int i = 0; i < 5; i++) 
        REQUIRE(result[vertex(i)] == ans[i]);
}

TEST_CASE("Test Dijkstra small multiple edges", "[dijkstra]") {
    setVertices(5);
    add_edge(0, 1, 3);
    add_edge(0, 4, 1);
    add_edge(1, 4, 2);
    add_edge(1, 2, 6);
    add_edge(2, 3, 1);
    add_edge(2, 0, 4);
    add_edge(3, 0, 5);
    add_edge(4, 3, 10);
    add_edge(4, 3, 2);
    add_edge(4, 2, 3);
    add_edge(1, 2, 2);

    auto result = algorithm::dijkstra(g, vertex(0));
    double ans[] = {0, 3, 4, 3, 1};

    for (int i = 0; i < 5; i++) 
        REQUIRE(result[vertex(i)] == ans[i]);
}

TEST_CASE("Test Dijkstra middle", "[dijkstra]") {
    setVertices(10);
    config_adj_matrix({{0., 6., 0., 2., 4., 0., 0., 3., 0., 0.},
       {0., 0., 6., 5., 0., 1., 0., 0., 0., 7.},
       {0., 2., 0., 0., 3., 6., 7., 0., 9., 9.},
       {0., 3., 9., 0., 8., 0., 1., 2., 5., 0.},
       {9., 2., 5., 2., 0., 4., 2., 0., 5., 2.},
       {8., 6., 9., 0., 2., 0., 2., 0., 0., 0.},
       {1., 5., 0., 0., 9., 2., 0., 5., 4., 0.},
       {6., 7., 6., 1., 2., 0., 1., 0., 0., 1.},
       {9., 0., 0., 7., 4., 0., 6., 0., 0., 6.},
       {0., 2., 1., 3., 4., 8., 9., 8., 0., 0.}});

    auto result = algorithm::dijkstra(g, vertex(0));

    double ans[] = {0, 5, 5, 2, 4, 5, 3, 3, 7, 4};

    for (int i = 0; i < 10; i++) 
        REQUIRE(result[vertex(i)] == ans[i]);
}

TEST_CASE("Test Dijkstra large", "[dijkstra]") {
    setVertices(20);
    config_adj_matrix({{ 0.,  0.,  2.,  0.,  0., 19.,  5.,  0.,  0.,  6.,  0.,  0.,  0.,
         0.,  0.,  0.,  0.,  0.,  0.,  0.},
       { 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  4.,  0.,
         0.,  0.,  0.,  0.,  0.,  0.,  0.},
       { 0.,  4.,  0., 15.,  0., 17., 13., 10.,  0.,  0.,  0., 11.,  2.,
         0.,  0.,  9.,  0.,  0.,  0.,  0.},
       {11.,  0., 13.,  0.,  0.,  0.,  0., 18.,  0.,  0.,  0.,  0.,  1.,
         0.,  3.,  0.,  0.,  0., 17.,  0.},
       { 0.,  0.,  0.,  0.,  0.,  3.,  0.,  0., 12.,  0.,  0.,  0., 13.,
         0.,  0.,  3.,  0.,  0.,  0.,  0.},
       { 0., 13., 14.,  0.,  0.,  0.,  0.,  0.,  0.,  5.,  2.,  0.,  0.,
        14.,  0.,  0.,  4.,  0.,  0.,  0.},
       { 0., 18.,  0.,  3.,  3.,  0.,  0.,  0., 14.,  0., 17.,  0., 18.,
         0., 18.,  0.,  0.,  0.,  0.,  0.},
       { 0.,  0., 10., 13.,  0.,  0.,  0.,  0.,  3.,  0.,  0.,  0.,  0.,
         0.,  0.,  0., 19.,  1.,  0., 10.},
       { 0.,  0.,  0.,  0.,  1.,  0.,  1., 19.,  0.,  8.,  0.,  6.,  0.,
         0.,  0.,  0.,  0., 15., 19.,  0.},
       {17.,  0.,  7.,  9.,  2.,  0., 11.,  0.,  0.,  0.,  0.,  0.,  0.,
         0.,  0.,  0.,  0., 18.,  0.,  0.},
       { 0.,  0.,  9.,  0.,  3.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,
         0.,  0.,  0.,  0.,  0.,  0.,  0.},
       { 0.,  0.,  0.,  0.,  0.,  0., 13.,  0., 15., 16.,  0.,  0.,  0.,
         0.,  0.,  0.,  0.,  0., 17., 16.},
       { 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,
         9.,  5.,  0., 16.,  0.,  0.,  0.},
       { 0.,  0.,  2.,  0.,  0.,  0.,  0.,  0., 17.,  0.,  0.,  0.,  0.,
         0.,  0.,  0.,  0.,  0., 17.,  0.},
       { 6.,  0., 18.,  0.,  0.,  0.,  0.,  0.,  0., 11.,  0.,  0.,  0.,
         0.,  0.,  0.,  0.,  0.,  0.,  0.},
       { 6.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,
         0.,  0.,  0.,  0.,  0.,  0.,  0.},
       { 0.,  0.,  0.,  0.,  7.,  1.,  0.,  0.,  0.,  0.,  0., 19.,  5.,
         0.,  6.,  0.,  0.,  0.,  0.,  0.},
       { 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,   0.,  0., 17.,
         0.,  0.,  4., 17.,  0.,  0.,  0.},
       { 0.,  0.,  0.,  0.,  0.,  0.,  1., 14.,  8.,  0.,  0.,  0., 10.,
         0.,  0.,  0.,  0.,  0.,  0.,  0.},
       { 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,
         0., 12.,  0.,  0.,  0.,  0.,  0.}});

    auto result = algorithm::dijkstra(g, vertex(0));

    double ans[] = {0, 6, 2, 8, 8, 11, 5, 12, 15, 6, 13, 10, 4, 13, 9, 11, 15, 13, 25, 22};

    for (int i = 0; i < 20; i++) 
        REQUIRE(result[vertex(i)] == ans[i]);
}

TEST_CASE("Test Dijkstra real", "[dijkstra]") {
    initializeMap();

    auto result = algorithm::dijkstra(Map, Map.getVertex("San Francisco,CA"));

    REQUIRE(result[Map.getVertex("Los Angeles,CA")] - 2.5133830107 <= 1e-8);
    REQUIRE(result[Map.getVertex("Boston,MA")] - 7.9799174235 <= 1e-8);
    REQUIRE(result[Map.getVertex("New York,NY")] - 7.4937890716 <= 1e-8);
    REQUIRE(result[Map.getVertex("Champaign,IL")] - 7.5332856004 <= 1e-8);
    REQUIRE(result[Map.getVertex("Las Vegas,NV")] - 2.5540219433 <= 1e-8);
}