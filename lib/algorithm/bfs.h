#ifndef BFS_H
#define BFS_H

#include "../graph/graph.h"

#include <map>

namespace algorithm {
    bool bfs(const graph::Graph& graph, graph::Node* start, graph::Node* dest,
            std::map<graph::Node*, size_t>& depth);
}

#endif