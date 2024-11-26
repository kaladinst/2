#include "../include/dLinkedList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

DLinkedList::DLinkedList() {
    head = nullptr;
    listSize = 0;
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
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    listSize++;
}

int DLinkedList::size() const {
    return listSize;
}

Iterator DLinkedList::begin() const {
    return Iterator(head);
}

Iterator DLinkedList::end() const {
    return Iterator(nullptr);
}

void DLinkedList::readChromosomesFromFile(DLinkedList &lines) {
    ifstream file("src/Dna.txt");
    if (!file) {
        cerr << "Dosya açılamadı" << endl;
        return;
    }
    string line;
    while(getline(file,line)){
        lines.insert(line);
    }
    file.close();
}

DLinkedList DLinkedList::parseGenes(const string &line) {
    DLinkedList genes;
    istringstream iss(line);
    string gene;
    while (iss >> gene) {
        genes.insert(gene);
    }
    return genes;
}

void DLinkedList::Mutation(DLinkedList &lines) {
    cout << "Mutasyon işlemi için bir satır numarası seçiniz" << endl;
    int row;
    cin >> row;

    Iterator it = lines.begin();
    for (int i = 0; i < row && it != lines.end(); ++i) {
        ++it;
    }

    if (it == lines.end()) {
        cerr << "Geçersiz satır numarası" << endl;
        return;
    }

    string line = *it;
    cout << "Seçilen satır: " << line << endl;
    cout << "Mutasyon işlemi yapılacak genin numarası: " << endl;
    int gene;
    cin >> gene;

    DLinkedList genes = parseGenes(line);

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

void DLinkedList::Crossover(DLinkedList &lines) {
    cout << "Çaprazlama işlemi için ilk satır numarası seçiniz" << endl;
    int row1;
    cin >> row1;

    Iterator it1 = lines.begin();
    for (int i = 0; i < row1 && it1 != lines.end(); ++i) {
        ++it1;
    }

    if (it1 == lines.end()) {
        cerr << "Geçersiz satır numarası" << endl;
        return;
    }


    cout << "Çaprazlama işlemi için ikinci satır numarası seçiniz" << endl;
    int row2;
    cin >> row2;

    Iterator it2 = lines.begin();
    for (int i = 0; i < row2 && it2 != lines.end(); ++i) {
        ++it2;
    }

    if (it2 == lines.end()) {
        cerr << "Geçersiz satır numarası" << endl;
        return;
    }

    string line1 = *it1;
    string line2 = *it2;

    DLinkedList gen1 = parseGenes(line1);
    DLinkedList gen2 = parseGenes(line2);

    int size1 = gen1.size();
    int size2 = gen2.size();
    int half1 = size1 / 2;
    int half2 = size2 / 2;

    Iterator genIt1 = gen1.begin();
    Iterator genIt2 = gen2.begin();

    for (int i = 0; i < half1; ++i) {
        ++genIt1;
    }
    if(size1 % 2 != 0){
        ++genIt1;
    }
    for (int i = 0; i < half2; ++i) {
        ++genIt2;
    }
    if(size2 % 2 != 0){
        ++genIt2;
    }

    DLinkedList newGen1, newGen2;

    Iterator it = gen1.begin();
    for (int i = 0; i < half1; ++i) {
        newGen1.insert(*it);
        ++it;
    }

    for (Iterator it = genIt2; it != gen2.end(); ++it) {
        newGen1.insert(*it);
    }

    for (Iterator it = genIt1; it != gen1.end(); ++it) {
        newGen2.insert(*it);
    }

    it = gen2.begin();
    for (int i = 0; i < half2; ++i) {
        newGen2.insert(*it);
        ++it;
    }

    ostringstream oss1, oss2;
    for (Iterator it = newGen1.begin(); it != newGen1.end(); ++it) {
        oss1 << *it << " ";
    }
    for (Iterator it = newGen2.begin(); it != newGen2.end(); ++it) {
        oss2 << *it << " ";
    }

    string newLine1 = oss1.str();
    string newLine2 = oss2.str();
    newLine1.pop_back();
    newLine2.pop_back(); 

    lines.insert(newLine1);
    lines.insert(newLine2);
    listSize += 2;

    cout << "Çaprazlama işlemi tamamlandı" << endl;
    cout << "Yeni Kromozom 1: " << newLine1 << endl;
    cout << "Yeni Kromozom 2: " << newLine2 << endl;
}

void DLinkedList::printToScreen(DLinkedList &lines) {
    for (Iterator it = lines.begin(); it != lines.end(); ++it) {
        string chromosome = *it;
        DLinkedList genes = parseGenes(chromosome);

        if (genes.size() == 0) {
            cout << chromosome << endl;
            continue;
        }

        istringstream iss(chromosome);
        string firstGen;
        iss >> firstGen;

        Node* current = genes.head;
        while (current && current->next) {
            current = current->next; 
        }

        bool found = false;
        while (current != nullptr) {
            if (current->data < firstGen) {
                cout << current->data << endl;
                found = true;
                break;
            }
            current = current->prev;
        }

        if (!found) {
            cout << firstGen << endl;
        }
    }
}


void DLinkedList::AutoOperation(DLinkedList &lines) {
    ifstream file("src/Islemler.txt");
    if (!file) {
        cerr << "Dosya açılamadı" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        char operation;
        int param1, param2;
        iss >> operation >> param1 >> param2;

        if (operation == 'M') {
            Iterator it = lines.begin();
            for (int i = 0; i < param1 && it != lines.end(); ++i) {
                ++it;
            }

            if (it == lines.end()) {
                cerr << "Geçersiz satır numarası" << endl;
                continue;
            }

            string chromosome = *it;
            DLinkedList genes = parseGenes(chromosome);
            if (param2 < 0 || param2 >= genes.size()) {
                cerr << "Geçersiz gen numarası" << endl;
                continue;
            }

            Iterator geneIt = genes.begin();
            for (int i = 0; i < param2 && geneIt != genes.end(); ++i) {
                ++geneIt;
            }

            if (geneIt == genes.end()) {
                cerr << "Geçersiz gen numarası" << endl;
                continue;
            }

            *geneIt = "X";

            ostringstream oss;
            for (Iterator it = genes.begin(); it != genes.end(); ++it) {
                oss << *it << " ";
            }

            string newLine = oss.str();
            newLine.pop_back();
            *it = newLine;

        } else if (operation == 'C') {
            Iterator it1 = lines.begin();
            for (int i = 0; i < param1 && it1 != lines.end(); ++i) {
                ++it1;
            }

            if (it1 == lines.end()) {
                cerr << "Geçersiz satır numarası" << endl;
                continue;
            }

            Iterator it2 = lines.begin();
            for (int i = 0; i < param2 && it2 != lines.end(); ++i) {
                ++it2;
            }

            if (it2 == lines.end()) {
                cerr << "Geçersiz satır numarası" << endl;
                continue;
            }

            string line1 = *it1;
            string line2 = *it2;

            DLinkedList gen1 = parseGenes(line1);
            DLinkedList gen2 = parseGenes(line2);

            int size1 = gen1.size();
            int size2 = gen2.size();
            int half1 = size1 / 2;
            int half2 = size2 / 2;

            Iterator genIt1 = gen1.begin();
            Iterator genIt2 = gen2.begin();

            for (int i = 0; i < half1; ++i) {
                ++genIt1;
            }

            if(size1 % 2 != 0){
                ++genIt1;
            }

            for (int i = 0; i < half2; ++i) {
                ++genIt2;
            }

            if(size2 % 2 != 0){
                ++genIt2;
            }
            
            DLinkedList newGen1, newGen2;

            Iterator it = gen1.begin();
            for (int i = 0; i < half1; ++i) {
                newGen1.insert(*it);
                ++it;
            }

            for (Iterator it = genIt2; it != gen2.end(); ++it) {
                newGen1.insert(*it);
            }

            for (Iterator it = genIt1; it != gen1.end(); ++it) {
                newGen2.insert(*it);
            }

            it = gen2.begin();
            for (int i = 0; i < half2; ++i) {
                newGen2.insert(*it);
                ++it;
            }

            ostringstream oss1, oss2;
            for (Iterator it = newGen1.begin(); it != newGen1.end(); ++it) {
                oss1 << *it << " ";
            }
            for (Iterator it = newGen2.begin(); it != newGen2.end(); ++it) {
                oss2 << *it << " ";
            }

            string newLine1 = oss1.str();
            string newLine2 = oss2.str();
            newLine1.pop_back();
            newLine2.pop_back();

            lines.insert(newLine1);
            lines.insert(newLine2);
            listSize += 2;
        }
    }
    file.close();

    cout << "Otomatik işlemler tamamlandı" << endl;
} 