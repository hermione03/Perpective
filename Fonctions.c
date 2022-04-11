#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Fonctions.h"

// FONCTIONS:

/*Cette fonction permet la lecture de fichier tout en remplissant une matrice à deux dimensions tel une copie de la grille en entree
en type int pour le traitement  */

void lecture(FILE *fichier, int grille[TMAX][TMAX], int n)
{
    int i = 0;
    char grille_temporaire[n][n]; // elle permet de copier les informations du fichier dans une premiere grille "temporaire" de type char

    char max_g = n * n;

    while (fgets(grille_temporaire[i], max_g, fichier)) // ici s'effectue donc cette copie et la boucle permet de lire le fichier jusqu'à sa fin
    {
        i++;
    }

    for (int y = 1; y <= n; y++) // le y commence par 1 car la premiere ligne contien le n
    {
        for (int i = 0; i < n; i++)
        {
            if (grille_temporaire[y][i] == 'X')
            {
                grille[y - 1][i] = 0; // remplace les X (comme écrit dans le fichier )
            }
            else if (grille_temporaire[y][i] >= '1')
            {
                grille[y - 1][i] = grille_temporaire[y][i] - '0'; // transformer les chiffres de char en int
            }
            else if (grille_temporaire[y][i] == ' ')
            {
                grille[y - 1][i] = -1; // remplace les espaces des quatres coins en -1
            }
        }
    }
}
/*********************************************************************************************************************/

/* Celle-ci comme son nom l'indique sert a afficher la grille dans le terminal*/

void affichage(int grille[TMAX][TMAX], int n)
{
    for (int ligne = 0; ligne < n; ligne++) // toujours par la ligne 1 et non 0 pour la raison expliquée plus haut
    {
        for (int col = 0; col < n; col++)
        {
            printf("%d ", grille[ligne][col]); // le reste est un parcours de matrice tout ce qu'il y a de plus classique...
        }
        printf("\n");
    }
}

/*********************************************************************************************************************/

void pov(int grille[TMAX], int n, int pdv[])
{
    int plg = grille[0];
    int len = n - 2;
    int j;
    pdv[0] = 1;
    pdv[1] = 1;
    for (j = 1; j < n - 1; j++)
    {
        if (grille[j] > plg)
        {
            pdv[0] += 1;
            plg = grille[j];
        }
    }
    plg = grille[len - 1];
    for (j = len - 2; j >= 0; j--)
    {
        if (grille[j] > plg)
        {
            pdv[1] += 1;
            plg = grille[j];
        }
    }
}
/*********************************************************************************************************************/

bool absent_in_row(int k, int grille[TMAX][TMAX], int i, int n)
{
    for (int j = 1; j < n - 1; j++)
        if (grille[i][j] == k)
            return false;
    return true;
}
bool absent_in_column(int k, int grille[TMAX][TMAX], int j, int n)
{
    for (int i = 1; i < n - 1; i++)
        if (grille[i][j] == k)
            return false;
    return true;
}

/*********************************************************************************************************************/
void certs(int a, int b, int c, int d, int n, int grille[TMAX][TMAX], int i, int j) // les placements surs
{
    int m = n - 2;
    int k, y;
    if (a == m && b == 1)
    {
        for (k = 1; k < n - 1; k++)
        {
            grille[i][k] = k;
        }
    }
    else if (a == 1 && b == m)
    {
        for (k = 1; k < n - 1; k++)
        {
            grille[i][k] = m;
            m -= 1;
        }
    }
    else if (a == 1)
    {
        grille[i][1] = m;
    }
    else if (b == 1)
    {
        grille[i][m] = m;
    }
    m = n - 2;
    if (c == m && d == 1)
    {
        for (y = 1; y < n; y++)
        {
            grille[y][j] = y - 1;
        }
    }
    else if (c == 1 && d == m)
    {
        for (y = 1; y < n; y++)
        {
            grille[y][j] = m;
            m -= 1;
        }
    }
    else if (c == 1)
    {
        grille[1][j] = m;
    }
    else if (d == 1)
    {
        grille[m + 1][j] = m;
    }
}
void traitement1(int grille[TMAX][TMAX], int n)
{
    int i, j;
    int a = 0, b = 0, c = 0, d = 0;
    for (i = 1; i < n - 1; i++) // Horizontalement
    {
        a = grille[i][0];
        b = grille[i][n - 1];
        for (j = 1; j < n; j++) // Verticalement
        {
            c = grille[1][j];
            d = grille[n][j];
            certs(a, b, c, d, n, grille, i, j);
        }
    }
}

/*********************************************************************************************************************/
