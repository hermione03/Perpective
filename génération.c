#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define TMAX 12

bool is_ligne(int k, int grille[TMAX][TMAX], int i, int n)
{
    int g;
    for (int j = 1; j < n; j++)
    {
        g = grille[i][j] - '0';
        printf("%d, ", g);
        if (g == k)
        {
            printf("true\n");
            return true;
        }
    }
    printf("false\n");
    return false;
}

bool is_colonne(int k, int grille[TMAX][TMAX], int j, int n)
{
    int g;
    for (int i = 1; i < n; i++)
    {
        g = grille[i][j] - '0';
        printf("%d, ", g);
        if (g == k)
        {
            printf("true\n");
            return true;
        }
    }
    printf("false\n");
    return false;
}

void remplissage_m(int grille[TMAX][TMAX], int n)
{
    int i, j, nbrf, min, a, b;
    bool x, y;
    min = 1;
    nbrf = n+1;
    srand(time (NULL));
    for (i = 1; i < nbrf; i = i + 1)
    {
        for (j = 1; j < nbrf; j = j + 1)
        {
            //generation d'un nombre aléatoire
            a = (int) ceil(rand()%(nbrf - min) + min);
            printf("le nombre A est %d\n",a);
            //vérification pour savoir s'il est déjà présent sur la ligne
            x = is_ligne(a, grille, i, nbrf);
            printf("la ligne verifier est la ligne %d\n",i);
            printf("%s\n", x ? "true" : "false");
            if (x)
            {    
                while (x)
                {
                    //while (!is_ligne(a, grille, i, nbrf) && !is_colonne(a,grille, j, nbrf))
                    a = (int) ceil(rand()%(nbrf - min) + min);
                    printf("rechargement du nombre %d\n",a);
                    
                    x = is_ligne(a, grille, i, nbrf);
                    printf("la ligne verifier est la ligne %d\n",i);
                    printf("%s\n", x ? "true" : "false");

                    y = is_colonne(a, grille, j, nbrf);
                    printf("la colonne verifier est la colonne %d\n",j);
                    printf("%s\n", y ? "true" : "false");

                    while (y)
                    {
                        //while (!is_ligne(a, grille, i, nbrf) && !is_colonne(a,grille, j, nbrf))
                        b = (int) ceil(rand()%(nbrf - min) + min);
                        printf("rechargement du nombre %d\n",a);
                        y = is_colonne(b, grille, j, nbrf);
                        printf("la colonne verifier est la colonne %d\n",j);
                        printf("%s\n", y ? "true" : "false");
                    } 
                }
            }
            //vérification pour savoir s'il est déjà présent dans la colonne
            y = is_colonne(a, grille, j, nbrf);
            printf("la colonne verifier est la colonne %d\n",j);
            printf("%s\n", x ? "true" : "false");
            if (y)
            {
                while (y)
                {
                    //while (!is_ligne(a, grille, i, nbrf) && !is_colonne(a,grille, j, nbrf))
                    a = (int) ceil(rand()%(nbrf - min) + min);
                    printf("rechargement du nombre %d\n",a);
                    y = is_colonne(a, grille, j, nbrf);
                    x = is_ligne(a, grille, i, nbrf);
                    printf("la ligne verifier est la ligne %d\n",i);
                    printf("%s\n", x ? "true" : "false");
                    while (x)
                    {
                        //while (!is_ligne(a, grille, i, nbrf) && !is_colonne(a,grille, j, nbrf))
                        a = (int) ceil(rand()%(nbrf - min) + min);
                        printf("rechargement du nombre %d\n",a);
                        x = is_ligne(a, grille, i, nbrf);
                    }
                }
            }
            //si tout est bon remplir le tableau
            if (!y && !x)
            {
                printf("le nombre [%d] a été enregistré en position [%d][%d]\n",a,i,j);
                grille[i][j] = a + '0';
            }
        }
    }
}

bool verification_t(int grille[TMAX][TMAX], int n)
{
    int i, j, nbrf, a;
    char temp;
    bool x, y;
    nbrf = n+1;
    for (i = 1; i < nbrf; i = i + 1)
    {
        for (j = 1; j < nbrf; j = j + 1)
        {
            temp = grille[i][j];
            a = grille[i][j];
            a = a - '0';
            grille[i][j] = '0';
            printf("%d\n", a);
            x = is_ligne(a, grille, i, nbrf);
            y = is_colonne(a, grille, j, nbrf);
            if (x)
            {
                printf("grille corrompu\n");
                return false;
            }
            else if (y)
            {
                printf("grille corrompu\n");
                return false;
            }
            grille[i][j] = temp;
        }
    }
    printf("grille complete\n");
    return true;
}

void generateur(char n)
{
    int i, j, nbr;
    int grille[TMAX][TMAX];
    nbr = n - '0';
    printf("%d\n",nbr);
    
    //remplissage du milieu de notre grille
    remplissage_m(grille,nbr);

    bool x = verification_t(grille,nbr);

    while (!x)
    {
        for (i = 0; i < nbr + 2; i++)
        {
            for (j = 0; j < nbr + 2; j++)
            {
                grille[i][j] = ' ';
            }
        }
        
        remplissage_m(grille,nbr);
        x = verification_t(grille,nbr);
    }
    
    printf("le remplissage du milieu est %s\n", x ? "true" : "false");

    //remplissage centre de la grille final

/*
    for (i = 1; i <= nbr; i++)
    {
        for (j = 1; j <= nbr; j++)
        {
            grille[i][j] = 'X'; 
        }
    }
*/
    //affichage de la grille dans le document final 
/*  
    FILE* f = fopen("test.txt", "w");
    
    putc(n, f);
    putc('\n', f);

    for (j = 0; j < nbr + 2; j++)
    {
        for (i = 0; i < nbr + 2; i++)
        {
            char car = grille[i][j];
            //printf("Le caractere de la grille pos[%d][%d] est %c\n",i,j,car);
            putc(car,f);
            putc(' ',f);
        }
        //printf("\n");
        putc('\n',f);        
    }
    fclose(f);
*/
    for (i = 0; i < nbr + 2; i++)
    {
        for (j = 0; j < nbr  + 2; j++)
        {
            printf("%c ",grille[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    //char a;
    //printf("veuillez saisir un chiffre : ");
    //scanf("%c", &a);
    
    generateur('5');
    return 0;
}
