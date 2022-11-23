#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../graph/graph.h"

#include <map>
#include <queue>

namespace algorithm {
    std::map<graph::Node*, size_t> dijkstra(const graph::Graph& graph, graph::Node* start);
}

#endif