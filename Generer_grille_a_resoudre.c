#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TMAX 12

bool exists_in_row(int k, int grille[TMAX][TMAX], int i, int n)
{
    for (int j = 0; j < n; j++)
        if (grille[i][j] == k)
            return true;
    return false;
}

bool existes_in_(int k, int grille[TMAX][TMAX], int j, int n)
{
    for (int i = 0; i < n; i++)
        if (grille[i][j] == k)
            return true;
    return false;
}

void cache_milieu(int grille[TMAX][TMAX], int n)
{
    int i, j;

    for (i = 2; i < n; i++)
    {

        for (j = 1; j < n-1; j++)
        {
            grille[i][j] = 0;
        }
    }
}
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

            if (grille_temporaire[y][i] >= '1')
            {
                grille[y][i] = grille_temporaire[y][i] - '0';
            }
            else if (grille_temporaire[y][i] == ' ')
            {
                grille[y][i] = -1;
            }
        }
    }
}

void affichage(int grille[TMAX][TMAX], int n)
{
    for (int ligne = 1; ligne <= n; ligne++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grille[ligne][col] == -1)
            {
                printf("%c ", ' ');
            }
            else
            {
                printf("%d ", grille[ligne][col]);
            }
        }
        printf("\n");
    }
}

int main()
{

    FILE *fichier = NULL;
    int grille[TMAX][TMAX];

    fichier = fopen("./Perspective.txt", "r");

    if (fichier == NULL)
        exit(1);

    char n1 = getc(fichier);
    int n = n1 - '0';

    n = n + 2;

    lecture(fichier, grille, n);

    affichage(grille, n);

    cache_milieu(grille, n);

    affichage(grille, n);
    fclose(fichier);
    return 0;
}
