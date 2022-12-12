#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "edge.h"
#include "city.h"

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
        void addVertex(std::string name);
        void addVertex(std::string name, double lat, double lon, size_t population);
        bool hasVertex(std::string name) const;
        Vertex* getVertex(std::string name) const;
        void addEdge(Vertex* v1, Vertex* v2, double weight);
        void addEdge(std::string v1_name, std::string v2_name, double weight);
        Edge getEdge(size_t idx) const; 
        Edge& getEdge(size_t idx);
        std::vector<Vertex*> getVertexList() const;
        std::vector<Edge> getEdgeList() const;
        void clean();
    };
}

#endif