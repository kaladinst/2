#include "../include/dLinkedList.hpp"
#include <iostream>

using namespace std;

DLinkedList::DLinkedList() {
    head = nullptr;
}

DLinkedList::~DLinkedList() {
    Node *current = head;
    while(current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

void DLinkedList::insert(const string& value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if(head == nullptr) {
        head = newNode;
    }
    else {
        Node *temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void DLinkedList::display() const {
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Iterator DLinkedList::begin() const{
    return Iterator(head);
}

Iterator DLinkedList::end() const {
    return Iterator(head);
}