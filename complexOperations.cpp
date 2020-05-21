#include "header.h"

//calculates, prints, and returns the result. I could use a built in function but I want to do this myself
double exponent(int base, int exponent){
    double result = 1;
    if (exponent == 0) return result;
    for(int i = 0; i < abs(exponent); i++) result = multiplication(result, base);
    if (exponent < 0){
        return (1/result);
    }
    return result;
}

/* For now I'm just going to use a built in function.
If I ever decide one day that I am a failure of a human being and I deserve nothing but endless suffering,
I'll write this process manually. .*/

double take_root(double index, double radicand){
    if (radicand < 0){
        return -1;
    }
    double result = pow(radicand, (1/index));
    return result;
}