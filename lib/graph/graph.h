#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "edge.h"

#include <vector>
#include <stdexcept>
#include <map>

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
        */
        std::map<std::string, Vertex*> vertices_;

        /*
        The edge list of the graph
        */
        std::vector<Edge> edges_;
    
    public:
        Graph() = default;
        ~Graph();
        Graph(const Graph& other);
        Graph& operator=(const Graph& other);
        void addVertex(Vertex& v);
        Vertex* getVertex(std::string name) const;
        void addEdge(Vertex* v1, Vertex* v2, double weight);
        Edge getEdge(size_t idx) const; 
        Edge& getEdge(size_t idx);
        std::vector<Vertex*> getVertexList() const;
        std::vector<Edge> getEdgeList() const;
    };
}

#endif