#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

namespace graph {
    /*
    A structure for edge
    u: starting point
    v: end point
    w: weight of the edge
    next_: the next edge it connects to 
    */
    struct Edge {
        Vertex* u, *v;
        double w;
        size_t next;

        Edge(Vertex* U, Vertex* V, double W, size_t nxt) {
            u = U, v = V, w = W, next = nxt;
        }

        bool operator==(const Edge& other) const {
            return *u == *(other.u) && *v == *(other.v) && w == other.w && next == other.w;
        }
    };
}

#endif