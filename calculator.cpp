#include "header.h"

//TODO: Implement a history function that stores user input and can spit it back out if the user requests
string stripper(string unstripped){
    string stripped;
    int head = unstripped.length();
    for (int i = 0; i < head; i++){
        if(unstripped[i] != ' ') stripped += unstripped[i];
    }
    return stripped;    
} 

//main function, asks for and recieves input.
//Is it bad practice to have so much code in the main? Fuck it, probably.
int main(){
    double previous_value = 0;
    string input_unstripped = "";
    string input_stripped = "";
    cout << "Please enter an equation: " << "\n";
    getline (cin, input_unstripped);
    input_stripped = stripper(input_unstripped);
    //This searches the entire input for some kind of operator
    /*TODO: Create some kind of hierarchy that checks for everything else before checking for negatives.
    This way I can parse negative operations */
    for (int i = 0; i < input_stripped.length(); i++){
        //if first_numbervalid operator is found, the calculator gets to work
        if(input_stripped[i] == '+', '-', '*', '/', '^', '=' ){
            int first_number;
            int second_number;
            /*Tries to assign the left and right sides of the operator as integers.
            If it can't, it will assign the value in history (default 0). I think there might be
            SOME way to have these both in the same try catch, but there also might not be.
            side note: Try catch is an ugly fuckin function */
            try{
                first_number = stoi(input_stripped.substr(0, i));
            } catch (std::invalid_argument const &e){
                first_number = previous_value;
            } catch (std::out_of_range const &e){
                cout << "Error! Skull is out of his range! " << "\n";
            }
            try{
                second_number = stoi(input_stripped.substr(i+1, input_stripped.length())); 
            } catch (std::invalid_argument const &e){
                second_number = previous_value;
            } catch (std::out_of_range const &e){
                cout << "Error! Skull is out of his range! " << "\n";
            }
            /*Reads for a SPECIFIC operator and runs the 
            appropriate function. The functions have return types so the result
            can be used as a temporary history value. */
            //TODO: Fix the comparison of negative values
            switch(input_stripped[i]){
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
                    return 0;
            }
        }
    }
    main();
}