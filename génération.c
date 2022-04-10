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

void remplissage_h(int grille[TMAX][TMAX], int n)
{
    int i, j, a, temp, res;
    temp = 0;
    res = 0;
    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            a = grille[i][j];
            if (a > temp)
            {
                res++;
                temp = a;
            }
        }
        grille[0][j] = res + '0';
        temp = 0;
        res = 0;
    }
}

void remplissage_b(int grille[TMAX][TMAX], int n)
{
    int i, j, a, temp, res;
    temp = 0;
    res = 0;
    for (j = n; j >= 1; j--)
    {
        for (i = n; i >= 1; i--)
        {
            a = grille[i][j];
            if (a > temp)
            {
                res++;
                temp = a;
            }
        }
        grille[n+1][j] = res + '0';
        temp = 0;
        res = 0;
    }
}

void remplissage_g(int grille[TMAX][TMAX], int n)
{
    int i, j, a, temp, res;
    temp = 0;
    res = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            a = grille[i][j];
            if (a > temp)
            {
                
                res++;
                temp = a;
            }
        }
        grille[i][0] = res + '0';
        temp = 0;
        res = 0;
    }
}

void remplissage_d(int grille[TMAX][TMAX], int n)
{
    int i, j, a, temp, res;
    temp = 0;
    res = 0;
    for (i = n; i > 0; i--)
    {
        for (j = n; j > 0; j--)
        {
            a = grille[i][j];
            if (a > temp)
            {
                
                res++;
                temp = a;
            }
        }
        grille[i][n+1] = res + '0';
        temp = 0;
        res = 0;
    }
}

void remplissage_t(int grille[TMAX][TMAX], int n)
{
    //remplissage ligne du haut
    remplissage_h(grille,n);

    //remplissage ligne du bas
    remplissage_b(grille,n);
    
    //remplissage ligne de la gauche
    remplissage_g(grille,n);
    
    //remplissage ligne de la droite
    remplissage_d(grille,n);

    //remplissage des coins
    grille[0][0] = ' ';
    grille[0][n + 1] = ' ';
    grille[n + 1][n + 1] = ' ';
    grille[n + 1][0] = ' ';
}

void generateur(char n)
{
    int i, j, nbr;
    int grille[TMAX][TMAX];
    nbr = n - '0';
    printf("%d\n",nbr);
    
    //remplissage du milieu de notre grille
    remplissage_m(grille,nbr);

    //verification du mileu
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
    
    //remplissage des bords de la grille
    remplissage_t(grille,nbr);

    //affichage de la grille résolue  
    FILE* f2 = fopen("Résultat.txt", "w");
    
    putc(n, f2);
    putc('\n', f2);

    for (j = 0; j < nbr + 2; j++)
    {
        for (i = 0; i < nbr + 2; i++)
        {
            char car = grille[i][j];
            
            putc(car,f2);
            //putc(' ',f2);
        }
        putc('\n',f2);        
    }
    fclose(f2);
/*
    printf("\n");
    //affichage terminal
    for (i = 0; i < nbr + 2; i++)
    {
        for (j = 0; j < nbr  + 2; j++)
        {
            printf("%c ",grille[i][j]);
        }
        printf("\n");
    }
*/
    //remplissage centre de la grille final
    for (i = 1; i <= nbr; i++)
    {
        for (j = 1; j <= nbr; j++)
        {
            grille[i][j] = 'X'; 
        }
    }
    printf("\n");

    //affichage terminal
    for (i = 0; i < nbr + 2; i++)
    {
        for (j = 0; j < nbr  + 2; j++)
        {
            printf("%c ",grille[i][j]);
        }
        printf("\n");
    }

    //affichage de la grille dans le document final  
    FILE* f = fopen("Énoncé.txt", "w");
    
    putc(n, f);
    putc('\n', f);

    for (j = 0; j < nbr + 2; j++)
    {
        for (i = 0; i < nbr + 2; i++)
        {
            char car = grille[i][j];
            
            putc(car,f);
            //putc(' ',f);
        }
        putc('\n',f);        
    }
    fclose(f);
}

int main()
{
    char a;
    printf("\nBonjour, vous allez pouvoir générer la grille aléatoire du jeu comprise entre 0 et 9.\n");
    printf("\nATTENTION : LA DIFFICULTÉ ET LE TEMPS POUR GÉNÉRER LA GRILLE EST DÛ AUX CHIFFRES CHOISIS\n");
    printf("\n(Nous recommandons une taille comprise entre 3 et 6)\n");
    printf("\nveuillez saisir un chiffre pour commencer: ");
    scanf("%c", &a);
    generateur(a);
    return 0;
}
