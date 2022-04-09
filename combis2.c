#include <stdio.h>
#include <stdlib.h>

#define TMAX 12

int pov(int tab[TMAX], int n)
{

    int pdv = 1;
    int plg = tab[0];
    int j;
    for (j = 1; j < n; j++)
    {
        if (tab[j] > plg)
        {
            pdv += 1;
            plg = tab[j];
        }
    }
    return pdv;
}
int pov_inv(int tab[TMAX], int n)
{

    int pdv = 1;
    int plg = tab[n - 1];
    int len = n - 1;
    int j;
    for (j = len; j >= 0; j--)
    {
        if (tab[j] > plg)
        {
            pdv += 1;
            plg = tab[j];
        }
    }
    return pdv;
}

void print_tab(int tab[], int size_tab)
{
    int i;

    for (i = 0; i < size_tab; i++)
        printf("%d", tab[i]);
    printf("\n"); // retour à la ligne
}

void permute(int tab[], int i, int j)
{
    int c;

    c = tab[i];
    tab[i] = tab[j];
    tab[j] = c;
}

void combin(int tab[], int i, int size_tab)
{
    int j;

    if (i == size_tab)
    {
        printf("%d\t", pov(tab, size_tab));
        printf("*%d*\t", pov_inv(tab, size_tab));
        print_tab(tab, size_tab);
    }
    else
        for (j = i; j < size_tab; j++)
        {
            permute(tab, i, j);
            combin(tab, i + 1, size_tab);
            permute(tab, i, j);
        }
}

void combin2(int tab[], int size_tab)
{
    int j, i=0;
    for (i = 0; i <= size_tab; i++)
    {
        if (i == size_tab)
        {
            printf("%d\t", pov(tab, size_tab));
            printf("*%d*\t", pov_inv(tab, size_tab));
            print_tab(tab, size_tab);
        }
        else
            for (j = i; j < size_tab; j++)
            {
                permute(tab, i, j);

                permute(tab, i, j);
            }
    }
}

int main()

{

    int nb, i;

    int *tab;

    // définition

    printf("nombres d'elements à trier: ");

    // rq : peut etre des fflush à faire pour nettoyer les tampons.

    scanf("%d", &nb);

    tab = malloc(nb * sizeof(int));

    // remplissage:

    for (i = 0; i < nb; i++)

    { // rq : peut etre des fflush à faire pour nettoyer les tampons.

        tab[i] = i + 1;
    }

    combin(tab,0, nb);
    free(tab);

    return 0;
}