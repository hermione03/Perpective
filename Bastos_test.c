#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define TMAX 12

void tirage_h(int liste[], int n, int grille[TMAX][TMAX])
{
    int i, a, b;
    int min = 1;
    int nbrf = n - 1;

    grille[0][0] = '0';
    grille[n + 1][0] = '0';

    b = 0;

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        a = (int)ceil(rand() % (nbrf) + min);
        if (a == 1)
        {
            min = 2;
        }
        else if (a == nbrf - 1)
        {
            nbrf = nbrf - 1;
        }
        while (a == b)
        {
            a = (int)ceil(rand() % (nbrf - min) + min);
        }
        b = a;
        liste[i] = a;
        char car = a + '0';
        grille[i + 1][0] = car;
    }
}

void tirage_b(int liste[], int liste_h[], int n, int grille[TMAX][TMAX])
{
    int elem, temp, a;

    grille[0][n + 1] = '0';
    grille[n + 1][n + 1] = '0';

    for (elem = 0; elem < n; elem++)
    {
        a = 0;
        temp = liste_h[elem];
        while (temp <= n)
        {
            a = a + 1;
            temp = temp + 1;
        }
        liste[elem] = a;
        char car = a + '0';
        grille[elem + 1][n + 1] = car;
    }
}

void generateur(char n)
{
    int i, j, nbr;
    int grille[TMAX][TMAX];

    nbr = n - '0';
    printf("%d\n", nbr);

    int l1[nbr];
    int lb[nbr];

    // print haut
    tirage_h(l1, nbr, grille);
    tirage_b(lb, l1, nbr, grille);
    printf("  ");
    for (i = 0; i < nbr; i++)
    {
        printf("%d ", l1[i]);
    }
    printf("\n");

    // print milieu
    for (i = 1; i < nbr; i++)
    {
        printf("0");
        for (j = 0; j < nbr; j++)
        {
            printf(" X");
        }
        printf(" 0\n");
    }

    // print bas
    // tirage_b(lb,l1,nbr);
    printf("  ");
    for (i = 0; i < nbr; i++)
    {
        printf("%d ", lb[i]);
    }
    printf("\n");

    // remplissage centre de la grille

    for (i = 1; i <= nbr; i++)
    {
        for (j = 1; j <= nbr; j++)
        {
            grille[i][j] = 'X';
        }
    }

    // affichage de la grille dans le document final

    FILE *f = fopen("test.txt", "w");

    putc(n, f);
    putc('\n', f);

    for (j = 0; j < nbr + 2; j++)
    {
        for (i = 0; i < nbr + 2; i++)
        {
            char car = grille[i][j];
            printf("Le caractere de la grille pos[%d][%d] est %c\n", i, j, car);
            putc(car, f);
        }
        printf("\n");
        putc('\n', f);
    }
    fclose(f);
}

int main()
{
    generateur('6');
    return 0;
}