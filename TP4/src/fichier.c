/*
* fichier: fichier.c
* but: fichier "fils" qui va lire et écrire dans un fichier
*
*/

#include <stdio.h> // headers
#include "fichier.h"


int main(){


    

    char nom_fichier[100];
    char message[1000];
    int choix;

    printf("Entrez le nom du fichier à lire et modifier (avec extention): ");
    scanf("%s", nom_fichier);


    // Demande à l'utilisateur de choisir s'il veut lire ou écrire dans un fichier
    
    printf("Que voulez-vous faire:\n 1. lire le fichier \n 2. écrire dans le fichier \n 3. lire et modifier \n");
    scanf("%d", &choix);

    if (choix == 1){
        lire_fichier(nom_fichier);
    }
    else if (choix == 2){
        

        printf("Entrez le message à ecrire dans le fichier %s: ", nom_fichier);
        scanf(" %[^\n]s", message);

        ecrire_dans_fichier(nom_fichier, message);

        // test si le message a bien été écrit dans le fichier
        lire_fichier(nom_fichier);
    }
    else if (choix == 3){
        
        lire_fichier(nom_fichier);
        printf("Entrez le message à ecrire dans le fichier %s: ", nom_fichier);
        scanf(" %[^\n]s", message);

        ecrire_dans_fichier(nom_fichier, message);

        // test si le message a bien été écrit dans le fichier
        lire_fichier(nom_fichier);
    }
        
    else{
        printf("Choix invalide !\n");
        return 1;
    }

    


    


    printf("Opération(s) réalisée(s) avec succès !\n");



    return 0; // Fin du programme
}