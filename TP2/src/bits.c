#include <stdio.h>

int main() {
    unsigned int d;
    printf("Entrez un entier : ");
    scanf("%d", &d);

    int len_d = sizeof(d) * 8; // Nombre de bits de d



    // Masque pour isoler le 4ème bit de gauche
    int masque_4b = 1 << (len_d - 3);

    // Masque pour isoler le 20ème bit de gauche
    int masque_20b = 1 << (len_d - 19);

    // Extraction des bits
    int bit_4 = (d & masque_4b) ? 1 : 0; // Si le bit est à 1, alors le résultat est 1, sinon 0
    int bit_20 = (d & masque_20b) ? 1 : 0; // Si le bit est à 1, alors le résultat est 1, sinon 0  

    // Vérification et affichage du résultat
    if (bit_4 == 1 && bit_20 == 1) { // Si les deux bits sont égaux à 1
        printf("Les 4ème et 20ème bits de gauche sont tous les deux 1.\n");
        printf("Résultat : 1\n");
    } else { // Sinon
        printf("Au moins un des bits n'est pas égal à 1.\n");
        printf("Résultat : 0\n");
    }

    return 0; // Fin du programme
}
