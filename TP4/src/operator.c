/*
* fichier: operator.c
* but :
* auteur: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI YOUNESS
*/


#include "operator.h"
#include <stdio.h>


int main(){

    int a, b;
    char op;

    printf("Entrez 2 nombres entiers: \n");
    printf("a :");
    scanf("%d", &a);

    printf("b :");
    scanf("%d", &b);


    printf("Entrez un opérateur parmis +, -, *, /, %%, &, |, ~:");
    scanf(" %c", &op);

     switch(op) {
        case '+':
            printf("Le résultat de la somme de %d et %d est %d\n", a, b, somme(a, b));
            break;
        case '-':
            printf("Le résultat de la différence de %d et %d est %d\n\n", a, b, difference(a, b));
            break;
        case '*':
            printf("Le résultat du produit de %d et %d est %d\n\n", a, b, produit(a, b));
            break;
        case '/':
            printf("Le résultat du quotient de %d et %d est %d\n\n", a, b, quotient(a, b));
            break;
        case '%':
            printf("Le résultat du modulo de %d et %d est %d\n\n", a, b, modulo(a, b));
            break;
        case '&':
            printf("Le résultat du et de %d et %d est %d\n\n", a, b, et(a, b));
            break;
        case '|':
            printf("Le résultat du ou de %d et %d est %d\n\n", a, b, ou(a, b));
            break;
        case '~':
            printf("Le résultat de la négation de %d est %x\n\n", a, negation(a));
            break;
        default:
            printf("Opérateur non reconnu\n\n");
            break;
            
    }

    return 0; // Fin du programme
}
    


