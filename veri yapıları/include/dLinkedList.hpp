#ifndef DLINKEDLIST_HPP
#define DLINKEDLIST_HPP

#include <iostream>
#include "iterator.hpp"
#include "Node.hpp" 
#include <string>
using namespace std;
class DLinkedList {
public:
    DLinkedList();
    ~DLinkedList();
    void insert(const string &value);
    void display() const;

    Iterator begin() const;
    Iterator end() const;

private:
    Node* head;

    friend class Iterator;
};

#endif