// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>

// Functie pentru alocare pe heap matrice n x m de int.
int **alloc_matrix(int n, int m)
{
    // a este un vector de pointeri la int
    int **a = (int **) malloc(n * sizeof(int *));
    if (!a) {
        fprintf(stderr, "Boom 1\n");
        return NULL;
    }

    // alocam liniile
    for (int i = 0; i < n; ++i) {
        // a[i] va fi pointer la int 
        a[i] = (int *) malloc(m * sizeof(int));
        if (!a[i]) {
            fprintf(stderr, "Boom2 2\n");

            // daca ajungem aici, a esuat alocarea liniei i.
            // dar liniile i-1, i-2, ..., 0 sunt alocate.. deci trebuie sa le eliberam
            for (int j = i - 1; j >= 0; --j) {
                free(a[j]);
            }
            free(a);
            return NULL;
        }
    }

    // alocarea a reusit cu totul!
    return a;
}

// Functie pentru eliberare matrice n x m, de int.
void free_matrix(int n, int m, int **a) // TODO: trebuie/este util m aici? :D 
{
    for (int i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);
}

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
}

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    int **a = alloc_matrix(n, m);
    if (!a) {
        fprintf(stderr, "alloc_matrix() failed\n");
        return 1;
    }
    scanf_matrix(n, m, a);
    printf_matrix(n, m, a);
    // product_matrix(n, m, a);
    free_matrix(n, m , a);

    return 0;
}

// TODO: Ca sursa anterioara, doar ca am modularizat.
// De acum in colo, vom scrie functii asemanatoare cu:
// - alloc_matrix, free_matrix, ...
// - scanf_matrix, printf_matrix, ...
// - sum_matrix, product_matrix, ...

// $ make && valgrind ./21-matrix_dynamic_allocation_func 
// make: Nothing to be done for 'build'.
// ==252060== Memcheck, a memory error detector
// ==252060== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
// ==252060== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
// ==252060== Command: ./21-matrix_dynamic_allocation_func
// ==252060== 
// 3 4
// 1 2 3 4
// 5 6 7 8
// 9 0 0 0
// 1 2 3 4 
// 5 6 7 8 
// 9 0 0 0 

// ==252060== 
// ==252060== HEAP SUMMARY:
// ==252060==     in use at exit: 0 bytes in 0 blocks
// ==252060==   total heap usage: 6 allocs, 6 frees, 2,120 bytes allocated
// ==252060== 
// ==252060== All heap blocks were freed -- no leaks are possible
// ==252060== 
// ==252060== For lists of detected and suppressed errors, rerun with: -s
// ==252060== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)