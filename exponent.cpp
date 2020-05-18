#include <iostream>             
#include <cmath>
#include <string>

using namespace std;
//calculates the exponent
double power(double base, int exponent){
    double result = 1;
    if (exponent == 0) return 1;
    for(int i = 0; i < exponent; i++) result *= base;
    return result;
}

//appends the proper ending to the exponent for grammar purposes
string append(int exponent){
    string append;
    switch(exponent % 100){
        case 1:
            append = "st";
            break; 
        case 2:
            append = "nd";
            break;
        case 3:
            append = "rd";
            break;
        default:
            append = "th";
    }
    return append;
}

//prints everything out
void print_pow(double base, int exponent){
    double result = power(base, exponent);
    string appendix = append(exponent);
    cout << base << " raised to the "<< exponent << appendix <<" power is " << result << ".\n";
}

//asks for information
void exponent(){
    int base, exponent;
    cout << "What's the base?: ";
    cin >> base;
    cout << "What is the exponent?: ",
    cin >> exponent;
    print_pow(base, exponent);
}