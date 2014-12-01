/* INTRUCTIONS
Add random expression --- Alex McMorine III
Get expression from user --- Harrison
Sort by answer --- Harrison
Output expressions with answers --- Swiggity Swilson
Delete expression --- Swiggityy Swilson
Sort by operator then by answer --- Alex McMorine III
*/
//Harrison: Guys, can we initialize our fractions?  It would make sign swapping a helluva lot easier (specifically make sign positive)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int rb (int min, int max) {
    return rand() % (max - min + 1) + min;
}

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
int numExp = 0;

//created an enum type to make the menu options more readable
enum Menu_Option {OUTPUT = 0, GETEXP = 1, SORT = 2, SORT_ANSWER = 3, SORT_OPERATOR = 4, DELETE = 5, GENERATE = 6, QUIT = 7, MENU_MAX = 8};

//checks whether input is valid or not
bool inputCheck(int userInput) {
    return (0 <= userInput && userInput <= MENU_MAX) ? 1 : 0; //It's a compact if/else, dude. Not magic at all.
}

int gcd(int x, int y) {
    return (y != 0) ? gcd(y, x % y) : x;
}


//-----------------------------------------------RAND STUFF------------------------------------------------
//-----------------------------------------------RAND STUFF------------------------------------------------

void randExps (){
    int numExps;

    do{
        printf ("\nEnter the number of expressions you would like to enter:");
        scanf ("%i", &numExps);
        if (numExps > 30 || numExps < 0){
            printf ("Invalid number.\n");
        }
    }while (numExps > 30 || numExps < 0);

    numExp == numExps;

    for (int i = 0; i < numExps; i++){
        exps[i].num1.num == rb (0,99);
        exps[i].num1.denom == rb (0,99);
        exps[i].num1.sign == rb (0,1);
        exps[i].num2.num == rb (0,99);
        exps[i].num2.denom == rb (0,99);
        exps[i].num2.sign == rb (0,2);
        exps[i].op == rb (0,3);
    }

}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

/*
//______________________________________________________________BEGIN PARSE SECTION___________________________________________________________

int validInt (char string){
if (string >= 48 && string <= 57)
    return 1;
else
    return 0;
}

int validOperator (char string){
    return ((string) == '+' || (string) == '-' || (string) == '/' || (string) == '*' );
}

Sign signSwap(Sign sign){//The naming is strong with this one
    if (sign == NEG)
       sign = POS;
    else if (sign == POS)
         sign = NEG;
    return sign;
}

int parse (char string[80], int expNum){
    int count, SScount, partition = 0;
    char temp [80];
    //attempting to handle format of ( - # ) OP ( - # ), with spaces between anything
    //walks through array, looking for a different sentinels
    for (int i = 0; string[i] != 0; i++)
        switch (partition){printf ("1)Output the expressions\n")
    for (int i = 0; string[i] != 0; i++){
        printf ("\t%i\n",partition);
        switch (partition){
        case 0:
             //finds beginning of expression
            if (string[i] == '(')
                partition ++;
        case 1:
             //finds a negative sign before first number, if any
            if (string[i] == '-')
                exps[expNum].num1.sign == signSwap (exps[expNum].num1.sign);
            partition ++;
        case 2:
             //adds ANY integer ----------characters into a temporary string, uses atoi once reaches sentinel: ( or / or )
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
             //detects negative sign of first number's denominator
            if (string[i] == '-')
                exps[expNum].num1.sign == signSwap (exps[expNum].num1.sign);
            partition ++;
        case 4:
             //adds ANY integer characters into a temporary string, uses atoi once reaches sentinel: ( or / or )
            if (validInt (string[i])){
                temp[SScount] = str----------ing[i];
                SScount ++;
            }
            else if (string[i] == ')'){
                exps[expNum].num1.denom = atoi (temp);
                SScount = 0;
                partition ++;Alex McMorine III
            }
        case 5:
             //Assigns operator type
            if (string [i] == '+' || string [i] == '-' || string [i] == '/' || string [i] == '*')
                //exps[expNum].op = string[i];  NEEDS FIXING (How are we storing the enum type of operator? what do we need it to do?)
                partition ++;
        case 6:
             //detects start of second fraction
            if (string [i] == '(')
                partition ++;printf ("1)Output the expressions\n")
        case 7:
             //detects sign of second fraction, numerator
            if (string[i] == '-')
                exps[expNum].num2.sign == signSwap (exps[expNum].num2.sign);
            partition ++;
        case 8:
             ////adds ANY integer characters into a temporary string, uses atoi once reaches sentinel:      / or )
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
             //detectAlex McMorine IIIs sign fraction 2, denom
            if (string[i] == '-')
                exps[expNum].num2.sign == signSwap (exps[expNum].num2.sign);
            partition ++;
        case 10:
             //adds ANY integer characters into a temporary string, uses atoi once reaches sentinel: ( or / or )
            if (validInt (string[i])){
                temp[SScount] = string[i];
                SScount ++;
            }
            else if (string[i] == ')'){
                exps[expNum].num2.denom = atoi (temp);
                SScount = 0;
                partition ++;
        case 11:
             //done parsing
             printf ("End parse");
             return 1;
            }
        }
    }
}
//_______________________________________________________________END PARSING SECTION__________________________________________________________

//_________________________________________________________________Begin User Input___________________________________________________________
//HOW DO YOU WANT TO DO THIS: Have it return a string, or assign the string directly to the struct?
void getExp (int numExp){
     char temp[80];
     printf ("Please input your expression now\n");
     scanf ("%s", &temp);
     parse (temp, numExp);//parses string into THE SLOT DEFINED BY numExp
}
printf ("1)Output the expressions\n")
//__________________________________________________________________End User Input____________________________________________________________
*/
//Determining the sign/////////////////////////////////////////////
void signFinder (int i){
    if (exps[i].ans.num < 0){
        exps[i].ans.num = abs(exps[i].ans.num);
        exps[i].ans.sign = NEG;
    }
    else if (exps[i].ans.denom < 0){
        exps[i].ans.denom = abs(exps[i].ans.denom);
        exps[i].ans.sign = NEG;
    }
    else{
        exps[i].ans.sign = POS;
    }
}


