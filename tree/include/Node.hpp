#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "Tree.hpp"

class Node {
    private:
    Node *next;
    Tree* tree;
    Node(Tree* tree);

    public:
    friend class List;
    friend class Tree;
};

#endif