#include "tarjan.h"

#include <functional>
#include <stack>
#include <unordered_set>

typedef std::map<Vertex*, size_t> m;

using namespace graph;

m algorithm::tarjan(const Graph& graph) {
    m dfn, low, group;
    std::stack<Vertex*> s;
    std::unordered_set<Vertex*> instack;
    size_t timestamp = 0, num_group = 0;

    std::function<void(Vertex*)> helper;
    helper = [&](Vertex* cur) {
        dfn[cur] = low[cur] = ++timestamp;
        s.push(cur);
        instack.insert(cur);

        for (auto i = cur->getHead(); i; i = graph.getEdge(i).next) {
            auto v = graph.getEdge(i).v;
            
            if (dfn.find(v) == dfn.end()) {
                helper(v);

                low[cur] = std::min(low[cur], low[v]);
            } else if (instack.find(v) != instack.end()) {
                low[cur] = std::min(low[cur], dfn[v]);
            }
        }

        if (dfn[cur] == low[cur]) {
            auto top = s.top();
            num_group++;

            do {
                top = s.top();
                s.pop();
                instack.erase(top);
                group[top] = num_group;
            } while (top != cur);
        }
    };

    for (const auto vertex: graph.getVertexList()) {
        if (dfn.find(vertex) == dfn.end()) {
            helper(vertex);
        }
    }

    return group;
}