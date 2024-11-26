#include "../include/dLinkedList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    DLinkedList list;
    DLinkedList lines;
    int choice;
    lines.readChromosomesFromFile(lines);
    do {

        cout << "1.Caprazlama" << endl;
        cout << "2.Mutasyon" << endl;
        cout << "3.Otomatik Islemler" << endl;
        cout << "4.Ekrana Yaz" << endl;
        cout << "5.Cikis" << endl;
        cin >> choice;

        if (choice == 1) {
            list.Crossover(lines);

        } else if (choice == 2) {
            list.Mutation(lines);
        } else if (choice == 3) {
            list.AutoOperation(lines);
        } else if (choice == 4) {
            list.printToScreen(lines);

        } else if (choice == 5) {
            return 0;
        } else {
            cout << "Yanlış Seçim" << endl;
        }
    } while (1);

    return 0;
}