/*
 * fichier: chercher2.c
 * but: Chercher une phrase dans un tableau de phrases
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI YOUNESS
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char phrases[10][100] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."};

    // Saisie de la phrase à chercher
    char phrase_a_chercher[100];
    printf("Entrez la phrase à chercher: ");
    fgets(phrase_a_chercher, 100, stdin);
    phrase_a_chercher[strcspn(phrase_a_chercher, "\n")] = '\0'; // Retirer le \n de la fin de la phrase saisie

    // Recherche de la phrase dans le tableau
    int trouve = 0;         // Variable booléenne pour savoir si la phrase est trouvée ou non
    int numero_phrase = -1; // Variable pour stocker le numéro de la phrase trouvée

    for (int i = 0; i < 10; i++)
    {
        int j = 0;
        while (phrases[i][j] != '\0' && phrase_a_chercher[j] != '\0' && phrases[i][j] == phrase_a_chercher[j])
        {
            j++;
        }

        if (phrases[i][j] == '\0' && phrase_a_chercher[j] == '\0')
        {
            trouve = 1; 
            numero_phrase = i + 1; // On incrémente i car les indices commencent à 0
            break;                 // On sort de la boucle for car la phrase est trouvée
        }
    }

    // Affichage du résultat
    if (trouve == 1)
    {
        printf("Phrase trouvée, c'est la phrase %d\n", numero_phrase);
    }
    else
    {
        printf("Phrase non trouvée.\n");
    }

    return 0; // Fin du programme
}
