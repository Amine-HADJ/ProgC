/* Fichier: conditions.c
 * affiche: les nombres divisibles par 2 et 15 simultanément, les nombres divisibles par 103 ou 107, les nombres divisibles par 7 ou 5, mais ne sont pas divisibles par 3.
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
 */

#include <stdio.h> // headers

int main()
{
    printf("Nombres divisibles par 2 et 15 simultanément:\n"); // Affiche les nombres divisibles par 2 et 15 simultanément
    for (int i = 1; i <= 1000; i++)
    { // Boucle de 1 à 1000
        if (i % 2 == 0 && i % 15 == 0)
        {                     // Si le nombre est divisible par 2 et 15 simultanément
            printf("%d ", i); // Affiche le nombre
        }
    }
    printf("\n\n");

    printf("Nombres divisibles par 103 ou 107:\n"); // Affiche les nombres divisibles par 103 ou 107
    int i = 1;
    while (i <= 1000)
    {                                     // Boucle de 1 à 1000
        if (i % 103 == 0 || i % 107 == 0) // Si le nombre est divisible par 103 ou 107
            printf("%d ", i);             // Affiche le nombre
        i++;                              // Passe au nombre suivant
    }
    printf("\n\n");

    printf("Nombres divisibles par 7 ou 5, mais ne sont pas divisibles par 3:\n"); // Affiche les nombres divisibles par 7 ou 5, mais ne sont pas divisibles par 3
    i = 1;
    do
    {
        if ((i % 7 == 0 || i % 5 == 0) && i % 3 != 0) // Si le nombre est divisible par 7 ou 5, mais ne sont pas divisibles par 3
            printf("%d ", i);                         // Affiche le nombre
        i++;
    } while (i <= 1000); // Boucle de 1 à 1000

    printf("\n");

    return 0; // Fin du programme
}
