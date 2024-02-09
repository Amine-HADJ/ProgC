/*
 * fichier: repertoire.h
 * but:
 * auteurs:
 */

#ifndef REPERTOIRE_H
#define REPERTOIRE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void lire_dossier(char *nom_repertoire)
{
    // ouverture du repertoire
    DIR *rep = opendir(nom_repertoire);

    // test si le repertoire est bien ouvert
    if (rep == NULL)    // si le repertoire n'est pas ouvert
    {                  // on affiche un message d'erreur
        perror("Erreur ouverture repertoire");
        exit(1); 
    }

    // lecture des fichiers présents dans le repertoire
    struct dirent *entree;
    while ((entree = readdir(rep)) != NULL)
    {
        // on affiche le nom du fichier
        printf("%s\n", entree->d_name);
    }

    // fermeture du repertoire
    closedir(rep);

    return;
}




#endif // REPERTOIRE_H
