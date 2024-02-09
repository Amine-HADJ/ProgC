/*
 * fichier: chercher.c
 * But: Chercher un entier dans un tableau d'entiers généré aléatoirement
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

    // affichage du tableau généré
    printf("Tableau généré : \n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", tab[i]);
    }

    // demande à l'utilisateur d'entrer l'entier qu'il veut chercher
    int entier_a_chercher;
    printf("Entrez l'entier que vous voulez chercher : ");
    scanf("%d", &entier_a_chercher);

    // recherche de l'entier dans le tableau

    int trouve = 0; // variable booléenne pour savoir si l'entier est trouvé ou non
    for (int i = 0; i < 100; i++)
    {
        if (tab[i] == entier_a_chercher)
        {
            trouve = 1;
        }
    }

    // affichage du résultat
    if (trouve == 1)
    {
        printf("Résultat: entier présent \n");
    }
    else
    {
        printf("Résultat: entier absent \n");
    }

    return 0; // fin du programme
}