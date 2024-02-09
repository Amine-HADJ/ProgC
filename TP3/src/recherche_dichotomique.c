/*
 * fichier: recherche_dichotomique.c
 * But: Générer 100 nombres aléatoires entre 0 et 1000, les trier par ordre croissant, puis chercher un entier dans le tableau par la recherche dichotomique
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

    // remplissage du tableau avec 100 nombres aléatoires entre 0 et 1000
    for (int i = 0; i < 100; i++)
    {
        tab[i] = rand() % 1000;
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

    // recherche dichotomique de l'entier dans le tableau
    int entier_a_chercher;
    printf("\nEntrez l'entier que vous voulez chercher : ");
    scanf("%d", &entier_a_chercher);

    // déclaration des variables
    int trouve = 0; // variable booléenne pour savoir si l'entier est trouvé ou non
    int debut = 0;  // indice du début du tableau
    int fin = 99;   // indice de la fin du tableau
    int milieu;     // indice du milieu du tableau

    // recherche dichotomique
    while (debut <= fin && trouve == 0)
    {                               // tant que l'entier n'est pas trouvé et qu'on a pas parcouru tout le tableau
        milieu = (debut + fin) / 2; // on calcule l'indice du milieu du tableau
        if (tab[milieu] == entier_a_chercher)
        {               // si l'entier est trouvé
            trouve = 1; // on affecte 1 à la variable booléenne
        }
        else if (tab[milieu] > entier_a_chercher)
        {                     // si l'entier est plus petit que l'élément du milieu
            fin = milieu - 1; // on affecte l'indice du milieu - 1 à la variable fin
        }
        else
        {                       // si l'entier est plus grand que l'élément du milieu
            debut = milieu + 1; // on affecte l'indice du milieu + 1 à la variable debut
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