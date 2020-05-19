#include "header.h"

//TODO: Since I wrote these out myself, I need to find a way to handle negatives. 
//Decimals I'm just gonna have the computer handle since I have no idea how I could write that myself.

//wrote these out manually as well, just to be a joker
int addition(int a, int b){
    int result = a;
    for (int i = 0; i < b; i++){
        result++;
    }

    return result;
}

int subtraction(int a, int b){
    int result = a;
    for (int i = 0; i < b; i++){
        result--;
    }

    return result;
}

int multiplication(int a, int b){
    int result = 0;
    for (int i = 0; i < b; i++){
        result = addition(result, a);
    }
    return result;
}

//this is a pain in the ass and is making me regret my decision above
double division(double a, double b){
    double result = 0;
    while(a > b-1){
        a -= b;
        result++;
    } 
    if ((a - b) != 0){
        //I can't currently think of a way to do this without the division operator.
        result = result + (a/b);
    }
    return result;
}

void comparator(int a, int b){
    if(a == b){
        cout << "True!" << "\n";
    } else {
        cout << "False." << "\n";
    }
}