#include "dijkstra.h"

#include <queue>

using namespace graph;

std::map<Vertex*, size_t> algorithm::dijkstra(const Graph& graph, Vertex* start) {
    std::priority_queue<std::pair<size_t, Vertex*>, std::vector<std::pair<size_t, Vertex*>>, std::greater<std::pair<size_t, Vertex*>>> q;
    std::map<Vertex*, size_t> dist;

    for (const auto v : graph.getVertexList())
        dist[v] = -1;

    q.push({0, start});
    dist[start] = 0;

    while (! q.empty()) {
        auto [dis, p] = q.top();
        q.pop();

        if (dist.find(p) != dist.end()) continue;

        for (auto i = p->getHead(); i; i = graph.getEdge(i).next) {
            auto v = graph.getEdge(i).v;
            if ((dist.find(v) == dist.end() || dist[p] + graph.getEdge(i).w < dist[v])
                && graph.getEdge(i).w) {
                dist[v] = dist[p]  + graph.getEdge(i).w;
                q.push({dist[v], v});
            }
        }
    }

    return dist;
}