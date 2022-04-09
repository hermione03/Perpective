#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fonctions.h"



void lecture(FILE *fichier, int grille[TMAX][TMAX], int n)
{
    int i = 0;
    char grille_temporaire[n][n];

    char max_g = n * n;

    while (fgets(grille_temporaire[i], max_g, fichier))
    {
        i++;
    }

    for (int y = 1; y <= n; y++)
    {
        for (int i = 0; i < n; i++)
        {
            if (grille_temporaire[y][i] == 'X' || grille_temporaire[y][i] == ' ')
            {
                grille[y][i] = 0;
            }
            else if (grille_temporaire[y][i] >= '1')
            {
                grille[y][i] = grille_temporaire[y][i] - '0';
            }
            else
            {
                grille[y][i] = ' ';
            }
        }
    }
}

void affichage(int grille[TMAX][TMAX], int n){
    for (int ligne = 1; ligne <= n; ligne++)
    {
        for (int col = 0; col < n; col++)
        {
            printf("%d ", grille[ligne][col]);
        }
        printf("\n");
    }
}
