#include "header.h"

/* TODO: Since I wrote these out myself, I need to find a way to handle negatives. 
Decimals I'm just gonna have the computer handle since I have no idea how I could write that myself. */

//wrote these out manually as well
int addition(int first_term, int second_term){
    int result = first_term;
    for (int i = 0; i < second_term; i++) result++;
    return result;
}

int subtraction(int first_term, int second_term){
    int result = first_term;
    for (int i = 0; i < second_term; i++) result--;
    return result;
}

int multiplication(int first_factor, int second_factor){
    int result = 0;
    for (int i = 0; i < second_factor; i++) result = addition(result, first_factor);
    return result;
}

//this is a pain in the ass and is making me regret my decision above
double division(double dividend, double divisor){
    double result = 0;
    while(dividend > divisor-1){
        dividend -= divisor;
        result++;
    } 
    //I can't currently think of a way to do this without the division operator.
    if ((dividend - divisor) != 0) result = result + (dividend/divisor);
    return result;
}

//easy as shit and will work for doubles
void comparator(double left_side, double right_side){
    if(left_side == right_side) cout << "True!" << "\n";
    else cout << "False." << "\n";
}