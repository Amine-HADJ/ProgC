/*
 * fichier: repertoire.h
 * but: contient les fonctions pour lire le contenu d'un repertoire et de ses sous-repertoires
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI EL ALOUI YOUNESS
 */

#ifndef REPERTOIRE_H // headers
#define REPERTOIRE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// 5.1 lire_dossier

int lire_dossier(char *nom_repertoire)
{
    // ouverture du repertoire
    DIR *rep = opendir(nom_repertoire); // opendir retourne un pointeur de type DIR (structure) qui contient les informations sur le repertoire

    // test si le repertoire est bien ouvert
    if (rep == NULL) // si le repertoire n'est pas ouvert
    {
        perror("Erreur ouverture repertoire"); // on affiche un message d'erreur
        return 1;                              // on quitte le programme
    }

    printf("Contenu de %s :\n", nom_repertoire);


    // lecture des fichiers présents dans le repertoire
    struct dirent *entree;                  // structure dirent qui contient les informations sur le fichier
    while ((entree = readdir(rep)) != NULL) // readdir retourne un pointeur de type struct dirent
    {
        // on affiche le nom du fichier
        printf("%s\n", entree->d_name); // d_name est un champ de la structure dirent qui contient le nom du fichier
    }

    // fermeture du repertoire
    closedir(rep);

    return 0;
}

// 5.2 lire_dossier_recursif (fonction appelle a elle meme pour chaque nouveau dossier trouvé)

int lire_dossier_recursif(char *nom_repertoire)
{
    // ouverture du repertoire
    DIR *rep = opendir(nom_repertoire);
    // test si le repertoire est bien ouvert
    if (rep == NULL) // si le repertoire n'est pas ouvert
    {                // on affiche un message d'erreur
        perror("Erreur ouverture repertoire");
        return 1;
    }

    printf("Contenu de %s :\n", nom_repertoire);
    // lecture des fichiers présents dans le repertoire
    struct dirent *entree;
    while ((entree = readdir(rep)) != NULL)
    {

        
        printf("%s\n", entree->d_name); // on affiche le nom du fichier
        if (entree->d_type == DT_DIR && strcmp(entree->d_name, ".") != 0 && strcmp(entree->d_name, "..") != 0)
        {
            char *nom_complet = malloc(strlen(nom_repertoire) + strlen(entree->d_name) + 2);
            sprintf(nom_complet, "%s/%s", nom_repertoire, entree->d_name); // sprintf permet de concatener 2 chaines de caracteres
            lire_dossier_recursif(nom_complet);                            // appel recursif
            free(nom_complet);                                             // liberation de la memoire allouee par malloc
        }
    }

    // fermeture du repertoire
    closedir(rep);

    return 0;
}

// 5.3 lire_dossier_iteratif (boucle for et while pour parcourir les fichiers et dossiers)
int lire_dossier_iteratif(char *nom_repertoire)
{

    // pile pour stocker les noms des répertoires à parcourir
    char **pile = NULL;
    int taille_pile = 0;

    // ouverture du répertoire initial
    DIR *rep = opendir(nom_repertoire);
    if (rep == NULL)
    {
        perror("Erreur ouverture repertoire");
        return 1;
    }

    // initialisation de la pile avec le répertoire initial
    pile = (char **)realloc(pile, sizeof(char *) * (taille_pile + 1));
    pile[taille_pile] = (char *)malloc(strlen(nom_repertoire) + 1);
    strcpy(pile[taille_pile], nom_repertoire);
    taille_pile++;

    // boucle pour parcourir les répertoires de manière itérative
    while (taille_pile > 0)
    {
        char *repertoire_courant = pile[taille_pile - 1]; // récupère le dernier répertoire ajouté à la pile
        taille_pile--;

        printf("Contenu de %s :\n", repertoire_courant);

        // ouverture du répertoire courant
        DIR *rep_courant = opendir(repertoire_courant);
        if (rep_courant == NULL)
        {
            perror("Erreur ouverture repertoire");
            return 1;
        }

        // lecture des fichiers et sous-répertoires
        struct dirent *entree;
        while ((entree = readdir(rep_courant)) != NULL)
        {
            printf("%s\n", entree->d_name);
            if (entree->d_type == DT_DIR &&
                strcmp(entree->d_name, ".") != 0 &&
                strcmp(entree->d_name, "..") != 0)
            {
                // construit le chemin complet du sous-répertoire
                char *nom_complet = (char *)malloc(strlen(repertoire_courant) + strlen(entree->d_name) + 2);
                sprintf(nom_complet, "%s/%s", repertoire_courant, entree->d_name);

                // ajoute le sous-répertoire à la pile
                pile = (char **)realloc(pile, sizeof(char *) * (taille_pile + 1));
                pile[taille_pile] = nom_complet;
                taille_pile++;
            }
        }

        // fermeture du répertoire courant
        closedir(rep_courant);
    }

    // libération de la mémoire allouée pour la pile
    for (int i = 0; i < taille_pile; i++)
    {
        free(pile[i]);
    }
    free(pile);

    return 0;
}

#endif // REPERTOIRE_H
