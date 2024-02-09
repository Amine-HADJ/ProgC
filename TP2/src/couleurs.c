/* Fichier: couleurs.c
* but: représenter des couleurs au format RGBA en utilisant les structures
* auteurs: HADJ-HAMDRI MOHAMMED-AMINE / ELTAHIRI YOUNESS
*/




#include <stdio.h> //headers
#include <stdlib.h> //pour acceder à la fontion rand()
#include <time.h> //pour acceder à la fontion time()



//Structure pour représenter la couleur RGBA

typedef struct { 
    unsigned char rouge; // unsigned char pour représenter les valeurs de 0 à 255
    unsigned char bleu;
    unsigned char vert;
    unsigned char alpha;
}Couleur;


int main(){

   srand(time(NULL)); //initialisation de la fonction rand()

    // tableau de la structure pour stocker 10 couleurs
    Couleur couleurs[10];

    // intialisation des premières composantes
    couleurs[0] = (Couleur){.rouge = 0xEF, .vert = 0x78, .bleu = 0x12, .alpha = 0xFF};

    // initialisation des 9 autres couleurs aléatoirement sous forme hexadécimale
    for (int i = 1; i < 10; i++){
        couleurs[i] = (Couleur){.rouge = rand() % 256, .vert = rand() % 256, .bleu = rand() % 256, .alpha = rand() % 256};
    }

   
    // affichage des couleurs 
    for (int i = 0; i < 10; i++){ 

        printf("Couleur %d :\n", i + 1);
        printf("Rouge : %d\n", couleurs[i].rouge);
        printf("Vert : %d\n", couleurs[i].vert);
        printf("Bleu : %d\n", couleurs[i].bleu);
        printf("Alpha : %d\n", couleurs[i].alpha);
        printf("\n");
    }
    
 

    return 0; // fin du programme
}