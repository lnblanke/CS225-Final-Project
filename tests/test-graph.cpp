#include "../lib/graph/graph.h"
#include "test.h"

using namespace test;

TEST_CASE("Test simple graph", "[graph]") {
    Graph g;
    
    setVertices(10);

    for (int i = 0; i < 10; i++)
        add_edge(0, i, 0);

    auto vertexList = g.getVertexList();

    for (int i = 0; i < 10; i++)
        REQUIRE(vertexList[i] == g.getVertex(to_string(i)));

    auto edgeList = g.getEdgeList();

    for (int i = 0; i < 10; i++)
        REQUIRE(edgeList[i] == g.getEdge(i + 1));
}

TEST_CASE("Test copy constructor and operator=", "[graph]") {
    Graph g;

    setVertices(5);

    add_edge(0, 1, 0);
    add_edge(1, 2, 0);
    add_edge(0, 3, 0);
    add_edge(2, 4, 0);
    add_edge(3, 2, 0);

    Graph g1(g);

    for (size_t i = 0; i < 5; i++) {
        REQUIRE(*g.getVertex(to_string(i)) == *g1.getVertex(to_string(i)));
    }

    for (size_t i = 1; i <= 5; i++) {
        REQUIRE(g.getEdge(i) == g1.getEdge(i));
    }
}

TEST_CASE("Test wrong operations", "[graph]") {
    // Graph g;

    // setVertices(5);

    // try {
    //     g.addVertex("1");

    //     REQUIRE(0);
    // } catch (invalid_argument& e) {}

    // try {
    //     add_edge(3, 5, 0);

    //     REQUIRE(0);
    // } catch (invalid_argument& e) {}

    // try {
    //     g.getVertex("5");

    //     REQUIRE(0);
    // } catch (invalid_argument& e) {}
}