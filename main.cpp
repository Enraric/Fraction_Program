/* INTRUCTIONS
Add random expression --- Alex McMorine III
Get expression from user --- Harrison
Sort by answer --- Harrison
Output expressions with answers --- Swiggity Swilson
Delete expression --- Swiggityy Swilson
Sort by operator then by answer --- Alex McMorine III
*/
//Harrison: Guys, can we initialize our fractions?  It would make sign swapping a helluva lot easier (specifically make sign positive)
//Alex  M: Feel free to if you can do it without destroying everything


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_EXP 30
#include <iostream>


int rb (int min, int max) {
    return rand() % (max - min + 1) + min;
}

int getNum (int min, int max){ // Thing Wilson likes to have to get a number between a min and max value. Could be useful.
	int num = 0;

	std::cin >> num;
	while (num < min || num > max){
		std::cin >> num;
	}
}

//Custom types/////////////////////////////////////////////////////
enum Operat {ADD, SUB, MULT, DIV, NONE};
enum Sign {POS, NEG, NOONE}; // Why can't I use none twice

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

Expression exps [MAX_EXP];
int numExp = 0;

//created an enum type to make the menu options more readable
enum Menu_Option {OUTPUT = 0, GETEXP = 1, SORT_ANSWER = 2, SORT_OPERATOR = 3, DELETE = 4, GENERATE = 5, QUIT = 6, MENU_MAX = 7};

//checks whether input is valid or not
bool inputCheck(int userInput) {
    return (0 <= userInput && userInput <= MENU_MAX) ? 1 : 0; //It's a compact if/else, dude. Not magic at all.
}


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


// Wilson's shitty output expn. with answer function....
void putExpAns (){	
	int index = 0;
	
	printf ("Input which # expression you would like to output (0-29). \n");
	index = getNum (0,29);
	mathStuff (index);
	// it's only the first thing for now, but I want to push the thing before we leave.
	printf ("\n(%c%i/%i)", exps[index].num1.sign, exps[index].num1.num, exps[index].num1.denom);
	/*printf ("%c",exps[index].num1.sign);
	printf ("%i",exps[index].num1.num);
	printf ("/");
	printf ("%i",exps[index].num1.denom);
	printf (")"); */
	printf (" %c ",exps[index].op);
	printf ("(%c%i/%i)", exps[index].num2.sign, exps[index].num2.num, exps[index].num2.denom);
	printf (" = (%c%i/%i)", exps[index].ans.sign, exps[index].ans.num, exps[index].ans.denom);
	
}

void deleteExp (){ // Wilson's deleteExp stuff.. I should really be using a constant for 29, but saying MAX EXP -1 is confusing...
	int index = 0;
	
	printf ("Input which # expression you would like to delete (0-29). \n");
	index = getNum (0,29);
	
	// Fun fact: This code is only here because my for loop doesn't work if they input 29.
	exps[index].num1.num = 0;
	exps[index].num1.denom = 0;
	exps[index].num2.num = 0;
	exps[index].num2.denom = 0;
	exps[index].ans.num = 0;
	exps[index].ans.denom = 0;
	exps[index].op = NONE; // Pls tell me this counts as the null character.
	
	for (int i = index;i<= 28;i++){
		exps[i].num1.num = exps[i+1].num1.num;
		exps[i].num1.denom = exps[i+1].num1.denom;
		exps[i].num2.num = exps[i+1].num2.num;
		exps[i].num2.denom = exps[i+1].num2.denom;
		exps[i].ans.num = exps[i+1].ans.num;
		exps[i].ans.denom = exps[i+1].ans.denom;
	}

}

//-------------------------------------------Sorting by Operator-------------------------------------------

void opSort (){
    Expression temp;
    for (int i = 0; i < numExp; i++){
        for (int j = 0; j < numExp; i++){
            if (exps[i].op > exps[i+1].op){
                temp = exps[i+1];
                exps[i+1] = exps[i];
                exps[i] = temp;
            }
            else if (exps[i].op == exps[i+1].op && exps[i].ans.num/exps[i].ans.denom > exps[i+1].ans.num/exps[i+1].ans.denom && exps[i].ans.sign >= exps[i].ans.sign){
                temp = exps[i+1];
                exps[i+1] = exps[i];
                exps[i] = temp;
            }
        }
    }
}

/*
ARE WE EVEN USING THIS???

int gcd(int x, int y) {
    return (y != 0) ? gcd(y, x % y) : x;
}
*/

//-----------------------------------------------RAND STUFF------------------------------------------------

void randExps (){
    int numExps;

    do{
        printf ("\nEnter the number of expressions you would like to generate: ");
        scanf ("%i", &numExps);
        if (numExps > 30 || numExps < 0){
            printf ("Invalid number.\n");
        }
    }while (numExps > 30 || numExps < 0);

    numExp == numExps;

    for (int i = 0; i < numExps; i++){
        exps[i].num1.num = rb (0,99);
        exps[i].num1.denom = rb (0,99);
        exps[i].num1.sign = (Sign) rb (0,1);
        exps[i].num2.num = rb (0,99);
        exps[i].num2.denom = rb (0,99);
        exps[i].num2.sign = (Sign) rb (0,1);
        exps[i].op = (Operat) rb (0,3);
        mathStuff(i);
    }

}

