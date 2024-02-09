/* Fichier: etudiant2.c
 * but: représenter les informations des étudiants en utilisant les structures
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / ELTAHIRI YOUNESS
 */

#include <stdio.h>  //headers
#include <string.h> //pour acceder à la fontion strlen()

typedef struct
{ // Structure pour représenter un étudiant
    char nom[100];
    char prenom[100];
    char adresse[200];
    float note_programmation;
    float note_systeme;
} Etudiant;

int main()
{
    Etudiant etudiants[5]; // Tableau de 5 étudiants de la structure Etudiant

    // Saisie des informations pour chaque étudiant
    for (int i = 0; i < 5; i++)
    {
        printf("Saisie des informations pour l'etudiant %d :\n", i + 1);

        // Saisie du nom et prénom
        printf("Nom: ");
        fgets(etudiants[i].nom, 100, stdin); // fgets pour lire la chaîne avec espaces

        printf("Prénom: ");
        fgets(etudiants[i].prenom, 100, stdin);

        printf("Adresse: ");
        fgets(etudiants[i].adresse, 200, stdin);

        printf("Note en programmation: ");
        scanf("%f", &etudiants[i].note_programmation);
        getchar();

        printf("Note en systeme d'exploitation: ");
        scanf("%f", &etudiants[i].note_systeme);
        getchar();

        printf("\n");
    }

    // Affichage des informations des étudiants
    for (int i = 0; i < 5; i++)
    {
        printf("Etudiant %d :\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prénom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);
        printf("Note 1 : %.1f\n", etudiants[i].note_programmation);
        printf("Note 2 : %.1f\n", etudiants[i].note_systeme);
        printf("\n");
    }

    return 0; // Fin du programme
}
