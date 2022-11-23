#include "dfs.h"

using namespace graph;

size_t algorithm::dfs(Graph& graph, Node* start, Node* end, int flow, 
std::map<Node*, size_t>& depth) {
    if (start == end) return flow;

    auto residual = flow;

    for (auto i = start->getHead(); i; i = graph.getEdge(i)->next) {
        auto v = graph.getEdge(i)->v;

        if (graph.getEdge(i)->w && depth[v] == depth[start] + 1) {
            auto update = dfs(graph, v, end, std::min(residual, graph.getEdge(i)->w), depth);

            if (! update) {
                depth[v] = 0;
            }

            residual -= update;
            graph.getEdge(i)->w -= update;
            graph.getEdge(i ^ 1)->w += update;
        }
    }

    return flow - residual;
}