/*
 * fichier: chercherfichier.c
 * but: chercher une phrase dans un fichier donné
 * auteur: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI EL ALAOUI YOUNESS
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nom_fichier[100];
    char phrase_a_chercher[100];

    // Demande à l'utilisateur de saisir le nom du fichier
    printf("Entrez le nom du fichier à ouvrir: ");
    scanf("%s", nom_fichier);

    // Demande à l'utilisateur de saisir la phrase à chercher
    printf("Entrez la phrase à chercher: ");
    getchar(); // Consume the newline character left by previous scanf
    fgets(phrase_a_chercher, sizeof(phrase_a_chercher), stdin);
    phrase_a_chercher[strcspn(phrase_a_chercher, "\n")] = '\0'; // Retirer le \n de la fin de la phrase saisie

    // Ouvrir le fichier en mode lecture
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    int nb_ligne = 0;

    // Lire le fichier ligne par ligne et chercher la phrase
    char ligne[200];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) // fgets retourne NULL si on arrive à la fin du fichier
    {
        nb_ligne++;
        int taille_ph = strlen(phrase_a_chercher) - 1; // Retirer le \n de la phrase
        int occurrences = 0;

        // on parcourt chaque ligne
        for (int i = 0; i < 200; i++)
        {
            // on parcourt chaque caractère de la ligne
            if (ligne[i] == phrase_a_chercher[0])
            {
                // on vérifie si le caractère est le premier de la phrase
                int j = 0;
                while (j < taille_ph && ligne[i + j] == phrase_a_chercher[j])
                {
                    // on vérifie si les caractères suivants sont les mêmes que ceux de la phrase
                    j++;
                }
                if (j == taille_ph)
                {
                    // si on a trouvé la phrase, on incrémente le nombre d'occurrences
                    occurrences++;
                }
            }
        }

        // Affichage le résultat
        if (occurrences > 0)
        {
            printf("La phrase \"%s\" a été trouvée %d fois dans la ligne %d\n", phrase_a_chercher, occurrences, nb_ligne);
        }
    }

    // Fermer le fichier
    fclose(fichier);

    return 0;
}
