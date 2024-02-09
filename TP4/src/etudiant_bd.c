/*
* fichier: etudiant_bd.c
* but: relever les informations de 5 étudiants et les stocker dans un fichier "etudiant.txt"
* auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI YOUNESS
*/



#include <stdio.h> //headers 
#include <stdlib.h> 
#include <string.h> 


typedef struct
{ // structure pour stocker les informations des étudiants
    char nom[100];
    char prenom[100];
    char adresse[100];
    int note_programmation;
    int note_systeme;
} Etudiant;


int main(){

    // Déclaration des variables
    Etudiant etudiants[5]; // tableau de 5 étudiants

    
    //Demande à l'utilisateur de saisir les informations des étudiants
    printf("Entrez les informations des étudiants: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Etudiant %d: \n", i+1);

        printf("Nom: ");
        fgets(etudiants[i].nom, 100, stdin);

        printf("Prenom: ");
        fgets(etudiants[i].prenom, 100, stdin);

        printf("Adresse: ");
        fgets(etudiants[i].adresse, 200, stdin);

        printf("Note 1: ");
        scanf("%d", &etudiants[i].note_programmation);
        getchar();

        printf("Note 2: ");
        scanf("%d", &etudiants[i].note_systeme);
        getchar();

        printf("\n");
    }

    //Stockage des infos dans un fichier "etudiant.txt"

    system("touch fichier.txt"); //Création fichier 
    
    FILE *fichier = fopen("etudiant.txt", "w");
    if (fichier == NULL) { // si le fichier n'existe pas
        perror("Erreur lors de l'ouverture du fichier"); // affiche le message d'erreur
        return 1; // quitte le programme
    }

    for (int i = 0; i < 5; i++)
    {
        fprintf(fichier, "Etudiant %d: \n", i+1);

        fprintf(fichier, "Nom: %s", etudiants[i].nom);

        fprintf(fichier, "Prenom: %s", etudiants[i].prenom);

        fprintf(fichier, "Adresse: %s", etudiants[i].adresse);

        fprintf(fichier, "Note programmation: %d\n", etudiants[i].note_programmation);

        fprintf(fichier, "Note systeme: %d\n", etudiants[i].note_systeme);

        fprintf(fichier, "\n\n");
    }

    fclose(fichier); // ferme le fichier

    printf("Les informations des étudiants ont été stockées dans le fichier etudiant.txt\n");



    return 0; // Fin du programme
}