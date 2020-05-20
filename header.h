#include <iostream>             
#include <cmath>
#include <string>
#include <climits>

using namespace std;

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

int addition(int first_term, int second_term);
int subtraction(int first_term, int second_term);
int multiplication(int first_factor, int second_factor);
double division(double dividend, double divisor);
void comparator(double left_side, double right_side);
double exponent(int base, int exponent);
double take_root(double index, double radicand);





