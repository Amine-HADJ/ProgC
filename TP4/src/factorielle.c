/*
 * fichier: factorielle.c
 * but: calculer la factorielle d'un entier naturel de maniere recursive
 * auteur: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI EL ALAOUI YOUNESS
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Définition de la fonction factorielle
int factorielle(int num)
{
    if (num == 0)
    {
        printf("fact(0): 1\n");
        return 1;
    }
    else
    {
        int valeur = num * factorielle(num - 1);
        printf("fact(%d): %d\n", num, valeur);
        return (valeur);
    }
}

int main()
{

    // Teste de la fonction factorielle avec différentes valeurs d'entiers naturels (1, 5, 10, 15, 20)
    factorielle(0);
    factorielle(5);

    // Verification des résultats grace à <math.h>
    printf("Vérification des résultats avec <math.h> et sa fonction tgamma(n+1) :\n");
    printf("fact(0): %d\n", (int)tgamma(1));
    printf("fact(5): %d\n", (int)tgamma(6));

    return 0; // Fin du programme
}
