/* Fichier: chaine.c
 * but: Concaténer deux chaînes de caractères et compter leurs longueurs
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
*/



#include <stdio.h> // headers

int main() {
    char chaine1[100], chaine2[100], chaine_conca[200];  // Déclaration des chaînes de caractères

    printf("Entrez une chaîne de caractères : "); // Demander à l'utilisateur d'entrer une chaîne de caractères
    
    fgets(chaine1, 100, stdin); // fgets permet de lire une chaîne de caractères avec des espaces contrairement à scanf

    printf("Entrez une autre chaîne de caractères : "); // Demander à l'utilisateur d'entrer une autre chaîne de caractères
    fgets(chaine2, 100, stdin); 

    int len1 = 0, len2 = 0; // Longueurs des chaînes initialisées à 0

   // Calcul de la longueur de la chaîne 1
    while (chaine1[len1] != '\n') {
        len1++;
    }

    // Calcul de la longueur de la chaîne 2
    while (chaine2[len2] != '\n') {
        len2++;
    }

    // Concaténation des 2 chaînes
    int i = 0;
    while (chaine1[i] != '\n') {
        chaine_conca[i] = chaine1[i];
        i++;
    }

    int j = 0;
    while (chaine2[j] != '\n' ) {
        chaine_conca[i] = chaine2[j];
        i++;
        j++;
    }

    int len_conca = i;
    
    // Affichage des longueurs des chaines
    printf("La longueur de la première chaîne est : %d\n", len1);
    printf("La longueur de la deuxième chaîne est : %d\n", len2);
    printf("La longueur de la chaîne concaténée est : %d\n", len_conca);

    // Affichage de la chaîne concaténée
    printf("La chaîne concaténée est : %s\n", chaine_conca);
    

    


    return 0; // Fin du programme
}
