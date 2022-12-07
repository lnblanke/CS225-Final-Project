#ifndef VERTEX_H
#define VERTEX_H

#include <string>

namespace graph {
    /*
    Class for a node
    */
    class Vertex {
    private:
        /*
        Name of the node, in default should be the name of the city
        */
        std::string name_;
        
        /*
        The first edge in the adjacent list that the node has
        */
        size_t head_ = 0;

    public:
        /*
        Initialize a node with name
        name: the name for the node
        */
        Vertex(const std::string& name) {
            name_ = name;
        }

        Vertex(const Vertex& other) {
            name_ = other.name_;
        }

        Vertex& operator=(const Vertex& other) {
            if (*this == other) return *this;

            name_ = other.name_;

            return *this;
        }
        
        /*
        Compare operator for the class
        */
        friend bool operator<(const Vertex& v1, const Vertex& v2) {
            return v1.name_ < v2.name_;
        }

        friend bool operator==(const Vertex& v1, const Vertex& v2) { 
            return v1.name_ == v2.name_ && v1.head_ == v2.head_;
        }

        /*
        Return the name of the node;
        */
        inline std::string getName() const { return name_; }

        /*
        Return the head of the adjacency list for the node
        */
        inline size_t& getHead() { return head_; }
    };
}

// bool operator==(const graph::Vertex* v1, const graph::Vertex* v2) {
//     return *v1 == *v2;
// }

#endif