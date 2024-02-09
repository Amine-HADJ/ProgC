/*
 * fichier: grand_petit.c
 * But: Générer 100 nombres aléatoires entre 0 et 1000 et afficher le numéro le plus grand et le numéro le plus petit
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


    int max = tab[0]; // initialisation du numéro le plus grand
    int min = tab[0]; // initialisation du numéro le plus petit
    for (int i = 0; i < 100; i++)
    { // parcours du tableau
        if (tab[i] > max)
        { // si le numéro est plus grand que le numéro le plus grand
            max = tab[i]; // on remplace le numéro le plus grand par le numéro
        }
        if (tab[i] < min) 
        { // si le numéro est plus petit que le numéro le plus petit
            min = tab[i]; // on remplace le numéro le plus petit par le numéro
        }
    }

    // Affichage du numéro le plus grand et le numéro le plus petit
    printf("Le numéro le plus grand est : %d\n", max);
    printf("Le numéro le plus petit est : %d\n", min);

    return 0; // fin du programme
}