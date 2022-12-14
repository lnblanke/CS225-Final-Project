#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../graph/graph.h"

#include <map>
#include <queue>

using namespace graph;

namespace algorithm {
    std::map<Vertex*, double> dijkstra(const Graph& graph, Vertex* start);
}

#endif