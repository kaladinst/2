/**
* @file dLinkedList.hpp
* @description Bu dosya DLinkedList sınıfını ve bu sınıfa ait metotları ve değişkenleri içerir.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 17.11.2024
* @author Emir Ali Duman G231210004 emir.duman@sakarya.edu.tr
*/
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
    void Mutation(DLinkedList &lines);
    void readChromosomesFromFile(DLinkedList &lines);
    DLinkedList parseGenes(const std::string &line);
    void Crossover(DLinkedList &lines);
    void printToScreen(DLinkedList &lines);
    void AutoOperation(DLinkedList &lines);
    int size() const;
    Iterator begin() const;
    Iterator end() const;
private:
    Node* head;
    int listSize;
    friend class Iterator;
};

#endif