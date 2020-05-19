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
                    //cout << a << " is what a is.\n";
                } catch (std::invalid_argument const &e){
                    //cout << "Error! Skull is an invalid! " << "\n";
                    a = hist;
                } catch (std::out_of_range const &e){
                    cout << "Error! Skull is out of his range! " << "\n";
                }
                try{
                    b = stoi(userimp.substr(i+1, userimp.length())); 
                    //cout << b << " is what b is. \n";  
                } catch (std::invalid_argument const &e){
                    //cout << "Error! Skull is an invalid! " << "\n";
                    b = hist;
                } catch (std::out_of_range const &e){
                    cout << "Error! Skull is out of his range! " << "\n";
                }
                switch(userimp[i]){
                    case '+':
                        hist = addition(a,b);
                        break;
                    case '-':
                        hist = subtraction(a,b);
                        break;
                    case '*':
                        hist = multiplication(a,b);
                        break;
                    case '/':
                        hist = division(a, b);
                        break;
                    case '^':
                        hist = exponent(a, b);
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
