/* Fichier: binaire.c
 * affiche: la représentation binaire d'un entier.
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
 */

#include <stdio.h> // headers


int main()
{
    int nombre; // Déclaration de la variable nombre

    printf("Entrez un entier : "); // Demande à l'utilisateur d'entrer un entier
    scanf("%d", &nombre);          // Lecture de l'entier

    printf("Représentation binaire de %d : ", nombre);

    int bits = sizeof(nombre) * 8; // Détermine le nombre de bits du nombre entier (sizeof() retourne la taille en octets du type de donnée passé en paramètre)

    // Boucle pour chaque bit, de gauche à droite
    for (int i = bits - 1; i >= 0; i--)
    {
        int bit = (nombre >> i) & 1; // Obtient le i-ème bit de droite à gauche
        printf("%d", bit);           // Affiche le bit
    }

    return 0; // Fin du programme
}
