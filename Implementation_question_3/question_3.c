#include "question_3.h"


double **Initialiser_Matrices(int taille)
{
    // Allocation de la première dimension de la matrice (tableau de pointeurs)
    double **matrice = (double **)malloc(taille * sizeof(double *));

    // Vérifier si l'allocation a réussi
    if (matrice == NULL)
    {
        fprintf(stderr, "L'allocation de mémoire a échoué.\n");
        exit(EXIT_FAILURE);
    }

    // Allocation de la deuxième dimension de la matrice (tableau de doubles)
    for (int i = 0; i < taille; i++)
    {
        matrice[i] = (double *)malloc(taille * sizeof(double));

        // Vérifier si l'allocation a réussi pour chaque ligne
        if (matrice[i] == NULL)
        {
            fprintf(stderr, "L'allocation de mémoire a échoué.\n");

            // Libérer la mémoire précédemment allouée avant de quitter
            for (int j = 0; j < i; j++)
            {
                free(matrice[j]);
            }
            free(matrice);

            exit(EXIT_FAILURE);
        }

        // Initialiser les éléments de la matrice à 0 ou à une autre valeur par défaut
        for (int j = 0; j < taille; j++)
        {
            matrice[i][j] = 0.0;
        }
    }

    // Retourner le pointeur vers la matrice nouvellement allouée et initialisée
    return matrice;
}

/*******************************************************************************/
void Liberer_Matrices(double **matrice, int taille)
{
    // Libérer chaque ligne de la matrice
    for (int i = 0; i < taille; i++)
    {
        free(matrice[i]); // Libérer chaque ligne
    }

    free(matrice); // Libérer le tableau de pointeurs
}

/*******************************************************************************/
void Afficher_Matrices(double **matrice, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            printf("%f       ", matrice[i][j]);
        }
        printf("\n");
    }
}
/*********************************************************************************/
double **Changer_Signe_Matrices(double **A, int taille)
{
    // Allouer de la mémoire pour la matrice résultante
    double **result = (double **)malloc(taille * sizeof(double *));
    if (result == NULL)
    {
        // Gérer les erreurs d'allocation de mémoire
        fprintf(stderr, "Échec de l'allocation mémoire pour la matrice résultante.\n");
        exit(EXIT_FAILURE);
    }

    // Parcourir chaque ligne de la matrice
    for (int i = 0; i < taille; i++)
    {
        // Allouer de la mémoire pour chaque ligne de la matrice résultante
        result[i] = (double *)malloc(taille * sizeof(double));
        if (result[i] == NULL)
        {
            // Gérer les erreurs d'allocation de mémoire
            fprintf(stderr, "Échec de l'allocation mémoire pour la ligne %d de la matrice résultante. \n", i);
            exit(EXIT_FAILURE);
        }

        // Parcourir chaque colonne de la matrice
        for (int j = 0; j < taille; j++)
        {
            // Changer le signe de chaque élément et l'assigner à la nouvelle matrice
            result[i][j] = -A[i][j];
        }
    }

    // Renvoyer la nouvelle matrice résultante
    return result;
}

