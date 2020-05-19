#include <iostream>             
#include <cmath>
#include <string>
#include "header.h"

using namespace std;

void addition(int a, int b){
    cout << (a + b) << ".\n";
}

void subtraction(int a, int b){
    cout << (a - b) << ".\n";
}

void multiplication(int a, int b){
    cout << (a * b) << ".\n";
}

void division(double a, double b){
    cout << (a / b) << ".\n";
}

void comparator(int a, int b){
    if(a == b){
        cout << "True!" << ".\n";
    } else {
        cout << "False." << ".\n";
    }

}