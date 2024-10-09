#include <iostream>
#include "../inc/header.h"

using namespace std;



int main() {
    cout << "Choose an option: " << endl;
    cout << "1. Calculate factorial" << endl;
    cout << "2. Swap Values" << endl; 
    cout << "3. Create Student" << endl;
    int option;
    cin >> option;
    if(option== 1)
    calcFactorial();
    if(option ==2)
    swapValues();
    if(option == 3)
    createStudent();
    return 0;
}