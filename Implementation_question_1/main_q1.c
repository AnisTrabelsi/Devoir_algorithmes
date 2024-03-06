#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "question_1.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <matriceA.txt> <matriceB.txt> <resultat.txt>\n", argv[0]);
        return 1;
    }

    FILE *fileA, *fileB, *fileOutput;
    int n;

    // Ouvrir les fichiers
    fileA = fopen(argv[1], "r");
    fileB = fopen(argv[2], "r");
    fileOutput = fopen(argv[3], "w");

    if (fileA == NULL || fileB == NULL || fileOutput == NULL)
    {
        fprintf(stderr, "Erreur lors de l'ouverture des fichiers.\n");
        return 1;
    }

    // Lire la taille des matrices
    fscanf(fileA, "%d", &n);
    fscanf(fileB, "%d", &n);

    // Allouer de la mémoire pour les matrices
    int **A = malloc(n * sizeof(int *));
    int **B = malloc(n * sizeof(int *));
    int **result = malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        A[i] = malloc(n * sizeof(int));
        B[i] = malloc(n * sizeof(int));
        result[i] = malloc(n * sizeof(int));
    }

    // Lire les éléments des matrices depuis les fichiers
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fscanf(fileA, "%d", &A[i][j]);
            fscanf(fileB, "%d", &B[i][j]);
        }
    }
    printf("---------------------------------------------------\n");

    clock_t start, end;
    double cpu_time_used;
    start = clock(); // calcul de temps
    // Effectuer la multiplication des matrices
    MultiplierMatrices(A, B, result, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Temps d'execution: %f secondes\n", cpu_time_used);

    // Écrire le résultat dans le fichier de sortie
    fprintf(fileOutput, "%d\n", n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fprintf(fileOutput, "%d ", result[i][j]);
        }
        fprintf(fileOutput, "\n");
    }

    // Fermer les fichiers et libérer la mémoire
    fclose(fileA);
    fclose(fileB);
    fclose(fileOutput);

    for (int i = 0; i < n; ++i)
    {
        free(A[i]);
        free(B[i]);
        free(result[i]);
    }
    free(A);
    free(B);
    free(result);

    return 0;
}