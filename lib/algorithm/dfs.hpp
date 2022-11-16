#ifndef DFS_HPP
#define DFS_HPP

#include "../graph/graph.hpp"
#include "../graph/node.hpp"
#include "../graph/edge.hpp"

namespace algorithm {
    size_t dfs(graph::Graph& graph, Node* start);
}

#endif