/**
* @file iterator.hpp
* @description Bu dosya Iterator sınıfını ve bu sınıfa ait metotları ve değişkenleri içerir.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 17.11.2024
* @author Emir Ali Duman G231210004 emir.duman@sakarya.edu.tr
*/
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Node.hpp"
#include <string>

class DLinkedList;

class Iterator {
public:
    Iterator(Node* p) : current(p) {}

    std::string& operator*() const {
        return current->data;
    }

    Iterator& operator++() {
        current = current->next;
        return *this;
    }

    Iterator& operator--() {
        current = current->prev;
        return *this;
    }

    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }
    
    bool operator==(const Iterator& other) const {
        return current == other.current;
    }

private:
    Node* current;
};

#endif