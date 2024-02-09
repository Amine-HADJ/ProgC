/*
 * fichier: fichier.h
 * but: definir les fonctions qui permettent de lire et d'ecrire dans un fichier
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI EL ALAOUI YOUNESS
 */

// headers
#ifndef FICHIER_H
#define FICHIER_H
#include <stdio.h>

void lire_fichier(const char *nom_de_fichier)
{
    FILE *fichier = fopen(nom_de_fichier, "r"); // ouvre le fichier en mode lecture ("r")
    if (fichier == NULL)
    {                                                    // si le fichier n'existe pas
        perror("Erreur lors de l'ouverture du fichier"); // affiche le message d'erreur
        return;                                          // quitte la fonction
    }

    char ligne[1000]; // ligne de 1000 caracteres
    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
    {                        // tant qu'il y a des lignes a lire
        printf("%s", ligne); // affiche la ligne
    }
    printf("\n\n");
    fclose(fichier); // ferme le fichier
}

void ecrire_dans_fichier(const char *nom_de_fichier, const char *message)
{
    FILE *fichier = fopen(nom_de_fichier, "a"); // ouvre le fichier en mode ajout ("a") pour ne pas supprimer le contenu du fichier
    if (fichier == NULL)
    {                                                    // si le fichier n'existe pas
        perror("Erreur lors de l'ouverture du fichier"); // affiche le message d'erreur
        return;                                          // quitte la fonction
    }

    fprintf(fichier, "\n");          // on ajoute un retour à la ligne avant le message pour ne pas ecraser le contenu du fichier
    fprintf(fichier, "%s", message); // ecrit le message dans le fichier
    printf("Le message à bien été ecrit dans le fichier\n");

    fclose(fichier);
}

#endif // FICHIER_H
