#include <stdio.h>

#ifndef _func_h
#define _func_h

#define TMAX 12
void lecture(FILE *fichier, int grille[TMAX][TMAX], int n);
void affichage(int grille[TMAX][TMAX], int n);
void pov(int grille[TMAX], int n, int pdv[]);
bool absent_in_column(int k, int grille[TMAX][TMAX], int j, int n);
bool absent_in_row(int k, int grille[TMAX][TMAX], int i, int n);
void certs(int a, int b, int c, int d, int n, int grille[TMAX][TMAX], int i, int j);
void traitement1(int grille[TMAX][TMAX], int n);

#endif
