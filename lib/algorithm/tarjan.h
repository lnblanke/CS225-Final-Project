#ifndef TARJAN_H
#define TARJAN_H

#include "../graph/graph.h"

#include <map>

using namespace graph;

namespace algorithm {
    std::map<Vertex*, size_t> tarjan(const Graph& graph);
}

#endif