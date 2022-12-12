#include "dijkstra.h"

#include <queue>

using namespace graph;

std::map<Vertex*, double> algorithm::dijkstra(const Graph& graph, Vertex* start) {
    std::priority_queue<std::pair<size_t, Vertex*>, std::vector<std::pair<size_t, Vertex*>>, std::greater<std::pair<size_t, Vertex*>>> q;
    std::map<Vertex*, double> dist;

    for (const auto v : graph.getVertexList())
        dist[v] = -1;

    q.push({0, start});
    dist[start] = 0;

    while (! q.empty()) {
        auto [dis, p] = q.top();
        q.pop();

        for (auto i = p->getHead(); i; i = graph.getEdge(i).next) {
            auto v = graph.getEdge(i).v;
            if ((dist[v] == -1 || dist[p] + graph.getEdge(i).w < dist[v])
                && graph.getEdge(i).w) {
                dist[v] = dist[p]  + graph.getEdge(i).w;
                q.push({dist[v], v});
            }
        }
    }

    return dist;
}