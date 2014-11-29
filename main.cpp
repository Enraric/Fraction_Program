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


//Custom types/////////////////////////////////////////////////////
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

//created an enum type to make the menu options more readable
enum Menu_Option {OUTPUT = 0, GETEXP = 1, SORT = 2, SORT_ANSWER = 3, SORT_OPERATOR = 4, DELETE = 5, GENERATE = 6, QUIT = 7, MENU_MAX = 8};

//checks whether input is valid or not
bool inputCheck(int userInput) {
    return (0 <= userInput && userInput <= MENU_MAX) ? 1 : 0; //It's a compact if/else, dude. Not magic at all.
}

int gcd(int x, int y) {
    return (y != 0) ? gcd(y, x % y) : x;
}

//parsing

int validInt (char string){
if (string >= 48 && string <= 57)
    return 1;
else
    return 0;
}

int validOperator (char string){
    return ((string) == '+' || (string) == '-' || (string) == '/' || (string) == '*' );
}

int signSwap(){

}

int parse (char string[80]/*alternatively, keep track of the array size*/, int expNum/*which expression this is in the array of expressions*/){
    int count, SScount, partition = 0;
    char temp [80];
    //attempting to handle format of ___(-36456/-456456)___operator___(-76574/-457347)___
    //walks through array, looking for a different sentinels
    for (int i = 0; string[i] != 0; i++)
        switch (partition){
        case 0:
            if (string[i] == '(')
                partition ++;
        case 1:
            //could replace these with function call
            if (string[i] == '-')
                exps[expNum].num1.sign == NEG;//have to change it to switch signs instead
            partition ++;
        case 2:
            if (validInt (string [i])){
                temp[SScount] = string[i];
                SScount ++;
            }
            else if (string[i] == '/'){
                exps[expNum].num1.num = atoi (temp);
                temp[SScount] = 0;
                partition ++;
            }
        case 3:
//could replace these with function call
            if (string[i] == '-')
                exps[expNum].num1.sign == NEG;//have to change it to switch signs instead
            partition ++;
        case 4:
            if (validInt (string[i])){
                temp[SScount] = string[i];
                SScount ++;
            }
            else if (string[i] == ')'){
                exps[expNum].num1.denom = atoi (temp);
                SScount = 0;
                partition ++;
            }
        case 5:
            if (string [i] == '+' || string [i] == '-' || string [i] == '/' || string [i] == '*')
                //exps[expNum].op = string[i];  NEEDS FIXING
                partition ++;
        case 6:
            if (string [i] == '(')
                partition ++;
        case 7:
//could replace these with function call
            if (string[i] == '-')
                exps[expNum].num2.sign == NEG;//have to change it to switch signs instead
                partition ++;
        case 8:
            if (validInt (string[i])){
                temp[SScount] = string[i];
                SScount ++;
            }
            else if (string[i] == '/'){
                exps[expNum].num2.num = atoi (temp);
                SScount = 0;
                partition ++;
            }
        case 9:
//could replace these with function call
            if (string[i] == '-')
                exps[expNum].num2.sign == NEG;//have to change it to switch signs instead
                partition ++;
        case 10:
            if (validInt (string[i])){
                temp[SScount] = string[i];
                SScount ++;
            }
            else if (string[i] == ')'){
                exps[expNum].num2.denom = atoi (temp);
                SScount = 0;
                partition ++;
            }
        }//end switch
}

//Determining the sign/////////////////////////////////////////////
void signFinder (Expression* exp){
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


//Calculates value of expression when adding//////////////////////////////////////////////////////
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

    signFinder(exp);
}


//Calculates value of expression when subtracting//////////////////////////////////////////////////////
void subEm (Expression* exp){
    //Setting the denominator
    exp->ans.denom = exp->num1.denom * exp->num2.denom;
    //Figuring out the numerator
    if (exp->num1.sign == POS && exp->num1.sign == POS){
        exp->ans.num = (exp->num1.num * exp->num2.denom) - (exp->num2.num * exp->num1.denom);
    }
    else if (exp->num1.sign == POS && exp->num1.sign == NEG){
        exp->ans.num = (exp->num1.num * exp->num2.denom) + (exp->num2.num * exp->num1.denom);
    }
    else if (exp->num1.sign == NEG && exp->num1.sign == POS){
        exp->ans.num = (exp->num2.num * exp->num2.denom) + (exp->num1.num * exp->num1.denom);
    }
    else if (exp->num1.sign == NEG && exp->num1.sign == NEG){
        exp->ans.num = (exp->num2.num * exp->num2.denom) - (exp->num1.num * exp->num1.denom);
        exp->ans.sign = NEG;
    }

    signFinder(exp);
}


//Calculates value of expression when multiplying//////////////////////////////////////////////////////
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

    signFinder(exp);
}


//Calculates value of expression when dividing//////////////////////////////////////////////////////
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

    signFinder(exp);
}


//Deciding which math stuff funtion to use//////////////////////////////////////////////////////
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

//Handling the menu options//////////////////////////////////////////////////////
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

//Menu stuff//////////////////////////////////////////////////////
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


//Main//////////////////////////////////////////////////////
int main() {
    Menu_Option menuchoice = menu();
    handling (menuchoice);
}
