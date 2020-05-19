#include "header.h"

/*TODO: 
-Implement a history function that stores user input and can spit it back out if the user requests
-Make it so the user can input a negative value as part of an equation and have it parse properly
-Introduce square roots. Might have to check for specific strings somehow.
*/

//clears whitespace from user input so spaces won't break the machine
string stripper(string unstripped){
    string stripped;
    int head = unstripped.length();
    for (int i = 0; i < head; i++){
        if(unstripped[i] != ' ') stripped += unstripped[i];
    }
    return stripped;    
} 

/*Reads for a SPECIFIC operator and runs the appropriate function. 
The functions have return types so the result
can be used as a temporary history value. */
double function_chooser(double previous_value, char input, int first_number, int second_number){
    switch(input){
        case '+':
            previous_value = addition(first_number,second_number);
            cout << previous_value << ".\n";
            break;
        case '-':
            previous_value = subtraction(first_number,second_number);
            cout << previous_value << ".\n";
            break;
        case '*':
            previous_value = multiplication(first_number,second_number);
            cout << previous_value << ".\n";
            break;
        case '/':
            previous_value = division(first_number, second_number);
            cout << previous_value << ".\n";
            break;
        case '^':
            previous_value = exponent(first_number, second_number);
            cout << previous_value << ".\n";
            break;
        case '=':
            comparator(first_number, second_number);
            break;
        /* This is just so I can exit the loop because the terminal
        doesn't have a big red x button. I'll comment this out for release.*/
        case '&':
            return -0;
    }
    return previous_value;
}

//This searches the entire input for some kind of operator
double operator_finder(string input, double previous_value){
    for (int i = 0; i < input.length(); i++){
        //if first_numbervalid operator is found, the calculator gets to work
        if(input[i] == '+', '-', '*', '/', '^', '=' ){
            int first_number;
            int second_number;
            /*Tries to assign the left and right sides of the operator as integers.
            If it can't, it will assign the value in history (default 0). I think there might be
            SOME way to have these both in the same try catch, but there also might not be.
            side note: Try catch is an ugly fuckin function */
            try{
                first_number = stoi(input.substr(0, i));
            } catch (std::invalid_argument const &e){
                first_number = previous_value;
            } catch (std::out_of_range const &e){
                cout << "Error! Skull is out of his range! " << "\n";
            }
            try{
                second_number = stoi(input.substr(i+1, input.length())); 
            } catch (std::invalid_argument const &e){
                second_number = previous_value;
            } catch (std::out_of_range const &e){
                cout << "Error! Skull is out of his range! " << "\n";
            }
            previous_value = function_chooser(previous_value, input[i], first_number, second_number);
            //This makes it so & can exit the program properly
            //this is an absolute hack but if it works, it works
            if (-0 == previous_value){
                return -0;    
            }
        }
    }
    return previous_value;
}

//main function, asks for and recieves input.
int main(){
    double previous_value = 0;
    string input_unstripped;
    while(true){
        cout << "Please enter an equation: " << "\n";
        getline(cin, input_unstripped);
        string input_stripped = stripper(input_unstripped);
        previous_value = operator_finder(input_stripped, previous_value);
        //This makes it so & can exit the program properly
        if (-0 == previous_value){
            return -0;
        }
    }
}