#ifndef NODE_H
#define NODE_H

#include <string>

namespace graph {
    /*
    Class for a node
    */
    class Node {
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
        Node(const std::string& name) {
            name_ = name;
        }
        
        /*
        Compare operator for the class
        */
        bool operator<(const Node& n1) {
            return name_ < n1.name_;
        }

        /*
        Return the name of the node;
        */
        inline std::string getName() { return name_; }

        /*
        Return the head of the adjacency list for the node
        */
        inline size_t& getHead() { return head_; }
    };
}

#endif