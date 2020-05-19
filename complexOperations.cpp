#include <iostream>             
#include <cmath>
#include <string>
#include "header.h"

using namespace std;

//calculates the exponent
double power(double base, int exponent){
    double result = 1;
    if (exponent == 0) return 1;
    for(int i = 0; i < exponent; i++) result *= base;
    return result;
}

//asks for information
int exponent(int base, int exponent){
    cout << power(base, exponent) << ".\n";
    return(power(base, exponent));
}