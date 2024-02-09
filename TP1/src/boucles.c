/* Fichier: boucles.c
 * but: afficher un triangle rectangle composé de '*' et '#' en utilisant des boucles for et while.
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
 */

// #include <stdio.h> // headers

// //BOUCLE FOR
// int main() {
//     int compteur; // Déclaration de la variable compteur
//     printf("Entrez la valeur du compteur (strictement inférieure à 10) : "); // Demande à l'utilisateur d'entrer la valeur du compteur
//     scanf("%d", &compteur); // Lecture de la valeur du compteur

//     if (compteur >= 10) { // Si la valeur du compteur est supérieure ou égale à 10
//         printf("La valeur du compteur doit être strictement inférieure à 10.\n"); // Affichage du message d'erreur
//         return 1; // Fin du programme
//     }

//     // Affichage du triangle rectangle
//     for (int i = 1; i <= compteur; i++) { // Boucle pour chaque ligne
//         for (int j = 1; j <= i; j++) { // Boucle pour chaque colonne
//             if (j == 1 || j == i || i == compteur) // Si on est sur le bord gauche, le bord droit ou la dernière ligne
//                 printf("* "); // Affichage de '*'
//             else
//                 printf("# "); // Affichage de '#'
//         }
//         printf("\n");
//     }

//     return 0; // Fin du programme
// }

// BOUCLE WHILE

#include <stdio.h> // headers

int main()
{
    int compteur;                                                            // Déclaration de la variable compteur
    printf("Entrez la valeur du compteur (strictement inférieure à 10) : "); // Demande à l'utilisateur d'entrer la valeur du compteur
    scanf("%d", &compteur);

    if (compteur >= 10)
    {                                                                             // Si la valeur du compteur est supérieure ou égale à 10
        printf("La valeur du compteur doit être strictement inférieure à 10.\n"); // Affichage du message d'erreur
        return 1;                                                                 // Fin du programme
    }

    int i = 1;
    while (i <= compteur)
    {
        int j = 1;
        while (j <= i)
        {
            if (j == 1 || j == i || i == compteur)
                printf("* ");
            else
                printf("# ");
            j++;
        }
        printf("\n");
        i++;
    }

    return 0; // Fin du programme
}
