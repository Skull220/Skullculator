#include "header.h"

//TODO: Implement a history function that stores user input and can spit it back out if
//the user requests
//main function, asks for and recieves input
int main(){
    double hist = 0;
    while(true){
        string userimp;
        cout << "Please enter an equation: " << "\n";
        cin >> userimp;
        //TODO: Write code that clears whitespaces from userimp


        //find an operator
        for (int i = 0; i < userimp.length(); i++){
            if(userimp [i] == '+', '-', '*', '/', '^', '=' ){
                int a;
                int b;
                //Try catch is an ugly fuckin function
                try{
                    a = stoi(userimp.substr(0, i));
                } catch (std::invalid_argument const &e){
                    a = hist;
                } catch (std::out_of_range const &e){
                    cout << "Error! Skull is out of his range! " << "\n";
                }
                try{
                    b = stoi(userimp.substr(i+1, userimp.length())); 
                } catch (std::invalid_argument const &e){
                    b = hist;
                } catch (std::out_of_range const &e){
                    cout << "Error! Skull is out of his range! " << "\n";
                }
                //TODO: Fix the comparison of negative values, which currently attempts to subtract
                //AND compare
                switch(userimp[i]){
                    case '+':
                        hist = addition(a,b);
                        cout << hist << ".\n";
                        break;
                    case '-':
                        hist = subtraction(a,b);
                        cout << hist << ".\n";
                        break;
                    case '*':
                        hist = multiplication(a,b);
                        cout << hist << ".\n";
                        break;
                    case '/':
                        hist = division(a, b);
                        cout << hist << ".\n";
                        break;
                    case '^':
                        hist = exponent(a, b);
                        cout << hist << ".\n";
                        break;
                    case '=':
                        comparator(a, b);
                        break;
                    case '&':
                        return 0;
                }
            }
        }

    }
}
