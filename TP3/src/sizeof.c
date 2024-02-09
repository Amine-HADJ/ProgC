/*
 * fichier: sizeof.c
 * But: Afficher la taille des types de base et des pointeurs
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI YOUNESS
 */

#include <stdio.h> //header

int main()
{

    // Affichage de la taille des types de base
    printf("La taille de int est : %ld\n", sizeof(int));
    printf("La taille de int* est :  %ld\n", sizeof(int *));
    printf("La taille de int** est : %ld\n", sizeof(int **));
    printf("La taille de char* est :  %ld\n", sizeof(char *));
    printf("La taille de char** est : %ld\n", sizeof(char **));
    printf("La taille de char*** est : %ld\n", sizeof(char ***));
    printf("La taille de float* est : %ld\n", sizeof(float *));
    printf("La taille de float** est : %ld\n", sizeof(float **));
    printf("La taille de float*** est : %ld\n", sizeof(float ***));

    return 0; // fin du programme
}