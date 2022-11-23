#include "dijkstra.h"

#include <queue>

using namespace graph;

std::map<Node*, size_t> algorithm::dijkstra(const Graph& graph, Node* start) {
    std::priority_queue<std::pair<size_t, Node*>, std::vector<std::pair<size_t, Node*>>, std::greater<std::pair<size_t, Node*>>> q;
    std::map<Node*, size_t> dist;

    q.push({0, start});
    dist[start] = 0;

    while (! q.empty()) {
        auto [dis, p] = q.top();
        q.pop();

        if (dist.find(p) != dist.end()) continue;

        for (auto i = p->getHead(); i; i = graph.getEdge(i)->next) {
            auto v = graph.getEdge(i)->v;
            if (dist.find(v) == dist.end() || dist[p] + graph.getEdge(i)->w < dist[v]) {
                dist[v] = dist[p]  + graph.getEdge(i)->w;
                q.push({dist[v], v});
            }
        }
    }

    return dist;
}