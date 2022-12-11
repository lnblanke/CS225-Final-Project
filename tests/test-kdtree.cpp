#include "test.h"
#include "../lib/algorithm/kd-tree.h"

using namespace test;

TEST_CASE("Test KD tree small", "[kdtree]") {
    vector<City*> v;

    for (int i = 0; i < 5; i++)
        v.push_back(new City(to_string(i), i, i, i));

    KDTree tree(v);

    REQUIRE(tree.findNearestNeighbor({4.3, 3.9}) == v[4]);
    REQUIRE(tree.findNearestNeighbor({2.5, 2.6}) == v[3]);
    REQUIRE(tree.findNearestNeighbor({1.8, 2.2}) == v[2]);
}