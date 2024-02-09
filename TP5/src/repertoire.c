/*
 * fichier: repertoire.c
 * but: lire le contenu d'un repertoire et de ses sous-repertoires en appelant les fonctions de repertoire.h
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI EL ALOUI YOUNESS
 */

// headers
#include "repertoire.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);
        return 1;
    }

    char *nom_repertoire = argv[1];

    // 5.1 lire_dossier
    printf("5.1 : lire_dossier\n");
    lire_dossier(nom_repertoire);
    printf("\n\n");

    // 5.2 lire_dossier_recursif
    printf("5.2 : lire_dossier_recursif\n");
    lire_dossier_recursif(nom_repertoire);
    printf("\n\n");

    // 5.3 lire_dossier_iteratif
    printf("5.3 : lire_dossier_iteratif\n");
    lire_dossier_iteratif(nom_repertoire);

    return 0;
}