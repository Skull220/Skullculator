#include "header.h"

//calculates, prints, and returns the result. I could use a built in function but I want to do this myself
double exponent(int base, int exponent){
    double result = 1;
    if (exponent != 0) for(int i = 0; i < exponent; i++) result *= base;
    return result;
}

/* If I ever decide one day that I am a failure of a human being and I deserve nothing but endless suffering,
I'll write this process manually. For now I'm just going to use a built in function.*/
double take_root(double index, double radicand){
    double result = pow(radicand, (1/index));
    return result;
}