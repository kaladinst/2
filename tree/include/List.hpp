#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"
#include "Tree.hpp"

class List{
    private:
    Node *head;
    Node *current;
    int displayCount;

    public:
    List();
    ~List();
    void remove();
    void proceed();
    void regress();
    void showList();
    void insert(Tree* tree);
    std::string showCurrent();
    void mirror();

};
#endif