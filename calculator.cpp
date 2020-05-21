#include "header.h"

//constructs history class 'hist'
history hist = history();



//Assigns values to be used by the calculator. See below.
double assigner(string input, int index, int type, int previous_value){
    double value;
    if (type == 0 || type == 2){
        /*Try catch is still an ugly function. 
        Half the reason I wrote this method is so I wouldn't need to look at it unless I needed to.*/
        try{
            value = stoi(input.substr(0, index));
        } catch (std::invalid_argument const &e){
            if (type == 2) value = 2;
            else value = previous_value; 
        }
    } else {
        try{
            if (type == 1) value = stoi(input.substr(index+1, input.length())); 
            else value = stoi(input.substr(index+4, input.length()));
        } catch (std::invalid_argument const &e){
            value = previous_value;
        }  
    }
    return value;
}

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
    switch(tolower(input[i])){
        case 'h':
            //There's got to be a better way...
            if(tolower(input[i+1]) == 'i' && tolower(input[i+2]) == 's' && tolower(input[i+3]) == 't') previous_value = hist.display_history();
            
            else if(tolower(input[i+1]) == 'e' && tolower(input[i+2]) == 'l' && tolower(input[i+3]) == 'p'){
                hist.help_menu();
            }
            break;
        case 'r':
            
            if(tolower(input[i+1]) == 'o' && tolower(input[i+2]) == 'o' && tolower(input[i+3]) == 't'){
                hist.commit_to_history(input);
                int radicand;
                int index;      
                index = assigner(input, i, 2, previous_value);
                radicand = assigner(input, i, 3, previous_value);
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
        //This is just as ugly as the equivalent if statement, but at least I don't feel like yanderedev
        switch(tolower(input[i])){
            /*Everything below is fucking revolting.
            It all works, but it should be changed as soon as possible*/
            case '-':                
            case '+':
            case '*':
            case '/':
            case '^':
            case '=':
                /*I have to assign these on different lines than where I initialize them.
                the compiler is a small child and will scream and cry
                and shit its pants unless I do so*/
                int index_of_operator;
                index_of_operator = i;
                //If negative is caught, this verifies there are no other operators. I think. 
                for (int j = 0; j < input.length(); j++){
                    if(input[j] == '+' || input[j] == '*' || input[j] == '/' 
                    || input[j] == '^' || input[j] == '=') index_of_operator = j; 
                }
                hist.commit_to_history(input);
                //Ditto, see two comments above
                int first_number;
                int second_number;
                first_number = assigner(input, index_of_operator, 0, previous_value);
                second_number = assigner(input, index_of_operator, 1, previous_value);
                previous_value = standard_operation_switch(previous_value, input[index_of_operator], first_number, second_number);
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
    cout << "Skullculator V1.0" << "\n";
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