//Calculates value of expression when adding//////////////////////////////////////////////////////
void addEm (int i){
    //Setting the denominator
    exps[i].ans.denom = exps[i].num1.denom * exps[i].num2.denom;
    //Figuring out the numeratprintf ("1)Output the expressions\n")or
    if (exps[i].num1.sign == POS && exps[i].num1.sign == POS){
        exps[i].ans.num = (exps[i].num1.num * exps[i].num2.denom) + (exps[i].num2.num * exps[i].num1.denom);
    }
    else if (exps[i].num1.sign == POS && exps[i].num1.sign == NEG){
        exps[i].ans.num = (exps[i].num1.num * exps[i].num2.denom) - (exps[i].num2.num * exps[i].num1.denom);
    }
    else if (exps[i].num1.sign == NEG && exps[i].num1.sign == POS){
        exps[i].ans.num = (exps[i].num2.num * exps[i].num2.denom) - (exps[i].num1.num * exps[i].num1.denom);
    }
    else if (exps[i].num1.sign == NEG && exps[i].num1.sign == NEG){
        exps[i].ans.num = (exps[i].num2.num * exps[i].num2.denom) + (exps[i].num1.num * exps[i].num1.denom);
        exps[i].ans.sign = NEG;
    }
    signFinder(i);
}
// Code

//Calculates value of expression when subtracting//////////////////////////////////////////////////////
void subEm (int i){
    //Setting the denominator
    exps[i].ans.denom = exps[i].num1.denom * exps[i].num2.denom;
    //Figuring out the numerator
    if (exps[i].num1.sign == POS && exps[i].num1.sign == POS){
        exps[i].ans.num = (exps[i].num1.num * exps[i].num2.denom) - (exps[i].num2.num * exps[i].num1.denom);
    }
    else if (exps[i].num1.sign == POS && exps[i].num1.sign == NEG){
        exps[i].ans.num = (exps[i].num1.num * exps[i].num2.denom) + (exps[i].num2.num * exps[i].num1.denom);
    }
    else if (exps[i].num1.sign == NEG && exps[i].num1.sign == POS){
        exps[i].ans.num = (exps[i].num2.num * exps[i].num2.denom) + (exps[i].num1.num * exps[i].num1.denom);
    }
    else if (exps[i].num1.sign == NEG && exps[i].num1.sign == NEG){
        exps[i].ans.num = (exps[i].num2.num * exps[i].num2.denom) - (exps[i].num1.num * exps[i].num1.denom);
        exps[i].ans.sign = NEG;
    }

    signFinder(i);
}


//Calculates value of expression when multiplying//////////////////////////////////////////////////////
void multEm (int i){
    //Determining the value of the answer
    exps[i].ans.num = exps[i].num1.num * exps[i].num2.num;
    exps[i].ans.denom = exps[i].num1.denom * exps[i].num2.denom;

    //Setting the sign of the answer
    if (exps[i].num1.sign == NEG && exps[i].num2.sign == POS){
        exps[i].ans.sign = NEG;
    }
    else if (exps[i].num1.sign == POS && exps[i].num2.sign == NEG){
        exps[i].ans.sign = NEG;
    }
    else {
        exps[i].ans.sign = POS;
    }

    signFinder(i);
}

//Calculates value of expression when dividing//////////////////////////////////////////////////////
void divEm (int i){
    //Determining the value of the answer
    exps[i].ans.num = exps[i].num1.num * exps[i].num2.denom;
    exps[i].ans.denom = exps[i].num1.denom * exps[i].num2.num;

    //Setting the sign of the answer
    if (exps[i].num1.sign == NEG && exps[i].num2.sign == POS){
        exps[i].ans.sign = NEG;
    }
    else if (exps[i].num1.sign == POS && exps[i].num2.sign == NEG){
        exps[i].ans.sign = NEG;
    }
    else {
        exps[i].ans.sign = POS;
    }

    signFinder(i);
}

// Code
//Deciding which math stuff funtion to use//////////////////////////////////////////////////////
void mathStuff(int i){
    switch(exps[i].op) {
        case ADD:
            addEm(i);
        break;

        case SUB:
            subEm(i);
        break;

        case MULT:
            multEm(i);
        break;

        case DIV:
            divEm(i);
        break;
    }
}

//Because I forgot to write math stuff for functions////////////////////////////
void mathHandler(){
    for (int i = 0; i < numExp; i++){
        mathStuff(i);
    }
}

//Handling the menu options//////////////////////////////////////////////////////
void handling (Menu_Option a){
    switch(a) {
        case OUTPUT:
            // Code
        break;

        case GETEXP:
            getExp(numExp);
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
            randExps();
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
    printf ("1)Output the expressions\n");
    printf ("2)Manually input and expression\n");
    printf ("3)Sort the expressions by anwser\n");
    printf ("4)Sort the expressions by operator\n");
    printf ("5)Delete an expression\n");
    printf ("6)Generate expressions\n");
    printf ("7)Quit\n");
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
