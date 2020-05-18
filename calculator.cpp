#include "header.h"


//main function, asks for and recieves input
int main(){
    string userimp;
    cout << "Please enter an equation: " << "\n";
    cin >> userimp;

    //find an operator
    for (int i = 0; i < userimp.length(); i++){
        switch(userimp[i]){
            case '+':
                addition(userimp, i);
                break;
            case '-':
                subtraction(userimp, i);
                break;
            case '*':
                multiplication(userimp, i);
                break;
            case '/':
                division(userimp, i);
                break;
            case '^':
                exponent();
                break;
        }
    }
    system("pause");
}
