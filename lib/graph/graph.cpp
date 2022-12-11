#include "graph.h"
using namespace graph;

Graph::~Graph() {
    for (auto& v : vertices_) {
        delete v.second;
    }

    vertices_ = std::map<std::string, graph::Vertex*>();
    edges_ = std::vector<graph::Edge>();
}

Graph::Graph(const Graph& other) {
    for (const auto v : other.getVertexList()) {
        vertices_[v->getName()] = new Vertex(v->getName());
    }

    for (const auto e : other.getEdgeList()) {
        addEdge(getVertex(e.u->getName()), getVertex(e.v->getName()), e.w);
    }            
}

Graph& Graph::operator=(const Graph& other) {
    if (this == &other) return *this;

    this->~Graph();

    for (const auto v : other.getVertexList()) {
        try {
            vertices_[v->getName()] = new City(*static_cast<City*>(v));
        } catch (std::invalid_argument& e) {
            vertices_[v->getName()] = new Vertex(v->getName());
        }
    }

    for (const auto e : other.getEdgeList()) {
        addEdge(getVertex(e.u->getName()), getVertex(e.v->getName()), e.w);
    }            

    return *this;
}

void Graph::addVertex(std::string name) {
    if (hasVertex(name))
        throw std::invalid_argument("Vertex with name " + name + " already exist in graph");

    vertices_[name] = new Vertex(name);
}

void Graph::addVertex(std::string name, double lat, double lon, size_t population) {
    if (hasVertex(name))
        throw std::invalid_argument("Vertex with name " + name + " already exist in graph");

    vertices_[name] = new City(name, lat, lon, population);
}

bool Graph::hasVertex(std::string name) const {
    try {
        getVertex(name);
        return 1;
    } catch (std::invalid_argument& e) {
        return 0;
    }
}

Vertex* Graph::getVertex(std::string name) const {
    if (vertices_.find(name) != vertices_.end())
        return vertices_.at(name);

    throw std::invalid_argument("Vertex with name " + name + " is not in the graph");
}

/*
Add an edge to the graph
u: startpoint
v: endpoint
weight: weight of the edge
*/
void Graph::addEdge(Vertex* v1, Vertex* v2, double weight) {
    if (! v1 || ! v2 || getVertex(v1->getName()) != v1 || getVertex(v2->getName()) != v2)
        throw std::invalid_argument("The vertex with the name is not the same as in the graph");

    edges_.push_back({v1, v2, weight, v1->getHead()});
    v1->getHead() = edges_.size();
}

void Graph::addEdge(std::string v1_name, std::string v2_name, double weight) {
    if (! hasVertex(v1_name) || ! hasVertex(v2_name))
        throw std::invalid_argument("The vertex with the name is not in the graph");

    edges_.push_back({vertices_[v1_name], vertices_[v2_name], weight, vertices_[v1_name]->getHead()});
    vertices_[v1_name]->getHead() = edges_.size();
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

void Graph::clean() {
    for (auto it = vertices_.begin(); it != vertices_.end();) {
        if (! it->second->getHead())
            vertices_.erase(it++);
        else it++;
    }
}