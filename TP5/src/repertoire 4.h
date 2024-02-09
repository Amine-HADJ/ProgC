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

void lire_fichier(char *nom_repertoire)
{

void listerFichiersRepertoire(const char *nomRepertoire) {
    DIR *rep = opendir(nomRepertoire);
    if (rep == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        exit(EXIT_FAILURE);
    }

    struct dirent *ent;
    while ((ent = readdir(rep)) != NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(rep);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <repertoire>\n", argv[0]);
        return EXIT_FAILURE;
    }

    listerFichiersRepertoire(argv[1]);

    return EXIT_SUCCESS;
}

}

#endif // REPERTOIRE_H
