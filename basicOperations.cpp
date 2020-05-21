#include "header.h"

//wrote these out manually as well
int addition(int first_term, int second_term){
    int result;
    int larger_value;
    /*check is one or both terms is positive. If so, assign the smallest value to first term.
    This makes it so that if one of the values is negative, that's the one that will be incrimented,
    which is how adding a positive value to a negative value works.*/
    if (first_term > -1 || second_term > -1){
        if (first_term > second_term){
            result = second_term;
            larger_value = first_term;
        } else {
            result = first_term;
            larger_value = second_term;
        }
        for (int i = 0; i < larger_value; i++) result++;
    } else {
        //if both values are negative this will cast one to positive and run the subtraction method
        if(first_term < 0 && second_term < 0){
            result = subtraction(first_term, abs(second_term));
            return result;
        }
    }
    return result;
}

//-9--3 returned -12, should have returned -6
int subtraction(int first_term, int second_term){
    //cout << "first term is: " << first_term << ". Second term is: " << second_term << ".\n";
    int result = first_term;
    if (second_term > 0) for (int i = 0; i < second_term; i++) result--;
    else result = addition(first_term, abs(second_term));
    return result;
}

int multiplication(int first_factor, int second_factor){
    int result = 0;
    // 3 * 5 =  15
    //-3 * 5 = -15
    // 3 *-5 = -15
    //-3 *-5 =  15
    for (int i = 0; i < abs(second_factor); i++) result = addition(result, abs(first_factor));
    if ((first_factor < 0 && second_factor > 0) || (first_factor > 0 && second_factor < 0)) result = -result;
    return result;
}

//this is a pain in the ass and is making me regret my decision above
double division(double dividend, double divisor){
    int signed_dividend = dividend;
    int signed_divisor = divisor;
    dividend = abs(dividend);
    divisor = abs(divisor);
    double result = 0;
    while(dividend > divisor-1){
        dividend -= divisor;
        result++;
    } 
    //I can't currently think of a way to do this without the division operator.
    if ((dividend - divisor) != 0) result = result + (dividend/divisor);
    
    if ((signed_dividend < 0 && signed_divisor > 0) || (signed_dividend > 0 && signed_divisor < 0)) result = -result;
    return result;
}

//easy as shit and will work for doubles
void comparator(double left_side, double right_side){
    if(left_side == right_side) cout << "True!" << "\n";
    else cout << "False." << "\n";
}