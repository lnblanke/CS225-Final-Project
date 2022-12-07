#ifndef DFS_H
#define DFS_H

#include "../graph/graph.h"

#include <map>

namespace algorithm {
    double dfs(graph::Graph& graph, graph::Vertex* start, graph::Vertex* end, double flow, 
    std::map<graph::Vertex*, size_t>& depth);
}

#endif