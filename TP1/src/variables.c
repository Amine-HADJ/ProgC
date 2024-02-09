/* Fichier: variables.c
 * affiche: les valeurs des variables affectées des différents types de base. (signed and unsigned)
 * auteur: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
 */

#include <stdio.h> // headers

int main()
{
    // Variables signées
    char signed_char = 'A';
    short signed_short = -1234;
    int signed_int = 123456;
    long int signed_long = -1234567890;
    long long int signed_long_long = 9876543210;

    // Variables non signées
    unsigned char unsigned_char = 200;
    unsigned short unsigned_short = 56789;
    unsigned int unsigned_int = 4294967295;                              // 10 chiffres, valeur maximale pour unsigned int
    unsigned long int unsigned_long = 1234567890UL;                      // 'UL' pour spécifier le type
    unsigned long long int unsigned_long_long = 18446744073709551615ULL; // 'ULL' pour spécifier le type

    // Variables à virgule flottante
    float float_var = 1.5;
    double double_var = 1.23456789;
    long double long_double_var = 1.234567891219999991L; // 'L' pour spécifier le type

    // Affichage des valeurs des variables de différents types
    printf("Valeurs des variables de différents types :\n");
    printf("signed char : %c\n", signed_char);
    printf("signed short : %d\n", signed_short);
    printf("signed int : %d\n", signed_int);
    printf("signed long : %ld\n", signed_long);
    printf("signed long long : %lld\n", signed_long_long);
    printf("\n");
    printf("unsigned char : %u\n", unsigned_char);
    printf("unsigned short : %u\n", unsigned_short);
    printf("unsigned int : %u\n", unsigned_int);
    printf("unsigned long : %lu\n", unsigned_long);
    printf("unsigned long long : %llu\n", unsigned_long_long);
    printf("\n");
    printf("float : %f\n", float_var);
    printf("double : %lf\n", double_var);
    printf("long double : %Lf\n", long_double_var);

    return 0; // fin du programme
}
