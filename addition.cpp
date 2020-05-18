#include <iostream>             
#include <cmath>
#include <string>
#include "header.h"

using namespace std;

double add(int a, int b){
    return a + b;
}

void print_add(int a, int b){
    cout << a << " plus " << b << " equals " << add(a, b) << ".\n";
}

void addition(){
    int a, b;
    cout << "What's the first term?: ";
    cin >> a;
    cout << "What is the second term?: ",
    cin >> b;
    print_add(a, b);
}

