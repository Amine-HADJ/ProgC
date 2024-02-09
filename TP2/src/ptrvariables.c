/* Fichier: ptrvariables.c
 * but : Manipuler les variables à l'aide des pointeurs
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
 */

#include <stdio.h> // Headers

int main()
{

    // Variables de différents types

    char c = 'A';
    short s = 12;
    int i = 987654;
    long int li = 12345678L;
    long long int lli = 1234567890LL;
    float f = 3.14;
    double d = 2.71828;
    long double ld = 1.61803398875L;

    // Affichage des adresses et valeurs avant la manipulation
    printf("Avant la manipulation :\n");
    printf("Adresse de c : %p, Valeur de c : %c\n", (char *)&c, c);
    printf("Adresse de s : %p, Valeur de s : %d\n", (char *)&s, s);
    printf("Adresse de i : %p, Valeur de i : %d\n", (char *)&i, i);
    printf("Adresse de li : %p, Valeur de li : %ld\n", (char *)&li, li);
    printf("Adresse de lli : %p, Valeur de lli : %lld\n", (char *)&lli, lli);
    printf("Adresse de f : %p, Valeur de f : %f\n", (char *)&f, f);
    printf("Adresse de d : %p, Valeur de d : %lf\n", (char *)&d, d);
    printf("Adresse de ld : %p, Valeur de ld : %Lf\n", (char *)&ld, ld);

    // Manipulation des variables à l'aide de pointeurs
    char *ptr_c = &c;
    short *ptr_s = &s;
    int *ptr_i = &i;
    long int *ptr_li = &li;
    long long int *ptr_lli = &lli;
    float *ptr_f = &f;
    double *ptr_d = &d;
    long double *ptr_ld = &ld;

    // Modifier les valeurs via les pointeurs
    *ptr_c = 'B';
    *ptr_s = 543;
    *ptr_i = 12345678;
    *ptr_li = 987654321;
    *ptr_lli = 98765432109876543LL;
    *ptr_f = 2.718;
    *ptr_d = 3.14159;
    *ptr_ld = 2.718281828459;

    // Affichage des adresses et valeurs après la manipulation
    printf("\nAprès la manipulation :\n");
    printf("Adresse de c : %p, Valeur de c : %c\n", (char *)&c, c);
    printf("Adresse de s : %p, Valeur de s : %d\n", (char *)&s, s);
    printf("Adresse de i : %p, Valeur de i : %d\n", (char *)&i, i);
    printf("Adresse de li : %p, Valeur de li : %ld\n", (char *)&li, li);
    printf("Adresse de lli : %p, Valeur de lli : %lld\n", (char *)&lli, lli);
    printf("Adresse de f : %p, Valeur de f : %f\n", (char *)&f, f);
    printf("Adresse de d : %p, Valeur de d : %lf\n", (char *)&d, d);
    printf("Adresse de ld : %p, Valeur de ld : %Lf\n", (char *)&ld, ld);

    return 0; // Fin du programme
}
