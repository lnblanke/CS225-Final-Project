#ifndef BFS_H
#define BFS_H

#include "../graph/graph.h"

#include <map>

namespace algorithm {
    bool bfs(const graph::Graph& graph, graph::Vertex* start, graph::Vertex* dest,
            std::map<graph::Vertex*, size_t>& depth);
}

#endif