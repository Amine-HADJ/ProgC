/*
 * fichier: liste.c
 * but: definir les fonctions de liste.h
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI EL ALAOUI YOUNESS
 */

#include "liste.h"
#include <stdlib.h>

void init_liste(liste_couleurs *l) // initialisation de la liste à NULL (vide)
{   // en c "->" sert à accéder aux champs d'une structure à travers un pointeur (en python ".")
    l->tete = NULL; // la tete de la liste est NULL (vide)
}

// en c un maillon est un pointeur vers une structure maillon qui contient un pointeur vers une structure couleur
void insertion(couleur *c, liste_couleurs *l) // insertion d'un maillon dans la liste (au début)
{
    maillon *nouveau_maillon = (maillon *)malloc(sizeof(maillon)); // allocation dynamique de la mémoire pour le nouveau maillon
    nouveau_maillon->c = c;                                        // le champ c du nouveau maillon pointe vers la couleur c
    nouveau_maillon->suivant = l->tete;                           // le champ suivant du nouveau maillon pointe vers l'ancienne tete de la liste
    l->tete = nouveau_maillon;                                   // la tete de la liste pointe vers le nouveau maillon
}

void parcours(liste_couleurs *l) // parcours de la liste
{
    maillon *courant = l->tete; // le maillon courant pointe vers la tete de la liste
    while (courant != NULL)    // tant que le maillon courant n'est pas NULL (fin de la liste)
    {                         // on affiche les valeurs des champs de la couleur du maillon courant
        printf("R: %d, G: %d, B: %d, A: %d\n", courant->c->R, courant->c->G, courant->c->B, courant->c->A);
        courant = courant->suivant;
    }
}