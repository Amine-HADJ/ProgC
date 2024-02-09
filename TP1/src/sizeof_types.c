/* Fichier: sizeof_types.c
 * affiche : la taille en octets des différents types de base (signed and unsigned)
 * auteur: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
 */

#include <stdio.h> // headers

int main()
{

    printf("Taille en octets des types de données :\n");

    // sizeof() retourne la taille en octets du type de donnée passé en paramètre

    printf("1.  char: %lu octets\n", sizeof(char));

    printf("2.  short: %lu octets\n", sizeof(short));

    printf("3.  int: %lu octets\n", sizeof(int));

    printf("4.  long int: %lu octets\n", sizeof(long int));

    printf("5.  long long int: %lu octets\n", sizeof(long long int));

    printf("6.  float: %lu octets\n", sizeof(float));

    printf("7.  double: %lu octets\n", sizeof(double));

    printf("8.  long double: %lu octets\n", sizeof(long double));

    return 0; // fin du programme
}
