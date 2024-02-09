/*
 * fichier: couleur_compteur.c
 * but: Générer aléatoirement 100 couleurs et compter les occurrences de chaque couleur
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI YOUNESS
 */

#include <stdio.h> // headers
#include <stdlib.h>
#include <time.h>

// Définition des structures

typedef struct
{
    int R;
    int G;
    int B;
    int A;
} Couleur;

typedef struct
{
    int R2;
    int G2;
    int B2;
    int A2;
    int occurence;
} Occurence;

// Définition de le fonction qui vérifie si une couleur est déjà comptée

int couleur_deja_comptee(Couleur couleur, Occurence *occurences, int nb_couleurs)
{
    for (int i = 0; i < nb_couleurs; i++)
    {                                        // Parcours du tableau d'occurences
        if (couleur.R == occurences[i].R2 && // Si la couleur est déjà comptée
            couleur.G == occurences[i].G2 && 
            couleur.B == occurences[i].B2 &&
            couleur.A == occurences[i].A2)
        {
            return i; // On retourne l'indice de la couleur
        }
    }
    return -1; // La couleur n'est pas encore comptée
}

int main()
{

    srand(time(NULL)); // Initialisation de la fonction rand()

    // Déclaration des variables

    int nb_couleurs_totales = 100;
    int nb_couleurs_distinctes = 0;

    Couleur couleurs[nb_couleurs_totales];
    Occurence occurences[nb_couleurs_totales];

    // Création aléatoire de nb_couleurs_totales couleurs
    for (int i = 0; i < nb_couleurs_totales; i++)
    {
        couleurs[i].R = rand() % 256;
        couleurs[i].G = rand() % 256;
        couleurs[i].B = rand() % 256;
        couleurs[i].A = rand() % 256;
    }

    // Comptage des occurrences de chaque couleur
    for (int i = 0; i < nb_couleurs_totales; i++)
    {
        int j = couleur_deja_comptee(couleurs[i], occurences, nb_couleurs_distinctes);
        if (j >= 0)
        {
            // La couleur existe déjà dans le tableau d'occurences
            occurences[j].occurence++;
        }
        else
        {
            // Nouvelle couleur
            occurences[nb_couleurs_distinctes].R2 = couleurs[i].R;
            occurences[nb_couleurs_distinctes].G2 = couleurs[i].G;
            occurences[nb_couleurs_distinctes].B2 = couleurs[i].B;
            occurences[nb_couleurs_distinctes].A2 = couleurs[i].A;
            occurences[nb_couleurs_distinctes].occurence = 1;
            nb_couleurs_distinctes++;
        }
    }

    // Affichage des couleurs distinctes et de leurs occurrences
    for (int i = 0; i < nb_couleurs_distinctes; i++)
    {
        printf("Couleur : R = 0x%x, G = 0x%x, B = 0x%x, A = 0x%x / Occurrence(s) : %d\n\n",
               occurences[i].R2, occurences[i].G2, occurences[i].B2, occurences[i].A2, occurences[i].occurence);
    }

        printf("Le nombre de couleurs disctinctes est de %d sur %d couleurs totales \n", nb_couleurs_distinctes, nb_couleurs_totales);

    return 0; // Fin du programme
}
