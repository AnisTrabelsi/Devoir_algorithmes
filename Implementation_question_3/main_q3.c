#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "question_3.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <nom_matrice.txt> <nom_matrice_resultat> \n", argv[0]);
        return 1;
    }

    FILE *fichier;
    int n;

    // Ouvrir le fichier en mode lecture
    fichier = fopen(argv[1], "r");

    // Vérifier si le fichier a été ouvert correctement
    if (fichier == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    // Lire la taille de la matrice depuis le fichier
    fscanf(fichier, "%d", &n);

    // Allouer de l'espace pour stocker la matrice carrée
    double **A = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    // Lire les éléments de la matrice depuis le fichier
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fichier, "%le", &A[i][j]);
        }
    }

    // Fermer le fichier
    fclose(fichier);

    // Afficher la matrice A
    printf("A:\n");
    Afficher_Matrices(A, n);
    printf("---------------------------------------------------\n");

    // Calculer la transposée de A
    double **AT = transposerMatrices(A, n);
    printf("AT:\n");
    Afficher_Matrices(AT, n);
    printf("---------------------------------------------------\n");
    // Calculer le produit matriciel A^TA
    double **ATA = Mutliplier_Matrices(AT, A, n);

    // Afficher A^TA
    printf("A^TA:\n");
    Afficher_Matrices(ATA, n);
    printf("---------------------------------------------------\n");

    clock_t start, end;
    double cpu_time_used;
    start = clock(); // calcul de temps

    // Calculer l'inverse de A^TA
    double **InverseATA = Inverser_Matrices(ATA, n);

    // Afficher l'inverse de A^TA
    printf("InverseATA:\n");
    Afficher_Matrices(InverseATA, n);
    printf("---------------------------------------------------\n");

    // Calculer l'inverse de A
    double **Ainv = Mutliplier_Matrices(InverseATA, AT, n);

    // Afficher l'inverse de A
    printf("A^(-1):\n");
    Afficher_Matrices(Ainv, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("---------------------------------------------------\n");
    printf("Temps d'execution: %f secondes\n", cpu_time_used);

    // Enregistrer Ainv dans un fichier
    fichier = fopen(argv[2], "w");
    if (fichier == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir le fichier pour l'écriture.\n");
        return 1;
    }

    fprintf(fichier, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(fichier, "%le   ", Ainv[i][j]);
        }
        fprintf(fichier, "\n");
    }

    fclose(fichier);
    // Libérer la mémoire
    Liberer_Matrices(A, n);
    Liberer_Matrices(AT, n);
    Liberer_Matrices(ATA, n);
    Liberer_Matrices(InverseATA, n);
    Liberer_Matrices(Ainv, n);

    return 0;
}
