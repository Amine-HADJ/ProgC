/* Fichier: tableauptr.c
 * but : Manipuler les tableaux à l'aide des pointeurs
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / ELTAHIRI YOUNESS
 */

#include <stdio.h>  // Headers 
#include <stdlib.h> //pour acceder à la fontion rand()
#include <time.h>   //pour acceder à la fontion time()

int main()
{

    // Déclaration des tableaux
    int int_tab[10];
    float float_tab[10];

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Remplissage des tableaux avec des valeurs aléatoires
    for (int i = 0; i < 10; i++)
    {
        int_tab[i] = rand() % 100;
        float_tab[i] = (float)rand() / RAND_MAX;
    }

    // Affichage des tableaux avant la multiplication par 3
    printf("Tableau d'entiers (avant la multiplication par 3) : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", *(int_tab + i));
        if (i < 10 - 1)
        {
            printf(", ");
        }
    }
    printf("\n\n");

    printf("Tableau de nombres à virgule flottante (avant la multiplication par 3) : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%f", *(float_tab + i));
        if (i < 10 - 1)
        {
            printf(", ");
        }
    }
    printf("\n\n");

    // Multiplication par 3 des valeurs d'indice pair en utilisant des pointeurs
    int *int_ptr = int_tab; // Déclaration des pointeurs
    float *float_ptr = float_tab;
    for (int i = 0; i < 10; i += 2)
    {
        *(int_ptr + i) *= 3;
        *(float_ptr + i) *= 3;
    }

    // Affichage des tableaux après la multiplication par 3
    printf("Tableau d'entiers (après la multiplication par 3) : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", *(int_tab + i));
        if (i < 9)
        {
            printf(", ");
        }
    }
    printf("\n\n");

    printf("Tableau de nombres à virgule flottante (après la multiplication par 3) : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%f", *(float_tab + i));
        if (i < 9)
        {
            printf(", ");
        }
    }

    return 0; // fin du programme
}