#include "../include/dLinkedList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    DLinkedList list;
    int choice;
    do {
        cout << "1.Çaprazlama" << endl;
        cout << "2.Mutasyon" << endl;
        cout << "3.Otomatik İşlemler" << endl;
        cout << "4.Ekrana Yaz" << endl;
        cout << "5.Çıkış" << endl;
        cin >> choice;

        if (choice == 1) {
            list.Crossover();
        } else if (choice == 2) {
            list.Mutation();
        } else if (choice == 3) {

        } else if (choice == 4) {
            list.printToScreen();
        } else if (choice == 5) {
            return 0;
        } else {
            cout << "Yanlış Seçim" << endl;
        }
    } while (1);

    return 0;
}