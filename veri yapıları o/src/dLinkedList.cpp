#include "../include/dLinkedList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

DLinkedList::DLinkedList() {
    head = nullptr;
}

DLinkedList::~DLinkedList() {
    Node *current = head;
    while (current != nullptr) {
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

    if (head == nullptr) {
        head = newNode;
        tail = newNode; 
        newNode->prev = nullptr;
    } else {
        tail->next = newNode;
        tail = newNode;
        newNode->prev = tail;
    }
}

void DLinkedList::display() const {
    if (head == nullptr) return;
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int DLinkedList::size() const {
    int count = 0;
    Node *temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* DLinkedList::findMiddle() {
    if (head == nullptr) {
        cout << "Liste boş" << endl;
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* DLinkedList::getLastNode() const {
    return tail;
}

Iterator DLinkedList::begin() const {
    return Iterator(head);
}

Iterator DLinkedList::end() const {
    return Iterator(nullptr);
}

void DLinkedList::Crossover() {
    DLinkedList newFirst;
    DLinkedList newSecond;
    cout << "Çaprazlama işlemi için ilk satır numarasını seçiniz" << endl;
    int firstRow;
    cin >> firstRow;

    cout << "Çaprazlama işlemi için ikinci satır numarasını seçiniz" << endl;
    int secondRow;
    cin >> secondRow;

    ifstream file("src/Dna.txt");
    if (!file) {
        cerr << "Dosya açılamadı" << endl;
        return;
    }

    DLinkedList lines;
    string line;
    while (getline(file, line)) {
        lines.insert(line);
    }
    file.close();

    Iterator firstIt = lines.begin();
    for (int i = 0; i < firstRow && firstIt != lines.end(); ++i) {
        ++firstIt;
    }

    if (firstIt == lines.end()) {
        cerr << "Geçersiz satır numarası" << endl;
        return;
    }

    Iterator secondIt = lines.begin();
    for (int i = 0; i < secondRow && secondIt != lines.end(); ++i) {
        ++secondIt;
    }

    if (secondIt == lines.end()) {
        cerr << "Geçersiz satır numarası" << endl;
        return;
    }

    string firstLine = *firstIt;
    string secondLine = *secondIt;

    cout << "Seçilen ilk satır: " << firstLine << endl;
    cout << "Seçilen ikinci satır: " << secondLine << endl;

    istringstream iss1(firstLine);
    DLinkedList firstGenes;
    string g1;
    while (iss1 >> g1) {
        firstGenes.insert(g1);
    }
    istringstream iss2(secondLine);
    DLinkedList secondGenes;
    string g2;
    while (iss2 >> g2) {
        secondGenes.insert(g2);
    }

    Node *firstMiddle = firstGenes.findMiddle();
    Node *secondMiddle = secondGenes.findMiddle();

    Node *current = firstGenes.head;
    while (current != firstMiddle) {
        newFirst.insert(current->data);
        current = current->next;
    }

    current = secondMiddle;
    while (current != nullptr) {
        newFirst.insert(current->data);
        current = current->next;
    }

    current = firstMiddle;
    while (current != nullptr) {
        newSecond.insert(current->data);
        current = current->next;
    }

    current = secondGenes.head;
    while (current != secondMiddle) {
        newSecond.insert(current->data);
        current = current->next;
    }

    cout << "Çaprazlama işlemi tamamlandı" << endl;
    cout << "Yeni Kromozomlar:" << endl;
    cout << "1. Kromozom: ";
    newFirst.display();
    cout << endl;
    cout << "2. Kromozom: ";
    newSecond.display();
    cout << endl;
}

void DLinkedList::Mutation() {
    cout << "Mutasyon işlemi için bir satır numarası seçiniz" << endl;
    int row;
    cin >> row;

    ifstream file("src/Dna.txt");
    if (!file) {
        cerr << "Dosya açılamadı" << endl;
        return;
    }

    DLinkedList lines;
    string line;
    while (getline(file, line)) {
        lines.insert(line);
    }
    file.close();

    Iterator it = lines.begin();
    for (int i = 0; i < row && it != lines.end(); ++i) {
        ++it;
    }

    if (it == lines.end()) {
        cerr << "Geçersiz satır numarası" << endl;
        return;
    }

    line = *it;
    cout << "Seçilen satır: " << line << endl;
    cout << "Mutasyon işlemi yapılacak genin numarası: " << endl;
    int gene;
    cin >> gene;

    istringstream iss(line);
    DLinkedList genes;
    string g;
    while (iss >> g) {
        genes.insert(g);
    }

    if (gene < 0 || gene >= genes.size()) {
        cerr << "Geçersiz gen numarası" << endl;
        return;
    }

    Iterator geneIt = genes.begin();
    for (int i = 0; i < gene && geneIt != genes.end(); ++i) {
        ++geneIt;
    }

    if (geneIt == genes.end()) {
        cerr << "Geçersiz gen numarası" << endl;
        return;
    }

    *geneIt = "X";

    ostringstream oss;
    for (Iterator it = genes.begin(); it != genes.end(); ++it) {
        oss << *it << " ";
    }

    string newLine = oss.str();
    newLine.pop_back();
    *it = newLine;

    cout << "Mutasyon işlemi tamamlandı" << endl;
    cout << "Yeni Kromozom: " << newLine << endl;

}

void DLinkedList::printToScreen() {
    ifstream file("src/Dna.txt");
    if (!file) {
        cerr << "Dosya açılamadı" << endl;
        return;
    }

    DLinkedList lines;
    string line;
    while (getline(file, line)) {
        lines.insert(line);
    }
    file.close();

    for (Iterator it = lines.begin(); it != lines.end(); ++it) {
        istringstream iss(*it);
        DLinkedList genes;
        string gene;

        while (iss >> gene) {
            genes.insert(gene);
        }

        if (genes.size() > 0) {
            Node* current = genes.tail;
             Node* selectedGene = genes.head;
            while (current != nullptr) {
                if (current->data < selectedGene->data) {
                    selectedGene = current;
                }
                current = current->prev;
            }
            cout << selectedGene->data << endl;
        }
    }
}