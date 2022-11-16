#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../graph/node.hpp"

#include <map>
#include <queue>

namespace algorithm {
    std::map<Node*, size_t> dijkstra(const Graph& graph, Node* start);
}

#endif