/**********************************************************************************/
double **transposerMatrices(double **A, int taille)
{
    // allocation de mémoire
    double **transpose = (double **)malloc(taille * sizeof(double *));
    if (transpose == NULL)
    {
        fprintf(stderr, "L'allocation de mémoire a échoué pour la matrice transposée.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < taille; i++)
    {
        transpose[i] = (double *)malloc(taille * sizeof(double));
        if (transpose[i] == NULL)
        {
            fprintf(stderr, "L'allocation de mémoire a échoué pour la ligne %d de la matrice transposée.\n", i);
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < taille; j++)
        {
            transpose[i][j] = A[j][i];
        }
    }

    return transpose;
}
/***********************************************************************************/
double **additionMatrices(double **A, double **B, int taille)
{
    // Allocate memory for the result matrice
    double **result = (double **)malloc(taille * sizeof(double *));
    if (result == NULL)
    {
        fprintf(stderr, "L'allocation de mémoire a échoué pour la matrice .\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < taille; i++)
    {
        result[i] = (double *)malloc(taille * sizeof(double));
        if (result[i] == NULL)
        {
            fprintf(stderr, "L'allocation de mémoire a échoué pour la ligne %d de la matrice .\n", i);
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < taille; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}
/***********************************************************************************/
double **Soustraire_Matrices(double **A, double **B, int taille)
{
    // Allocate memory for the result matrice
    double **result = (double **)malloc(taille * sizeof(double *));
    if (result == NULL)
    {
        fprintf(stderr, "L'allocation de mémoire a échoué pour la matrice .\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < taille; i++)
    {
        result[i] = (double *)malloc(taille * sizeof(double));
        if (result[i] == NULL)
        {
            fprintf(stderr, "L'allocation de mémoire a échoué pour la ligne %d de la matrice .\n", i);
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < taille; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}


/******************************************************************************************/
void concatenerMatrices_Strassen(double **matrice, double **result, int row, int col, int n)
{
    int i, j, r = row, c = col;
    for (i = 0; i < n; i++)
    {
        c = col;
        for (j = 0; j < n; j++)
        {
            result[r][c] = matrice[i][j];
            c++;
        }
        r++;
    }
}

/*********************************************************************************/
double **Diviser_Strassen(double **matrice, int n, int row, int col)
{
    int n_new = n / 2;

    double **array = Initialiser_Matrices(n_new);
    int i, j, r = row, c = col;
    for (i = 0; i < n_new; i++)
    {
        c = col;
        for (j = 0; j < n_new; j++)
        {
            array[i][j] = matrice[r][c];
            c++;
        }
        r++;
    }
    return array;
}

/**********************************************************************************/
double **StrassensMult_Recursif(double **matriceA, double **matriceB, int n)
{
    double **result = Initialiser_Matrices(n);
    if (n > 1)
    {
        // Diviser_Strassen
        double **a11 = Diviser_Strassen(matriceA, n, 0, 0);
        double **a12 = Diviser_Strassen(matriceA, n, 0, (n / 2));
        double **a21 = Diviser_Strassen(matriceA, n, (n / 2), 0);
        double **a22 = Diviser_Strassen(matriceA, n, (n / 2), (n / 2));
        double **b11 = Diviser_Strassen(matriceB, n, 0, 0);
        double **b12 = Diviser_Strassen(matriceB, n, 0, n / 2);
        double **b21 = Diviser_Strassen(matriceB, n, n / 2, 0);
        double **b22 = Diviser_Strassen(matriceB, n, n / 2, n / 2);

        // appel recursif de diviser et regner
        double **m1 = StrassensMult_Recursif(additionMatrices(a11, a22, n / 2), additionMatrices(b11, b22, n / 2), n / 2);
        double **m2 = StrassensMult_Recursif(additionMatrices(a21, a22, n / 2), b11, n / 2);
        double **m3 = StrassensMult_Recursif(a11, Soustraire_Matrices(b12, b22, n / 2), n / 2);
        double **m4 = StrassensMult_Recursif(a22, Soustraire_Matrices(b21, b11, n / 2), n / 2);
        double **m5 = StrassensMult_Recursif(additionMatrices(a11, a12, n / 2), b22, n / 2);
        double **m6 = StrassensMult_Recursif(Soustraire_Matrices(a21, a11, n / 2), additionMatrices(b11, b12, n / 2), n / 2);
        double **m7 = StrassensMult_Recursif(Soustraire_Matrices(a12, a22, n / 2), additionMatrices(b21, b22, n / 2), n / 2);

        double **c11 = additionMatrices(Soustraire_Matrices(additionMatrices(m1, m4, n / 2), m5, n / 2), m7, n / 2);
        double **c12 = additionMatrices(m3, m5, n / 2);
        double **c21 = additionMatrices(m2, m4, n / 2);
        double **c22 = additionMatrices(Soustraire_Matrices(additionMatrices(m1, m3, n / 2), m2, n / 2), m6, n / 2);
        // concatener les matrices
        concatenerMatrices_Strassen(c11, result, 0, 0, n / 2);
        concatenerMatrices_Strassen(c12, result, 0, n / 2, n / 2);
        concatenerMatrices_Strassen(c21, result, n / 2, 0, n / 2);
        concatenerMatrices_Strassen(c22, result, n / 2, n / 2, n / 2);
    }
    else
    {
        // condition 'arret
        result[0][0] = matriceA[0][0] * matriceB[0][0];
    }
    return result;
}
/**********************************************************************************************/

double **Mutliplier_Matrices(double **matriceA, double **matriceB,int n)
{
    double **result = StrassensMult_Recursif(matriceA, matriceB, n);
    return result;
}

/************************************************************************************/
void Decomposer_Matrice(double **ATA, double **B, double **C, double **Ct, double **D, int n)
{
    // Calcul de la moitié de la taille de la matrice
    int moitie_n = n / 2;

    // Boucle pour parcourir les sous-matrices
    for (int i = 0; i < moitie_n; i++)
    {
        for (int j = 0; j < moitie_n; j++)
        {
            // Assignation des valeurs à la sous-matrice B (quart supérieur gauche de ATA)
            B[i][j] = ATA[i][j];

            // Assignation des valeurs à la sous-matrice C (quart supérieur droit de ATA)
            Ct[i][j] = ATA[i][j + moitie_n];

            // Assignation des valeurs à la sous-matrice Ct (quart inférieur gauche de ATA)
            C[i][j] = ATA[i + moitie_n][j];

            // Assignation des valeurs à la sous-matrice D (quart inférieur droit de ATA)
            D[i][j] = ATA[i + moitie_n][j + moitie_n];
        }
    }
}
/*************************************************************************************/
double **concatenerMatrices(double **I, double **CBinv_tSinv, double **SinvCBinv, double **Sinv, int taille)
{
    int n = taille * 2;
    double **Minv = (double **)malloc(n * sizeof(double *));
    if (Minv == NULL)
    {
        fprintf(stderr, "L'allocation de mémoire a échoué pour Minv.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        Minv[i] = (double *)malloc(n * sizeof(double));
        if (Minv[i] == NULL)
        {
            fprintf(stderr, "L'allocation de mémoire a échoué pour la ligne %d de Minv.\n", i);
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < n; j++)
        {
            if (i < taille && j < taille)
            {
                // Top-left quadrant
                Minv[i][j] = I[i][j];
            }
            else if (i < taille && j >= taille)
            {
                // Top-right quadrant
                Minv[i][j] = CBinv_tSinv[i][j - taille];
            }
            else if (i >= taille && j < taille)
            {
                // Bottom-left quadrant
                Minv[i][j] = SinvCBinv[i - taille][j];
            }
            else
            {
                // Bottom-right quadrant
                Minv[i][j] = Sinv[i - taille][j - taille];
            }
        }
    }

    return Minv;
}
/***********************************************************************************************/
double **Inverser_Matrices(double **ATA, int n)
{
    // allocation des matrices
    double **B = Initialiser_Matrices(n / 2);
    double **D = Initialiser_Matrices(n / 2);
    double **C = Initialiser_Matrices(n / 2);
    double **Ct = Initialiser_Matrices(n / 2);

    int taille = n / 2;

    Decomposer_Matrice(ATA, B, C, Ct, D, n);

    // condition d'arret
    if (taille == 0)
    {
        fprintf(stderr, "Erreur : Matrices non inversible\n");
        exit(EXIT_FAILURE);
    }
    if (taille == 1)
    {

        B[0][0] = 1 / B[0][0]; // B^-1

        double **CBinv = Mutliplier_Matrices(C, B, taille);  // CB^-1
        double **BinvCt = transposerMatrices(CBinv, taille); // B^-1 * C^T
        double **S = Mutliplier_Matrices(C, BinvCt, taille);
        S = Soustraire_Matrices(D, S, taille); // S = D − C*(B^−1)*(C^T)

        double **Sinv = Initialiser_Matrices(1);
        Sinv[0][0] = 1 / S[0][0]; // S^-1

        double **SinvCBinv = Mutliplier_Matrices(Sinv, CBinv, taille);
        double **CBinv_tSinv = transposerMatrices(SinvCBinv, taille);              //(S^-1)*C*(B^−1)
        double **BinvCtSinvCBinv = Mutliplier_Matrices(BinvCt, SinvCBinv, taille); // (B^−1)*(C^T)*(S^-1)*C*(B^−1)
        double **I = additionMatrices(B, BinvCtSinvCBinv, taille);                 //(B^−1)+(B^−1)*(C^T)*(S^-1)*C*(B^−1)

        // Assemblage de la matrice inverse 2x2
        CBinv_tSinv = Changer_Signe_Matrices(CBinv_tSinv, taille); //-(S^-1)*C*(B^−1)
        SinvCBinv = Changer_Signe_Matrices(SinvCBinv, taille);     //-(B^−1)*(C^T)*(S^-1)
        double **Minv = concatenerMatrices(I, CBinv_tSinv, SinvCBinv, Sinv, taille);

        return Minv;
    }

    double **Binv = Inverser_Matrices(B, taille);
    double **CBinv = Mutliplier_Matrices(C, Binv, taille);
    double **BinvCt = transposerMatrices(CBinv, taille);
    double **S = Mutliplier_Matrices(CBinv, Ct, taille);
    S = Soustraire_Matrices(D, S, taille);

    double **Sinv = Inverser_Matrices(S, taille);
    double **SinvCBinv = Mutliplier_Matrices(Sinv, CBinv, taille);
    double **CBinv_tSinv = transposerMatrices(SinvCBinv, taille);
    double **BinvCtSinvCBinv = Mutliplier_Matrices(BinvCt, SinvCBinv, taille);
    double **I = additionMatrices(Binv, BinvCtSinvCBinv, taille);

    // Assemblage
    CBinv_tSinv = Changer_Signe_Matrices(CBinv_tSinv, taille);
    SinvCBinv = Changer_Signe_Matrices(SinvCBinv, taille);
    double **Minv = concatenerMatrices(I, CBinv_tSinv, SinvCBinv, Sinv, taille);

    // -- Liberation des matrices
    Liberer_Matrices(B, taille);
    Liberer_Matrices(C, taille);
    Liberer_Matrices(Ct, taille);
    Liberer_Matrices(D, taille);
    Liberer_Matrices(Binv, taille);
    Liberer_Matrices(CBinv, taille);
    Liberer_Matrices(BinvCt, taille);
    Liberer_Matrices(S, taille);
    Liberer_Matrices(Sinv, taille);
    Liberer_Matrices(SinvCBinv, taille);
    Liberer_Matrices(CBinv_tSinv, taille);
    Liberer_Matrices(BinvCtSinvCBinv, taille);
    Liberer_Matrices(I, taille);

    return Minv;
}
