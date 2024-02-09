/* Fichier: opérateurs2.c
 * affiche: le résultat d'une opération arithmétique ou logique sur deux entiers.
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
 */

#include <stdio.h> // headers

int main()
{
    int num1, num2; // Déclaration des deux entiers
    char op;        // Déclaration de l'opérateur

    printf("Entrez deux entiers : "); // Demande à l'utilisateur d'entrer deux entiers
    scanf("%d %d", &num1, &num2);     // Lecture des deux entiers

    printf("Entrez l'opérateur (+ - * / %% & | ~) : "); // Demande à l'utilisateur d'entrer l'opérateur
    scanf(" %c", &op);                                  // Lecture de l'opérateur

    switch (op)
    {         // Vérifie l'opérateur
    case '+': // Si l'opérateur est '+'
        printf("Résultat : %d + %d = %d\n", num1, num2, num1 + num2);
        break;
    case '-': // Si l'opérateur est '-'
        printf("Résultat : %d - %d = %d\n", num1, num2, num1 - num2);
        break;
    case '*': // Si l'opérateur est '*'
        printf("Résultat : %d * %d = %d\n", num1, num2, num1 * num2);
        break;
    case '/': // Si l'opérateur est '/'
        if (num2 != 0)
            printf("Résultat : %d / %d = %f\n", num1, num2, (float)num1 / num2);
        else
            printf("Division par zéro impossible.\n");
        break;
    case '%': // Si l'opérateur est '%'
        if (num2 != 0)
            printf("Résultat : %d %% %d = %d\n", num1, num2, num1 % num2);
        else
            printf("Division par zéro impossible.\n");
        break;
    case '&': // Si l'opérateur est '&'
        printf("Résultat (opération ET) : %d & %d = %d\n", num1, num2, num1 & num2);
        break;
    case '|': // Si l'opérateur est '|'
        printf("Résultat (opération OU) : %d | %d = %d\n", num1, num2, num1 | num2);
        break;
    case '~': // Si l'opérateur est '~'
        printf("Résultat (complément à un) : ~%d = %d\n", num1, ~num1);
        break;
    default: // Si l'opérateur n'est pas reconnu
        printf("Opérateur non reconnu.\n");
    }

    return 0; // Fin du programme
}
