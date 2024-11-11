#ifndef NODE_HPP
#define NODE_HPP

#include <string>

struct Node {
    std::string data;
    Node* next;
    Node* prev;    
};

#endif