//---------------------------------------------------------------------------------------------------------

//______________________________________________________________BEGIN PARSE SECTION___________________________________________________________

bool validInt (char character){
    return (character >= 48 && character <= 57);
}

bool validOperator (char str){
    return ((str) == '+' || (str) == '-' || (str) == '/' || (str) == '*' );
}

Sign signSwap(Sign sign){//The naming is strong with this one
    if (sign == NEG)
       sign = POS;
    else if (sign == POS)
         sign = NEG;
    return sign;
}

int parse (char str[80], int expNum){
    int SScount = 0;
    int partition = 0;
    char temp [80] = {""};
    //attempting to handle format of ( - # ) OP ( - # ), with spaces between anything
    //walks through array, looking for a different sentinels
    for (int i = 0; str[i] != 0; i++){
        printf ("%i\t%c\t%i\n", i, str[i], partition);
        switch (partition){
        case 0:
             //finds beginning of expression
            if (str[i] == '(')
                partition ++;
            break;
        case 1:
             //finds any negative signs, each one switches the current sign
            //also takes all digits until the slash or bracket
            //replace with function if time allows
            if (str[i] == '-')
                exps[expNum].num1.sign = signSwap (exps[expNum].num1.sign);
            else if (validInt (str [i])){
                temp[SScount] = str[i];
                SScount ++;
            }
            else if (str[i] == '/'){
                temp [SScount+1] = 0;
                exps[expNum].num1.num = atoi (temp);
                SScount=0;
                partition ++;
            }
                break;
        case 2:
            if (str[i] == '-')
                exps[expNum].num1.sign = signSwap (exps[expNum].num1.sign);
            else if (validInt (str [i])){
                temp[SScount] = str[i];
                SScount ++;
            }
            else if (str[i] == ')'){
                temp [SScount+1] = 0;
                exps[expNum].num1.denom = atoi (temp);
                SScount=0;
                partition ++;
            }
                break;
        case 3:
             //Assigns operator type
            if (str [i] == '+' || str [i] == '-' || str [i] == '/' || str [i] == '*')
                //exps[expNum].op = str[i];  NEEDS FIXING (How are we storing the enum type of operator? what do we need it to do?)
                partition ++;
            break;
        case 4:
             //detects start of second fraction
            if (str [i] == '(')
                partition ++;
                break;
        case 5:
            if (str[i] == '-')
                exps[expNum].num2.sign = signSwap (exps[expNum].num2.sign);
            else if (validInt (str [i])){
                temp[SScount] = str[i];
                SScount ++;
            }
            else if (str[i] == '/'){
                temp [SScount+1] = 0;
                exps[expNum].num2.num = atoi (temp);
                SScount=0;
                partition ++;
            }
                break;
        case 6:
            if (str[i] == '-')
                exps[expNum].num2.sign = signSwap (exps[expNum].num2.sign);
            else if (validInt (str [i])){
                temp[SScount] = str[i];
                SScount ++;
            }
            else if (str[i] == ')'){
                temp [SScount+1] = 0;
                exps[expNum].num2.denom = atoi (temp);
                SScount=0;
                partition ++;
            }
                break;
        default:
            break;
        }
    }
    if (partition >= 7){
        printf ("parse complete\n\n");
        return 1;
    }
    else{
        printf ("Parse Failed\n");
        return 0;
    }
}
//_______________________________________________________________END PARSING SECTION__________________________________________________________

//_________________________________________________________________Begin User Input___________________________________________________________
void clear (){
  while ( getchar() != '\n' );
}

void getExp (int numExp){
    char temp[80];
    clear();
    do {
        printf ("Please input your expression now\n");
        gets(temp);
    } while (!parse(temp, numExp) && (numExp < MAX_EXP));//parses string into THE SLOT DEFINED BY numExp
    putExpAns ();
}
//__________________________________________________________________End User Input____________________________________________________________



//Handling the menu options//////////////////////////////////////////////////////
void handling (Menu_Option a){
    switch(a) {
        case OUTPUT:
            // Code
            putExpAns ();
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
            deleteExp ();
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



void menuPrint (){
printf ("0)Output the expressions\n");
printf ("1)Manually input and expression\n");
printf ("2)Sort the expressions by anwser\n");
printf ("3)Sort the expressions by operator\n");
printf ("4)Delete an expression\n");
printf ("5)Generate expressions\n");
printf ("6)Quit\n");
}

//Menu stuff//////////////////////////////////////////////////////
Menu_Option menu() {
    char temp [80];
    int userInput = 0;
    menuPrint();
    do {
        printf ("Input the number of your choice\n");
        scanf ("%s",&temp); //IT WAS THE GETS THAT WAS GIVING US CRAP, DON'T KNOW WHY SCANF FIXED BUT IT DID (DON'T COMPLAIN)   ...USE CIN THO -Wilson
        userInput = atoi (temp);
    } while (!inputCheck (userInput));
    return (Menu_Option) userInput;
}


//Main//////////////////////////////////////////////////////
int main() {
    Menu_Option menuchoice;
    do{
        srand (time(NULL));
        menuchoice = menu();
        handling (menuchoice);
    }while (menuchoice != QUIT);
}
