#ifndef DFS_H
#define DFS_H

#include "../graph/graph.h"
#include "../graph/node.h"
#include "../graph/edge.h"

#include <map>

namespace algorithm {
    size_t dfs(graph::Graph& graph, graph::Node* start, graph::Node* end, int flow, 
    std::map<graph::Node*, size_t>& depth);
}

#endif