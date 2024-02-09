/*
 * fichier: main.c
 * but: fichier "père" qui va compiler et exécuter les fichiers du TP4
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI EL ALAOUI YOUNESS
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"
#include "liste.c"

int main()
{

    // Déclaration des variables
    char nom_fichier[7][100]; // tableau de 7 chaines de caractères de 100 caractères maximum pour contenir les noms des fichiers

    // Lecture des nom des fichier .c présent dans le repertoire par un appel system
    system("ls | grep c$ > liste_fichiers.txt"); // on redirige la sortie de la commande ls | grep c$ dans le fichier liste_fichiers.txt

    // Ouverture du fichier liste_fichiers.txt en mode lecture
    FILE *fichier = fopen("liste_fichiers.txt", "r");
    if (fichier == NULL)
    {                                                    // si le fichier n'existe pas
        perror("Erreur lors de l'ouverture du fichier"); // affiche le message d'erreur
        return 1;                                        // quitte le programme
    }

    // Lecture des noms des fichiers dans le fichier liste_fichiers.txt
    int i = 0;
    while (fgets(nom_fichier[i], sizeof(nom_fichier[i]), fichier) != NULL)
    {                                                      // tant qu'il y a des lignes a lire
        nom_fichier[i][strlen(nom_fichier[i]) - 1] = '\0'; // on remplace le dernier caractère de la chaine de caractère par le caractère de fin de chaine
        printf("%s\n", nom_fichier[i]);                    // affiche la ligne
    }
    printf("\n");
    fclose(fichier);                 // ferme le fichier
    system("rm liste_fichiers.txt"); // Suppression du fichier liste_fichiers.txt

    // Demande à l'utilisateur de choisir un fichier
    printf("Entrez le nom du fichier à compiler et à exécuter (sans l'extension.c): ");
    scanf("%s", nom_fichier[i]);

    if (strcmp(nom_fichier[i], "liste") != 0)
    { // Si le fichier à compiler est liste.c on execute le code suivant

        // Compilation du fichier
        char compilation[100] = "gcc -Wextra -Wall -o ";
        strcat(compilation, nom_fichier[i]);
        strcat(compilation, " ");
        strcat(compilation, nom_fichier[i]);
        strcat(compilation, ".c");

        printf("Compilation de %s.c ...\n\n", nom_fichier[i]);
        system(compilation);

        // Execution du fichier
        char execution[100] = "./";
        strcat(execution, nom_fichier[i]);

        // Si le fichier à executer est calcule.c on demande à l'utilisateur de saisir les arguments
        if (strcmp(nom_fichier[i], "calcule") == 0)
        {
            printf("Entrez les arguments à passer au programme (séparés par un espace sous la forme: 'op' nb1 nb2\n): ");
            char arguments[100];
            scanf(" %[^\n]s", arguments);
            strcat(execution, " ");
            strcat(execution, arguments);
        }

        printf("Execution de %s ...\n\n", nom_fichier[i]);
        system(execution);
    }

    else
    {
        /////////////////////////////////////////////////////////////
        // EXERCICE 7 COULEURS

        // Création d'une liste de 10 couleurs en utilisant la structure couleur
        struct couleur couleurs[] = {
            {0xFF, 0x00, 0x00, 0xFF},
            {0x00, 0xFF, 0x00, 0xFF},
            {0x00, 0x00, 0xFF, 0xFF},
            {0xFF, 0xFF, 0x00, 0xFF},
            {0xFF, 0x00, 0xFF, 0xFF},
            {0x00, 0xFF, 0xFF, 0xFF},
            {0xFF, 0xFF, 0xFF, 0xFF},
            {0xFF, 0xFF, 0x00, 0xFF},
            {0xF0, 0x00, 0xFF, 0xFF},
            {0x00, 0xFF, 0xFF, 0xFF}
         };

        // Initialisation de la liste de couleurs
        struct liste_couleurs ma_liste;
        init_liste(&ma_liste);

        // Insertion des couleurs dans la liste
        for (int i = 0; i < 10; i++) {
            insertion(&couleurs[i], &ma_liste);
        }

        // Affichage de la liste des couleurs
        printf("Liste des couleurs :\n");
        parcours(&ma_liste);

        // FIN EXERCICE 7 COULEURS
        //////////////////////////////////////////////////////////////////
    }

    return 0; // Fin du programme
}
