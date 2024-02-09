/*
 * fichier octets.c
 * But: afficher les octets individuels de différentes variables de types de données
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI YOUNESS
 */

#include <stdio.h> //header

int main()
{

    // Déclaration des variables de chaque type de données
    short entier_court;
    int entier;
    long int entier_long;
    float flottant;
    double double_flottant;
    long double double_flottant_long;
    char caractere;

    // Initialisation des variables avec des valeurs
    entier_court = 1;
    entier = 123456;
    entier_long = 12345678999;
    flottant = 12.34;
    double_flottant = 56.789;
    double_flottant_long = 78.91011;
    caractere = 'A';

    // Affichage des octets de chaque variable  (en hexadécimal)
    printf("Octets de short :\n");
    printf(" %02hhx %02hhx\n\n", ((char *)&entier_court)[0], ((char *)&entier_court)[1]);
    printf("Octets de int :\n");
    printf("%02hhx %02hhx %02hhx %02hhx\n\n", ((char *)&entier)[0], ((char *)&entier)[1], ((char *)&entier)[2], ((char *)&entier)[3]);
    printf("Octets de long int :\n");
    printf("%02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx\n\n", ((char *)&entier_long)[0], ((char *)&entier_long)[1], ((char *)&entier_long)[2], ((char *)&entier_long)[3], ((char *)&entier_long)[4], ((char *)&entier_long)[5], ((char *)&entier_long)[6], ((char *)&entier_long)[7]);

    printf("Octets de float : \n");
    size_t taille_float = sizeof(float);
    for (size_t i = 0; i < taille_float; i++)
        printf("%02hhx ", ((char *)&flottant)[i]);
    printf("\n\n");

    printf("Octets de double :\n");
    size_t taille_double = sizeof(double);
    for (size_t i = 0; i < taille_double; i++)
        printf("%02hhx ", ((char *)&double_flottant)[i]);
    printf("\n\n");

    printf("Octets de long double : \n");
    size_t taille_long_double = sizeof(long double);
    for (size_t i = 0; i < taille_long_double; i++)
        printf("%02hhx ", ((char *)&double_flottant_long)[i]);
    printf("\n\n");

    printf("Octet de char :\n");
    printf("%02hhx", ((char *)&caractere)[0]);
    printf("\n\n");

    return 0; // fin du programme
}
