/*
* fichier: calcule.c
* but: effectuer un calcule grace à la ligne de commande
* auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI YOUNESS
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf(" Usage: %s <op> <nb1> <nb2>\n", argv[0]);
        return 1;
    }

    char op = argv[1][0];
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);

    switch(op) {
        case '+':
            printf("%d %c %d = %d\n", num1, op, num2, somme(num1, num2));
            break;
        case '-':
            printf("%d %c %d = %d\n", num1, op, num2, difference(num1, num2));
            break;
        case '*':  
            printf("%d %c %d = %d\n", num1, op, num2, produit(num1, num2));
            break;
        case '/':
            printf("%d %c %d = %d\n", num1, op, num2, quotient(num1, num2));
            break;
        case '%':
            printf("%d %c %d = %d\n", num1, op, num2, modulo(num1, num2));
            break;
        case '&':
            printf("%d %c %d = %d\n", num1, op, num2, et(num1, num2));
            break;
        case '|':
            printf("%d %c %d = %d\n", num1, op, num2, ou(num1, num2));
            break;
        case '~':
            printf("%c %d = %d\n", op, num1, negation(num1));
            break;
            
        
            
    }

    

    return 0; // Fin du programme
}

