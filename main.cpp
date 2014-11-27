/* INTRUCTIONS
Add random expression
Get expression from user
Sort by answer
Output expressions with answers
Delete expression
Sort by operator then by answer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum Operat {ADD, SUB, MULT, DIV};
enum Sign {POS, NEG};

struct Fraction {
       Sign sign;
       int num;
       int denom;
};

struct Expression {
       Fraction num1;
       Fraction num2;
       Operat op;
};

Expression exps [30];

/*
int gcd(int x, int y) {
    return (y != 0) ? gcd(y, x % y) : x;
}
*/

//created an enum type to make the menu options more readable
enum Menu_Option {OUTPUT = 0, GETEXP = 1, SORT = 2, SORT_ANSWER = 3, SORT_OPERATOR = 4, DELETE = 5, GENERATE = 6, QUIT = 7, MENU_MAX = QUIT};

//checks whether input is valid or not
bool inputCheck(int userInput) {
    return (0 <= userInput && userInput <= MENU_MAX) ? 1 : 0; //It's a compact if/else, dude. Not magic at all.
}

Menu_Option menu() {
    char* temp;
    int userInput = 0;
    do {
        printf ("Input the number of your choice\n");
        gets (temp);
        userInput = atoi (temp);
    } while (!inputCheck (userInput));
    return (Menu_Option) userInput;
}

int main() {
    menu();
}
