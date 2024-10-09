#include "../inc/header.h"
#include <iostream>
using namespace std;

class Student {
private: 
    string name;
    int grade;
public:
    Student(string name, int grade) : name(name), grade(grade) {}
    
    string getName() {
        return name;
    }
    
    int getGrade() {
        return grade;
    }
    
    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
    }
};

void createStudent() {
    string name;
    int grade;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter grade: ";
    cin >> grade;
    Student s(name, grade);
    s.printInfo();
}

void calcFactorial() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int factorial = 1;
    for (int i = 1; i <= n; i++ ) {
        factorial *= i;   
    }
    cout << "Factorial of " << n << " is " << factorial << endl;
}

void swapValues() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int *p = &a;
    int *q = &b;
    cout << "Before swapping: " << a << " " << b << endl;
    cout << "Adresses of a and b are: " << p << " " << q << endl;
    int temp = *p;
    *p = *q;
    *q = temp;
    cout <<"After swappping: " << a << " " << b << endl;
    cout << "Adresses of a and b are: " << p << " " << q << endl;
}