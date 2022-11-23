#include "bfs.h"

#include <queue>
#include <iostream>

using namespace graph;

bool algorithm::bfs(const Graph& graph, Node* start, Node* dest, std::map<Node*, size_t>& depth) {
    depth = std::map<Node*, size_t>();
    std::queue<Node*> q;

    q.push(start);
    depth[start] = 1;

    while (! q.empty()) {
        auto p = q.front();
        q.pop();

        for (auto i = p->getHead(); i; i = graph.getEdge(i)->next) {
            auto edge = graph.getEdge(i);
            if (edge->w && depth.find(edge->v) == depth.end()) {
                q.push(edge->v);
                depth[edge->v] = depth[p] + 1;
            }
        }
    }

    return depth.find(dest) != depth.end();
}