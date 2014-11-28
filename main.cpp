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
       Fraction ans;
       Operat op;
};

Expression exps [30];

typedef struct Fraction Fraction;

struct Equation{
    Fraction f1, f2;
    char operators;
};
typedef struct Equation Equation;

//created an enum type to make the menu options more readable
enum Menu_Option {OUTPUT = 0, GETEXP = 1, SORT = 2, SORT_ANSWER = 3, SORT_OPERATOR = 4, DELETE = 5, GENERATE = 6, QUIT = 7, MENU_MAX = 8};

//checks whether input is valid or not
bool inputCheck(int userInput) {
    return (0 <= userInput && userInput <= MENU_MAX) ? 1 : 0; //It's a compact if/else, dude. Not magic at all.
}

int gcd(int x, int y) {
    return (y != 0) ? gcd(y, x % y) : x;
}

void addEm (Expression* exp){
    //Setting the denominator
    exp->ans.denom = exp->num1.denom * exp->num2.denom;
    //Figuring out the numerator
    if (exp->num1.sign == POS && exp->num1.sign == POS){
        exp->ans.num = (exp->num1.num * exp->num2.denom) + (exp->num2.num * exp->num1.denom);
    }
    else if (exp->num1.sign == POS && exp->num1.sign == NEG){
        exp->ans.num = (exp->num1.num * exp->num2.denom) - (exp->num2.num * exp->num1.denom);
    }
    else if (exp->num1.sign == NEG && exp->num1.sign == POS){
        exp->ans.num = (exp->num2.num * exp->num2.denom) - (exp->num1.num * exp->num1.denom);
    }
    else if (exp->num1.sign == NEG && exp->num1.sign == NEG){
        exp->ans.num = (exp->num2.num * exp->num2.denom) + (exp->num1.num * exp->num1.denom);
        exp->ans.sign = NEG;
    }

    //Determining the sign
    if (exp->ans.num < 0){
        exp->ans.num = abs(exp->ans.num);
        exp->ans.sign = NEG;
    }
    else if (exp->ans.denom < 0){
        exp->ans.denom = abs(exp->ans.denom);
        exp->ans.sign = NEG;
    }
    else{
        exp->ans.sign = POS;
    }
}

void multEm (Expression* exp){
    //Determining the value of the answer
    exp->ans.num = exp->num1.num * exp->num2.num;
    exp->ans.denom = exp->num1.denom * exp->num2.denom;

    //Setting the sign of the answer
    if (exp->num1.sign == NEG && exp->num2.sign == POS){
        exp->ans.sign = NEG;
    }
    else if (exp->num1.sign == POS && exp->num2.sign == NEG){
        exp->ans.sign = NEG;
    }
    else {
        exp->ans.sign = POS;
    }

    //Determining the sign
    if (exp->ans.num < 0){
        exp->ans.num = abs(exp->ans.num);
        exp->ans.sign = NEG;
    }
    else if (exp->ans.denom < 0){
        exp->ans.denom = abs(exp->ans.denom);
        exp->ans.sign = NEG;
    }
    else{
        exp->ans.sign = POS;
    }
}

void divEm (Expression* exp){
    //Determining the value of the answer
    exp->ans.num = exp->num1.num * exp->num2.denom;
    exp->ans.denom = exp->num1.denom * exp->num2.num;

    //Setting the sign of the answer
    if (exp->num1.sign == NEG && exp->num2.sign == POS){
        exp->ans.sign = NEG;
    }
    else if (exp->num1.sign == POS && exp->num2.sign == NEG){
        exp->ans.sign = NEG;
    }
    else {
        exp->ans.sign = POS;
    }

    //Determining the sign
    if (exp->ans.num < 0){
        exp->ans.num = abs(exp->ans.num);
        exp->ans.sign = NEG;
    }
    else if (exp->ans.denom < 0){
        exp->ans.denom = abs(exp->ans.denom);
        exp->ans.sign = NEG;
    }
    else{
        exp->ans.sign = POS;
    }
}

void mathStuff(Expression* exp){
    switch(exp->op) {
        case ADD:
            // addEm
        break;

        case SUB:
            // subEm
        break;

        case MULT:
            // multEm
        break;

        case DIV:
            // divEm
        break;
    }
}

void handling (Menu_Option a){
    switch(a) {
        case OUTPUT:
            // Code
        break;

        case GETEXP:
            // Code
        break;

        case SORT:
            // Code
        break;

        case SORT_ANSWER:
            // Code
        break;

        case SORT_OPERATOR:
            // Code
        break;

        case DELETE:
            // Code
        break;

        case GENERATE:
            // Code
        break;

        case QUIT:
            // Code
        break;

        default:
            // Code
        break;
    }
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
    Menu_Option menuchoice = menu();
    handling (menuchoice);
}
