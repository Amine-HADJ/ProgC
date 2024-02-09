/* Fichier: opérateurs.c
* but : calcul l'opération choisie par l'utilisateur en entrée.
* auteur: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
*/


#include <stdio.h> // headers
#include <stdbool.h> // pour le type booléen

int main() {
    int a = 16; // Déclaration des variables
    int b = 3;

    printf("a = %d, b = %d\n", a, b); // Affichage des variables

    // Déclaration des opérations arithmétiques
    int addition = a + b; 
    int soustraction = a - b;
    int multiplication = a * b;
    float division = (b != 0) ? (float)a / b : 0; // Si b est différent de 0, on effectue la division, sinon on retourne 0
    int modulo = (b != 0) ? a % b : 0; // Si b est différent de 0, on effectue le modulo, sinon on retourne 0

    // Affichage des résultats
    printf("Addition: %d\n", addition);
    printf("Soustraction: %d\n", soustraction);
    printf("Multiplication: %d\n", multiplication);

    if (b != 0) { // Si b est différent de 0

        printf("Division: %f\n", division); // Affichage de la division
        printf("Modulo: %d\n", modulo); // Affichage du modulo

    } else { // Sinon

        printf("Division par zéro n'est pas autorisée.\n"); // Affichage du message d'erreur
        printf("Modulo par zéro n'est pas autorisé.\n");    // Affichage du message d'erreur

    }

    // Comparaisons
    bool is_equal = (a == b); // Déclaration des variables booléennes
    bool is_greater = (a > b); 

    printf("a est égal à b : %s\n", is_equal ? "true" : "false"); 
    printf("a est supérieur à b : %s\n", is_greater ? "true" : "false");

    return 0; // Fin du programme
}
