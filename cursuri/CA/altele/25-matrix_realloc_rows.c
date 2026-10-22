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

int main(void)
{
    int n;
    scanf("%d", &n);

    // alocare matrice
    int **a = (int **)malloc(n * sizeof(int *));
    if (!a) {
        fprintf(stderr, "Tii cu ursu\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = (int *)malloc(n * sizeof(int));
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
    scanf_matrix(n, n, a);
    printf_matrix(n, n, a);

    int q;
    scanf("%d", &q);

    int new_row;
    for (int i = 0; i < q; ++i) {
        char type;
        int row, target;
        scanf(" %c", &type);
        scanf("%d%d", &row, &target);

        new_row = row;

        if (type == 'r') {
            int *tmp = (int *)realloc(*(a + row), target * sizeof(int));
            if (!tmp) {
                // free(v); // Mereu eliberam bufferul vechi, daca cel nou nu a putut fi eliberat.
                // PS Este gresit sa folosim v = reallc(v, ...);
                return -1;
            }
            *(a + row) = tmp;
            new_row += target;
        }

        if (type == 'f') {
            for (int j = 0; j < new_row; ++j) {
                *(*(a + row) + j) = target;
            }
        }
    }

    printf_matrix(n, new_row, a);

    return 0;
}

// TODO: Să se citească o matrice a cu n x n elemente.
// Ulterior se citesc q operatii, de forma "type row target".
// Dacă operația este de tipul 'r', se va face resize la linia row astfel încât să aibă dimensiunea target.
// Dacă operația este de tipul 'f', se va face umple linia row cu valoarea target.
