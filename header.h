//includes
#include <iostream>           
#include <cmath>
#include <string>
#include <climits>

/*TODO: 
0) Bugtest and push 1.0 release. (All)
1) Fix the ugly code, especially line 108 (calculator, basicOperations)
    -See if it might be possible to merge some methods
2) Fix the history to show the result of a calculation, not just the entered equation.
3) Fix the history so that if the user opts to quick add or quick subtract, 
   it'll show the left/right value (calculator, history)   
4) Find a better way to handle history so I can 'bump up' the list and replace oldest value with newest (history)
5) Add decimal support
*/

/*Some might call this bad practice 
but fun fact I have a notarized letter from Bjarne Soupstore saying that
sucking my dick is good practice so get on your knees if you've got a problem */
using namespace std;

//history
class history{
    private:
        string history_list[20];
        int history_slot;
    public:
        void clear_history();
        void commit_to_history(string input);
        double display_history();
        void help_menu();
};

//basicOperations
int addition(int first_term, int second_term);
int subtraction(int first_term, int second_term);
int multiplication(int first_factor, int second_factor);
double division(double dividend, double divisor);
void comparator(double left_side, double right_side);

//complexOperations
double exponent(int base, int exponent);
double take_root(double index, double radicand);