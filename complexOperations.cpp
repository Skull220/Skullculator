#include <iostream>             
#include <cmath>
#include <string>
#include "header.h"

using namespace std;


//TODO: Since I wrote these out myself, I need to find a way to handle negatives.

//calculates, prints, and returns the result. I could use a built in function but I want to do this myself
int exponent(int base, int exponent){
    double result = 1;
    if (exponent != 0){ 
        for(int i = 0; i < exponent; i++) result *= base;
    }
    return result;
}