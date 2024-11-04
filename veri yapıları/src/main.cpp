#include "../include/dLinkedList.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    DLinkedList list;
    int choice;
    do{
        cout << "1.Çaprazlama" << endl;
        cout << "2.Mutasyon" << endl;
        cout << "3.Otomatik İşlemler" << endl;
        cout << "4.Ekrana Yaz" << endl;
        cout << "5.Çıkış" << endl;
        cin >> choice;

        if(choice == 1){
            cout << "Çaprazlama işlemi için iki adet satır numarası seçiniz" << endl;
        }
        else if(choice == 2){

        }
        else if(choice == 3){

        }
        else if(choice == 4){
            ifstream file("src/Dna.txt");

            if(!file) {
                cerr << "Dosya açılamadı" << endl;
                return 1;
            }
            string line;
            while(getline(file, line)) {
                list.insert(line);
            }
            file.close();
            list.display();
            
        }
        else if(choice == 5){
            return 0;
        }
        else{
            cout << "Yanlış Seçim" << endl;
        }

    }while(1);



    
    return 0;
}