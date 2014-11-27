#include <stdio.h>
#include <stdlib.h>

/*
int gcd(int x, int y) {
    return (y != 0) ? gcd(y, x % y) : x;
}
*/

//created an enum type to make the menu options more readable
enum Menu_Option {OUTPUT = 0, GETEXP = 1, SORT = 2, SORT_ANSWER = 3, SORT_OPERATOR = 4, DELETE = 5, GENERATE = 6, QUIT = 7, MENU_MAX = QUIT};

//checks whether input is valid or not
bool inputCheck(int userInput) {
    return (0 <= userInput && userInput <= MENU_MAX) ? 1 : 0; //Ask Remi (It does magical stuff)
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

