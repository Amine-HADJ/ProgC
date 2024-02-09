/*
 * fichier: tri.c
 * But: trier un tableau d'entiers par ordre croissant
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI YOUNESS
 */

#include <stdio.h>  //header
#include <stdlib.h> //pour acceder à la fontion rand()
#include <time.h>   //pour acceder à la fontion time()

int main()
{

    srand(time(NULL)); // initialisation de la fonction rand()

    // création tableau d'entiers de taille 100
    int tab[100];

    // génération de 100 nombres aléatoires entre 0 et 1000
    for (int i = 0; i < 100; i++)
    {
        tab[i] = rand() % 1000;
    }

    // affichage du tableau avant le tri
    printf("Tableau avant le tri : \n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", tab[i]);
    }

    // tri du tableau par ordre croissant
    int var; // variable varoraire pour stocker la valeur d'un élément du tableau
    for (int i = 0; i < 100; i++)
    {
        for (int j = i + 1; j < 100; j++)
        {
            if (tab[i] > tab[j])
            {                    // si l'élément i est supérieur à l'élément j, on les échange
                var = tab[i];    // on stocke la valeur de l'élément i dans la variable varoraire
                tab[i] = tab[j]; // on affecte la valeur de l'élément j à l'élément i
                tab[j] = var;    // on affecte la valeur de la variable varoraire à l'élément j
            }
        }
    }

    // affichage du tableau après le tri
    printf("Tableau après le tri : \n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", tab[i]);
    }

    return 0; // fin du programme
}