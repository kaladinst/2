#include "../include/List.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

List::List() {
    head = nullptr;
    current = nullptr;
    displayCount = 10;
}

Node::Node(Tree* tree) {
    this->tree = tree;
    next = nullptr;
}

List::~List() {
    Node* current = head;
    if(current != nullptr) {
        do{
            Node*next = current->next;
            delete current;
            current = next;
        } while(current != head);
    }
}

void List::insert(Tree* tree) {
    Node* newNode = new Node(tree);
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        current = head;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

std::string List::showCurrent() {
    if (current != nullptr) {
        std::ostringstream oss;
        oss << "Current Tree:\n";

        current->tree->printTreeStructure();

        return oss.str();
    }
    return "No current tree";
}

void List::mirror() {
    current->tree->mirror();
    showList();
}

void List::proceed() {
    if (current == nullptr) {
        current = head;
    } else if (current->next != nullptr) {
        current = current->next;
    }
    showList();
}

void List::regress() {
    if(current == nullptr || current == head) {
        return;
    }
    Node* temp = head;
    while(temp->next != current) {
        temp = temp->next;
    }
    current = temp;
    showList();
}

void List::remove() {
    if (current == head) {
        head = head->next;
        delete current->tree;
        delete current;
        current = head;
    } else {
        Node* temp = head;
        while (temp->next != current) {
            temp = temp->next;
        }
        temp->next = current->next;
        delete current->tree;
        delete current;
        current = temp;
    }
    showList();
}
void List::showList() {
    if (current == nullptr) {
        current = head;
    }

    Node* temp = head;
    std::ostringstream dots;
    std::ostringstream addresses;
    std::ostringstream values;
    std::ostringstream arrows;
    std::ostringstream nextAddresses;

    cout << "\033[2J\033[1;1H";

    int totalNodes = 0;
    while (temp != nullptr) { 
        totalNodes++;
        temp = temp->next;
    }

    temp = head; 
    int startNode = 0;
    int currentIndex = 0;

    Node* tempCurrent = head;
    while (tempCurrent != nullptr && tempCurrent != current) {
        currentIndex++;
        tempCurrent = tempCurrent->next;
    }

    if (currentIndex >= displayCount) {
        startNode = currentIndex - (currentIndex % displayCount);
    } else {
        startNode = 0;
    }
    currentIndex--;

    for (int i = 0; i < startNode; i++) {
        temp = temp->next;
    }

    int count = 0;
    while (temp != nullptr && count < displayCount) {
        dots << std::string(8, '.') << " ";

        std::ostringstream addressStream;
        addressStream << std::setw(4) << std::setfill('0') << std::hex << (reinterpret_cast<uintptr_t>(temp) & 0xFFFF);
        addresses << std::setw(8) << std::setfill(' ') << addressStream.str() << " ";

        values << std::setw(8) << std::setfill(' ') << std::dec << temp->tree->calculateTotalValue() << " ";
        if (temp == current) {
            arrows << std::string(8, '^') << " ";
        } else {
            arrows << std::string(8, ' ') << " ";
        }

        if (temp->next != nullptr) {
            std::ostringstream nextAddressStream;
            nextAddressStream << std::setw(4) << std::setfill('0') << std::hex << (reinterpret_cast<uintptr_t>(temp->next) & 0xFFFF);
            nextAddresses << std::setw(8) << std::setfill(' ') << nextAddressStream.str() << " ";
        } else {
            nextAddresses << std::setw(8) << std::setfill(' ') << "NULL" << " ";
        }

        temp = temp->next;
        count++;
    }

    cout << dots.str() << endl;
    cout << addresses.str() << endl;
    cout << values.str() << endl;
    cout << nextAddresses.str() << endl;
    cout << dots.str() << endl;
    cout << arrows.str() << endl;
}