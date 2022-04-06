#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fonctions.h"

int main()
{

    FILE *fichier = NULL;
    int grille[TMAX][TMAX];

    fichier = fopen("./Perspective2.txt", "r");

    if (fichier == NULL)
        exit(1);

    char n1 = getc(fichier);
    int n = n1 - '0';

    n = n + 2;
    lecture(fichier, grille, n);
    affichage(grille, n);

    return 0;
}