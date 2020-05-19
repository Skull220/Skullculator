#include "header.h"

void findnumbers(string userimp, int i, int j){
    int a;
    int b;
    try{
        a = stoi(userimp.substr(0, i));
        //cout << a << " is what a is.\n";
        b = stoi(userimp.substr(i+1, userimp.length())); 
        //cout << b << " is what b is. \n";  
    } catch (std::invalid_argument const &e){
        cout << "Error! Skull is an invalid! " << "\n";
    } catch (std::out_of_range const &e){
        cout << "Error! Skull is out of his range! " << "\n";
    }
    //cout << j << " is the j value.\n";
    switch (j){
        case 1:
            addition(a,b);
            break;
        case 2:
            subtraction(a,b);
            break;
        case 3:
            multiplication(a,b);
            break;
        case 4:
            division(a, b);
            break;
        case 5:
            //write exponent code here
            break;
        case 6:
            comparator(a, b);
    }

}

//main function, asks for and recieves input
int main(){
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
                    findnumbers(userimp, i, 1);
                    break;
                case '-':
                    findnumbers(userimp, i, 2);
                    break;
                case '*':
                    findnumbers(userimp, i, 3);
                    break;
                case '/':
                    findnumbers(userimp, i, 4);
                    break;
                case '^':
                    exponent();
                    break;
                case '=':
                    findnumbers(userimp, i, 6);
                    break;
                case '&':
                    return 0;
            }
        }

    }
}
