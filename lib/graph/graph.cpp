#include "graph.h"

using namespace graph;

Graph::~Graph() {
    for (auto& v : vertices_) {
        delete v.second;
    }
}

Graph::Graph(const Graph& other) {
    for (const auto v : other.getVertexList())
        vertices_[v->getName()] = new Vertex(v->getName());

    for (const auto e : other.getEdgeList()) {
        addEdge(getVertex(e.u->getName()), getVertex(e.v->getName()), e.w);
    }            
}

Graph& Graph::operator=(const Graph& other) {
    if (this == &other) return *this;

    this->~Graph();

    for (const auto v : other.getVertexList())
        vertices_[v->getName()] = new Vertex(v->getName());

    for (const auto e : other.getEdgeList()) {
        addEdge(getVertex(e.u->getName()), getVertex(e.v->getName()), e.w);
    }            

    return *this;
}

void Graph::addVertex(Vertex& v) {
    if (getVertex(v.getName()))    
        throw std::invalid_argument("Vertex with name " + v.getName() + " already exist in graph");

    vertices_[v.getName()] = &v;
}

Vertex* Graph::getVertex(std::string name) const {
    if (vertices_.find(name) != vertices_.end())
        return vertices_.at(name);

    return nullptr;
}

/*
Add an edge to the graph
u: startpoint
v: endpoint
weight: weight of the edge
*/
void Graph::addEdge(Vertex* v1, Vertex* v2, double weight) {
    if (getVertex(v1->getName()) != v1 || getVertex(v2->getName()) != v2)
        throw std::invalid_argument("The vertex with the name is not the same as in the graph");

    edges_.push_back({v1, v2, weight, v1->getHead()});
    v1->getHead() = edges_.size();
}

/*
Get an edge at index

idx: the index of the edge, 1 indexed
*/
Edge Graph::getEdge(size_t idx) const{
    return edges_[idx - 1];
}
/*
Get an edge at index

idx: the index of the edge, 1 indexed
*/
Edge& Graph::getEdge(size_t idx) {
    return edges_[idx - 1];
}

std::vector<Vertex*> Graph::getVertexList() const {
    std::vector<Vertex*> list;

    for (const auto& it : vertices_) list.push_back(it.second);

    return list;
}

std::vector<Edge> Graph::getEdgeList() const {
    return edges_;
}