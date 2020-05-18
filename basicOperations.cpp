#include <iostream>             
#include <cmath>
#include <string>
#include "header.h"

using namespace std;
int a, b;
void addition(string userimp, int i){
    try{
        int a = stoi(userimp.substr(0, i));
        int b = stoi(userimp.substr(i, userimp.length()));   
    } catch (std::invalid_argument const &e){
        cout << "Error! Skull is a moron!";
    } catch (std::out_of_range const &e){
        cout << "Error! Skull is a moron!";
    }
    cout << a + b << ".\n";
}
void subtraction(string userimp, int i){
    try{
        int a = stoi(userimp.substr(0, i));
        int b = stoi(userimp.substr(i, userimp.length()));   
    } catch (std::invalid_argument const &e){
        cout << "Error! Skull is a moron!";
    } catch (std::out_of_range const &e){
        cout << "Error! Skull is a moron!";
    }
    cout << a - b << ".\n";
}

void multiplication(string userimp, int i){
    try{
        int a = stoi(userimp.substr(0, i));
        int b = stoi(userimp.substr(i, userimp.length()));   
    } catch (std::invalid_argument const &e){
        cout << "Error! Skull is a moron!";
    } catch (std::out_of_range const &e){
        cout << "Error! Skull is a moron!";
    }
    cout << a * b << ".\n";
}

void division(string userimp, int i){
    try{
        int a = stoi(userimp.substr(0, i));
        int b = stoi(userimp.substr(i, userimp.length()));   
    } catch (std::invalid_argument const &e){
        cout << "Error! Skull is a moron!";
    } catch (std::out_of_range const &e){
        cout << "Error! Skull is a moron!";
    }
    cout << a / b << ".\n";
}
