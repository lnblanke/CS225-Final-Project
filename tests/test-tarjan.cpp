#include "../lib/algorithm/tarjan.h"
#include "test.h"

using namespace test;

typedef vector<vector<size_t>> v2d;

#define begin(i) size_t i = 0

/*
This test is not finished
*/

bool check(const Graph& g, const v2d& real, const map<Vertex*, size_t>& result) {
    for (begin(i); i < real.size(); i++) {
        for (begin(j); j < real[i].size(); j++) {
            for (auto k = j + 1; k < real[i].size(); k++) {
                if (result.at(g.getVertex(to_string(real[i][j]))) != 
                    result.at(g.getVertex(to_string(real[i][k]))))
                    return 0;
            }
        }
    }

    for (begin(i); i < real.size(); i++) {
        for (auto j = i + 1; j < real.size(); j++) {
            for (begin(k); k < real[i].size(); k++) {
                for (begin(t); t < real[j].size(); t++) {
                    if (result.at(g.getVertex(to_string(real[i][k]))) ==
                        result.at(g.getVertex(to_string(real[j][t]))))
                        return 0;
                }
            }
        }
    }

    return 1;
}

TEST_CASE("Test tarjan simple", "[tarjan]") {
    Graph g;

    setVertices(10);

    add_edge(0, 1, 0);
    add_edge(0, 3, 0);
    add_edge(1, 4, 0);
    add_edge(1, 2, 0);
    add_edge(1, 9, 0);
    add_edge(2, 4, 0);
    add_edge(2, 5, 0);
    add_edge(3, 4, 0);
    add_edge(4, 8, 0);
    add_edge(4, 5, 0);
    add_edge(5, 8, 0);
    add_edge(5, 6, 0);
    add_edge(7, 5, 0);
    add_edge(7, 6, 0);
    add_edge(8, 4, 0);
    add_edge(8, 3, 0);
    add_edge(8, 6, 0);

    auto result = algorithm::tarjan(g);

    v2d ans = {{0}, {1}, {2}, {3, 4, 5, 8}, {6}, {7}, {9}};

    REQUIRE(check(g, ans, result));
}