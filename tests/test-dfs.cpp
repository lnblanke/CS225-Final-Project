#include "../lib/algorithm/dfs.h"
#include "test.h"

using namespace test;

void checkWeights(const Graph& g, const vector<double>& weight) {
    for (auto i = 0ul; i < weight.size(); i++)
        REQUIRE(g.getEdge(i + 1).w == weight[i]);
}

TEST_CASE("Test DFS simple", "[dfs]") {
    setVertices(5);

    add_edge(0, 1, 1);
    add_edge(1, 0, 0);
    add_edge(0, 2, 2);
    add_edge(2, 0, 0);
    add_edge(0, 4, 5);
    add_edge(4, 0, 0);
    add_edge(1, 3, 4);
    add_edge(3, 1, 0);
    add_edge(2, 1, 3);
    add_edge(1, 2, 0);
    add_edge(2, 3, 2);
    add_edge(3, 2, 0);
    add_edge(2, 4, 6);
    add_edge(4, 2, 0);
    add_edge(3, 4, 1);
    add_edge(4, 3, 0);

    map<Vertex*, size_t> depth = {
        {vertex(0), 1},
        {vertex(1), 2},
        {vertex(2), 2},
        {vertex(3), 3},
        {vertex(4), 2}
    };

    REQUIRE(algorithm::dfs(g, vertex(0), vertex(4), 1e7, depth) == 5);

    checkWeights(g, {1, 0, 2, 0, 0, 5, 4, 0, 3, 0, 2, 0, 6, 0, 1, 0});
}

TEST_CASE("Test DFS small", "[dfs]") {
    setVertices(5);

    add_edge(0, 2, 3);
    add_edge(2, 0, 0);
    add_edge(0, 3, 3);
    add_edge(3, 0, 0);
    add_edge(1, 0, 1);
    add_edge(0, 1, 0);
    add_edge(1, 3, 7);
    add_edge(3, 1, 0);
    add_edge(1, 2, 6);
    add_edge(2, 1, 0);
    add_edge(2, 3, 5);
    add_edge(3, 2, 0);
    add_edge(2, 4, 4);
    add_edge(4, 2, 0);
    add_edge(3, 4, 2);
    add_edge(4, 3, 0);

    map<Vertex*, size_t> depth = {
        {vertex(0), 2},
        {vertex(1), 1},
        {vertex(2), 2},
        {vertex(3), 2},
        {vertex(4), 3}
    };

    REQUIRE(algorithm::dfs(g, vertex(1), vertex(4), 1e7, depth) == 6);

    checkWeights(g, {3, 0, 3, 0, 1, 0, 5, 2, 2, 4, 5, 0, 0, 4, 0, 2});
}