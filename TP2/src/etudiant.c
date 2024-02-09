/*
* fichier: etudiant.c
* but: représenter les informations des étudiants en utilisant les tableaux
* auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI YOUNESS
*/


#include <stdio.h>

int main()
{
    // Déclaration des tableaux pour stocker les informations des étudiants
    char noms_prenoms[5][100];
    char adresses[5][200];
    float notes_programmation[5];
    float notes_systeme[5];

    // Remplissage des tableaux avec les informations des étudiants
    for (int i = 0; i < 5; i++)
    {
        printf("Etudiant %d:\n", i + 1);

        printf("Nom et prenom: ");
        fgets(noms_prenoms[i], 100, stdin); // fgets pour lire la chaîne avec espaces

        printf("Adresse: ");
        fgets(adresses[i], 200, stdin);

        printf("Note en programmation: ");
        scanf("%f", &notes_programmation[i]);
        getchar();

        printf("Note en systeme d'exploitation: ");
        scanf("%f", &notes_systeme[i]);
        getchar();

        printf("\n");
    }

    // Affichage des informations des étudiants
    printf("Informations des etudiants :\n");
    for (int i = 0; i < 5; i++)
    { // Boucle for pour parcourir les tableaux
        printf("Etudiant %d:\n", i + 1);

        printf("Nom et prenom: %s\n", noms_prenoms[i]);

        printf("Adresse: %s\n", adresses[i]);

        printf("Note en programmation: %.1f\n", notes_programmation[i]);

        printf("Note en systeme d'exploitation: %.1f\n", notes_systeme[i]);

        printf("\n");
    }

    return 0; // Fin du programme
}
