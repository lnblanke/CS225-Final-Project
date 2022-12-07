#ifndef DINIC_H
#define DINIC_H

#include "bfs.h"
#include "dfs.h"

#define INF 2e9

using namespace graph;

namespace algorithm {
    double dinic(Graph& g, Vertex* source, Vertex* sink) {
        double cost = 0;

        std::map<Vertex*, size_t> depth;        

        while (algorithm::bfs(g, source, sink, depth)) {
            cost += algorithm::dfs(g, source, sink, INF, depth);
        }

        return cost;
    }
}

#endif