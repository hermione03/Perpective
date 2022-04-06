#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TMAX 12

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
            if (grille_temporaire[y][i] == 'X')
            {
                grille[y][i] = 0;
            }
            else if (grille_temporaire[y][i] >= '1')
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

/*void possible(int a,int b, int c, int d, int n){
    int m = n-2;
}*/

void traitement(int grille[TMAX][TMAX], int n)
{
    int i,j;
    int a = 0, b = 0, c = 0, d = 0;
    for (i = 0; i < n; i++)
    {
        a = grille[i][0];
        b = grille[i][n - 1];
        for (j = 0; j < n; j++)
        {
            c = grille[1][j];
            d = grille[n - 1][j];
            possible(a, b, c, d);
        }
    }
}

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