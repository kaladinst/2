#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Node.hpp"
using namespace std;
class DLinkedList;

class Iterator {
public:
    Iterator(Node* p) : current(p) {}

    string& operator*() const {
        return current->data;
    }

    Iterator& operator++() {
        current = current->next;
        return *this;
    }

    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }

private:
   Node* current;
};

#endif