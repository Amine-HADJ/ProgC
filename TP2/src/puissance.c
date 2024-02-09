/* Fichier: puissance.c
* but: Calculer la puissance d'un entier
* auteurs: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
*/

#include <stdio.h> // headers

int main(){

    // Déclaration des variables
    int a = 2;
    int b = 3;
    int result = 1;


    printf("a = %d et b = %d\n", a, b); // Affiche les valeurs de a et b

    for(int i = 0; i < b; i++){ // Boucle for qui multiplie a par lui-même b fois
        
        if(b == 0){ // Si b = 0, le résultat est 1
            result = 1;
        }
        else{ // Sinon, on multiplie a par lui-même b fois
            result = result * a;
        }
        
     
    }

    // Affichage le résultat
    printf("Le résulat de a^(b) est: %d\n", result);
    

    return 0; // Fin du programme

}