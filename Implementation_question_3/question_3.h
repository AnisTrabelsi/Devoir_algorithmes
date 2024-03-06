#ifndef __QUESTION_3_H__
#define __QUESTION_3_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double **Initialiser_Matrices(int taille);
void Liberer_Matrices(double **matrice, int taille);
void Afficher_Matrices(double **matrice, int taille);
double **Changer_Signe_Matrices(double **A, int taille);
double **transposerMatrices(double **A, int taille);
double **additionMatrices(double **A, double **B, int taille);
double **Soustraire_Matrices(double **A, double **B, int taille);
double **Mutliplier_Matrices(double **A, double **B, int taille);
void concatenerMatrices_Strassen(double **matrice, double **result, int row, int col, int n);
double **Diviser_Strassen(double **matrice, int n, int row, int col);
double **StrassensMult_Recursif(double **matriceA, double **matriceB, int n);
double **strassensMultiplication(int n, double **matriceA, double **matriceB);
void Decomposer_Matrice(double **ATA, double **B, double **C, double **Ct, double **D, int n);
double **concatenerMatrices(double **I, double **CBinv_tSinv, double **SinvCBinv, double **Sinv, int taille);
double **Inverser_Matrices(double **ATA, int n);


#endif