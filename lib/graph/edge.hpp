#ifndef EDGE_HPP
#define EDGE_HPP

#include "node.hpp"

namespace graph {
    /*
    A structure for edge
    u: starting point
    v: end point
    w: weight of the edge
    next_: the next edge it connects to 
    */
    struct Edge {
        Node u, v;
        size_t w, next_;
    };
}

#endif