/*
 * fichier : liste.h
 * but: definir les structures et implementer les fonctions
 * auteurs: HADJ-HAMDRI MOHAMMED-AMINE / TAHIRI EL ALAOUI YOUNESS
 */

// headers
#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>

typedef struct couleur
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
} couleur;

typedef struct maillon
{
    couleur *c;
    struct maillon *suivant;
} maillon;

typedef struct liste_couleurs
{
    maillon *tete;
} liste_couleurs;

void init_liste(liste_couleurs *l);
void insertion(couleur *c, liste_couleurs *l);
void parcours(liste_couleurs *l);

#endif // LISTE_H
