#include "header.h"

//TODO: Implement a history function that stores user input and can spit it back out if
//the user requests

double findnumbers(string userimp, int i, int j, int hist){
    int a;
    int b;
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
    //cout << j << " is the j value.\n";
    switch (j){
        case 1:
            hist = addition(a,b);
            break;
        case 2:
            hist = subtraction(a,b);
            break;
        case 3:
            hist = multiplication(a,b);
            break;
        case 4:
            hist = division(a, b);
            break;
        case 5:
            hist = exponent(a, b);
            break;
        case 6:
            comparator(a, b);
    }
    return hist;
}

//main function, asks for and recieves input
int main(){
    double hist = 0;
    while(true){
        string userimp;
        cout << "Please enter an equation: " << "\n";
        cin >> userimp;
        //TODO: Write code that clears whitespaces from userimp


        //find an operator
        //TODO: Find a better way to do this. Make it so if it finds ANY operator, then it runs findnumbers. 
        for (int i = 0; i < userimp.length(); i++){
            switch(userimp[i]){
                case '+':
                    hist = findnumbers(userimp, i, 1, hist);
                    break;
                case '-':
                    hist = findnumbers(userimp, i, 2, hist);
                    break;
                case '*':
                    hist = findnumbers(userimp, i, 3, hist);
                    break;
                case '/':
                    hist = findnumbers(userimp, i, 4, hist);
                    break;
                case '^':
                    hist = findnumbers(userimp, i, 5, hist);
                    break;
                case '=':
                    hist = findnumbers(userimp, i, 6, hist);
                    break;
                case '&':
                    return 0;
            }
        }

    }
}
