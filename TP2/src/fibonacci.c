/* Fichier: fibonacci.c
 * but: Afficher les n premiers termes de la suite de Fibonacci
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
*/


#include <stdio.h> // headers

int main(){
   
    // Déclaration des variables
    int U0 = 0; // premiers termes de la suite
    int U1 = 1;     
    int n; // nombre de termes à afficher

    printf("Entrez un entier n: "); // Demande à l'utilisateur d'entrer un entier n
    scanf("%d", &n); // Lecture de l'entier n

    printf("%d %d ", U0, U1); // afficher les deux premiers termes de la suite

    for (int i = 2; i < n; i++){
        int Un = U0 + U1; // calcul du terme suivant de la suite
        printf("%d ", Un); // affichage du terme suivant de la suite
        U0 = U1; // mise à jour des deux premiers termes de la suite
        U1 = Un;
    }

    printf("\n"); 

    return 0; // Fin du programme
}