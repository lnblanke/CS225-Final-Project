#include <bits/stdc++.h>
#include "../lib/data/file.h"
#include "../lib/graph/graph.h"
#include "../lib/algorithm/bfs.h"
#include "../lib/algorithm/dfs.h"
#include "../lib/algorithm/dijkstra.h"

using namespace std;

int main() {
    auto matrix = data::read_file("../data/airports.dat");

    for (const auto& row : matrix) {
        for (const auto& col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }

    auto* g = new graph::Graph(vector<graph::Node*>());
}