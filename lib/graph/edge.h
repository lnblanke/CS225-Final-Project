#ifndef EDGE_H
#define EDGE_H

#include "node.h"

namespace graph {
    /*
    A structure for edge
    u: starting point
    v: end point
    w: weight of the edge
    next_: the next edge it connects to 
    */
    struct Edge {
        Node* u, *v;
        int w;
        size_t next;

        Edge(Node* U, Node* V, size_t W, size_t nxt) {
            u = U, v = V, w = W, next = nxt;
        }
    };
}

#endif