#include "../include/List.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    List list;
    
    Tree tree;
    ifstream file("agaclar.txt");

    string line;
    if(file.is_open()) {
        while(getline(file, line)) {
            Tree* tree = new Tree();
            for (std::size_t i = 0; i < line.size(); ++i) {
                char c = line[i];
                tree->insert(c);
            }

            list.insert(tree);
            cout << "Tree inserted: " << line << endl;

        }
        file.close();
    }

    list.showList();
    list.proceed();
    cout << list.showCurrent() << endl;

    while(true) {
        cout << "Secim: ";
        char secim;
        cin >> secim;

        if(secim == 'a'){
            list.regress();
            list.showList();
            cout << list.showCurrent() << endl;
        }
        else if(secim == 'd'){
            list.proceed();
            list.showList();
            cout << list.showCurrent() << endl;
        }
        else if(secim == 's'){
            list.remove();
            list.showList();
            cout << list.showCurrent() << endl;
        }
        else if(secim == 'w'){
            list.mirror();
            list.showList();
            cout << list.showCurrent() << endl;
        }

        else if(secim == 'q'){
            break;
        }
        else{
            cout << "Hatali secim" << endl;
        }
    }

    return 0;
}