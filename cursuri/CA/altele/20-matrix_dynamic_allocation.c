// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>

// Functie pentru citirea de la STDIN a unei matrice a, cu n x m elemente.
void scanf_matrix(int n, int m, int **a)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Functie pentru afisarea la STDOUT a unei matrice a, cu n x m elemente.
void printf_matrix(int n, int m, int **a)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Functie pentru calcul produs elemente.
long long int product_matrix(int n, int m, int **a)
{
    long long int p = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            p *= a[i][j];
        }
    }
    return p;
}

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    // 1 declare + alocare
    int **a = (int **) malloc(n * sizeof(int *));
    if (!a) {
        fprintf(stderr, "Tii cu ursu\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = (int *) malloc(m * sizeof(int));
        if (!a[i]) {
            fprintf(stderr, "Tii cu ursu\n");
            for (int j = i - 1; j >= 0; --j) {
                free(a[j]);
            }
            free(a);
            return 2;
        }
    }

    // utilizare
    scanf_matrix(n, m, a);
    printf_matrix(n, m, a);

    // 3. dealocare
    for (int i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);

    return 0;
}

// TODO: Să se citească o matrice a cu n x m elemente. Să se calculeze produsul elementelor.
// Să se gestioneze eficient memoria.
