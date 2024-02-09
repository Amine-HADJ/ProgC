/* Fichier: cercle.c
 * but : calcul l'aire et le périmètre d'un cercle de rayon donné en entrée
 * auteur: HADJ-HAMDRI MOHAMMED-AMINE / EL TAHIRI YOUNESS
 */

#include <stdio.h> // headers
#include <math.h> // pour la constante M_PI

int main()
{
   float rayon;

   printf("Entrez le rayon du cercle : "); // Demande à l'utilisateur d'entrer le rayon du cercle
   scanf("%f", &rayon);                    // Lecture du rayon du cercle

   float aire = M_PI * rayon * rayon;  // Calcul de l'aire du cercle
   float perimetre = 2 * M_PI * rayon; // Calcul du périmètre du cercle

   printf("L'aire du cercle est %f\n", aire);            // Affichage de l'aire du cercle
   printf("Le périmètre du cercle est %f\n", perimetre); // Affichage du périmètre du cercle

   return 0; // Fin du programme
}
