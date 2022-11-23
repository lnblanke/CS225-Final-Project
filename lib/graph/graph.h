#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include "edge.h"

#include <vector>
#include <set>
#include <stdexcept>

namespace graph {
    /*
    The class for graph
    With respect to our dataset, the graph should be undirected and may contains 
    multiple edges and cycles, but self loops would not exist
    */
    class Graph {
    private:
        /*
        The node list of the graph
        The data structure is made std::set to make find node O(log(n))
        */
        std::set<Node*> nodes_;

        /*
        The edge list of the graph
        */
        std::vector<Edge*> edges_;
    
    public:
        Graph() = default;
        
        /*
        Construct a graph with only nodes
        nodes: the nodes list of the graph
        */
        Graph(const std::vector<Node*>& nodes) {
            for (const auto& node : nodes)
                nodes_.insert(node);
        }

        /*
        Add an edge to the graph
        u: startpoint
        v: endpoint
        weight: weight of the edge
        */
        void addEdge(Node* u, Node* v, size_t weight) {
            if (nodes_.find(u) == nodes_.end() || nodes_.find(v) == nodes_.end()) {
                throw std::invalid_argument("At least one of the nodes doesn't exist");
            }

            edges_.push_back(new Edge(u, v, weight, u->getHead()));
            u->getHead() = edges_.size();
        }

        /*
        Get an edge at index

        idx: the index of the edge, 1 indexed
        */
        Edge* getEdge(size_t idx) const {
            return edges_[idx - 1];
        }
    };
}

#endif