#include "header.h"

void history::clear_history(){
        for (int i = 0; i < 20; i++) history_list[i] = "";
        int history_slot = 0;
    }
void history::commit_to_history(string input){
    if(history_slot > 20) clear_history();    
    history_list[history_slot] = input;
    history_slot++; 
}
double history::display_history(){
    cout << "User history (Last 20 inputs):" << "\n";
    for(int i = 0; i < 20; i++) if(!(history_list[i] == "")) cout << history_list[i] << ".\n";
    return 0;
}

void history::help_menu(){
    cout << "Available operations:" << "\n";
    cout << "+    || Add two values                      || type as: x + y" << "\n";
    cout << "-    || Subtract two values                 || type as: x - y" << "\n";
    cout << "*    || Multiply two values                 || type as: x * y" << "\n";
    cout << "/    || Divide two values                   || type as: x / y" << "\n";
    cout << "=    || Compare two values                  || type as: x = y" << "\n";
    cout << "^    || Put a value to the power of another || type as: x ^ n" << "\n";
    cout << "root || Take a value to the root of another || type as: n root x" << "\n";
    cout << "hist || Display up to 20 lines of history   || type as: hist" << "\n";
    cout << "help || Display this menu                   || type as: help" << "\n";
    cout << "&    || Force quit the program              || type as: &" << "\n";
    cout << "NOTE: Typing any equation without an x, y, or n value will substitute the missing value(s)"<< "\n";
    cout << "with the result of the previous operation (default 0)." << "\n";

}

