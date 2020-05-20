#include "header.h"

history hist = history();

/*TODO: 
-Make it so the user can input a negative value as part of an equation and have it parse properly
Some say this is the 13th labor of hercules 
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

/*See below. The only difference is that, true to the name, this one handles complex inputs. 
Those require more than one letter, so it first verifies that the input is valid.*/
double complex_operation_switch(int previous_value, string input, int i){

    switch(input[i]){
        case 'h':
            //There's got to be a better way...
            if(input[i+1] == 'i' && input[i+2] == 's' && input[i+3] == 't') previous_value = hist.display_history();
            else if(input[i+1] == 'e' && input[i+2] == 'l' && input[i+3] == 'p'){
                hist.help_menu();
            }
            break;
        case 'r':
            if(input[i+1] == 'o' && input[i+2] == 'o' && input[i+3] == 't'){
                int radicand;
                int index;
                /*A lot of this is copy and pasted but there are also just enough differences
                between this one and the one below that I think it's justified. I can probably make it
                a function if I try hard enough.*/                
                try{
                    index = stoi(input.substr(0, i));
                } catch (std::invalid_argument const &e){
                    //index defaults to 2 because it's a root problem
                    index = 2;
                } catch (std::out_of_range const &e){
                    cout << "Error! Skull is out of his range! " << "\n";
                }
                try{
                    radicand = stoi(input.substr(i+4, input.length())); 
                } catch (std::invalid_argument const &e){
                    radicand = previous_value;
                } catch (std::out_of_range const &e){
                    cout << "Error! Skull is out of his range! " << "\n";
                }
                previous_value = take_root(index, radicand);
                cout << previous_value << ".\n";
            } 
            break;
    }
    return previous_value;
}

/*Reads for a SPECIFIC operator and runs the appropriate function. 
The functions have return types so the result
can be used as a temporary history value. */
double standard_operation_switch(double previous_value, char input, int first_number, int second_number){
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
    }
    return previous_value;
}

//This searches the entire input for some kind of operator
double operator_finder(string input, double previous_value){
    for (int i = 0; i < input.length(); i++){
        //if a valid operator is found, the calculator commits the equation to history and gets to work
        //actually, this is just as ugly as the if statement, but at least I don't feel like yanderedev
        switch(input[i]){
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '=':
                hist.commit_to_history(input);
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
                previous_value = standard_operation_switch(previous_value, input[i], first_number, second_number);
                /*side note: I honest to god had a near panic attack 
                because I thought the previous value function completely stopped working. 
                Lo and behold I just forgot to put a fucking break*/
                break;
            case 'h':
            case 'r':
                previous_value = complex_operation_switch(previous_value, input, i);
                break;
            /* This is just so I can exit the loop,
            because the terminal doesn't have a big red x button. I'll comment this 
            out for release. This is an absolute hack but if it works, it works. */
            case '&':
                return INT_MAX;    
                break;
        }
    }
    return previous_value;
}

//main function, asks for and recieves input.
int main(){ 
    hist.clear_history();
    double previous_value = 0;
    string input_unstripped;
    cout << "Skull Calculator V1.0" << "\n";
    while(true){
        cout << "." << "\n" << "." << "\n";
        cout << "Please enter an equation or type 'help' to view available list: " << "\n";
        getline(cin, input_unstripped);
        string input_stripped = stripper(input_unstripped);
        previous_value = operator_finder(input_stripped, previous_value);
        //This makes it so & can exit the program properly
        if (previous_value == INT_MAX){
            return 0;
        }
    }
}