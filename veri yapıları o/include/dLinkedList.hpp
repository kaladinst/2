#ifndef DLINKEDLIST_HPP
#define DLINKEDLIST_HPP

#include <iostream>
#include "iterator.hpp"
#include "Node.hpp" 
#include <string>

class DLinkedList {
public:
    DLinkedList();
    ~DLinkedList();
    void insert(const std::string &value);
    void display() const;
    void Mutation();
    void Crossover();
    int size() const;
    void printToScreen();
    Node* findMiddle();
    Node* getLastNode() const;

    Iterator begin() const;
    Iterator end() const;
private:
    Node* head;
    Node* tail;

    friend class Iterator;
};

#endif