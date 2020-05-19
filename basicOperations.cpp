#include <iostream>             
#include <cmath>
#include <string>
#include "header.h"

using namespace std;

//TODO: Have all these operations return a value. This way, I can give the calculator multi step equations

int addition(int a, int b){
    cout << (a + b) << ".\n";
    return (a + b);
}

int subtraction(int a, int b){
    cout << (a - b) << ".\n";
    return (a - b);
}

int multiplication(int a, int b){
    cout << (a * b) << ".\n";
    return (a * b);
}

double division(double a, double b){
    cout << (a / b) << ".\n";
    return (a / b);
}

void comparator(int a, int b){
    if(a == b){
        cout << "True!" << "\n";
    } else {
        cout << "False." << "\n";
    }

}