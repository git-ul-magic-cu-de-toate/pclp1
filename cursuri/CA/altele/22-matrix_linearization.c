// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>

// Functie pentru alocare pe heap matrice n x m de int, dar in forma liniarizata.
// Din punct de vedere al limbajului C, este un vector de int!
int *alloc_matrix_linear(int n, int m)
{
    // a este un vector de pointeri la int
    int *a = (int *)malloc(n * m * sizeof(int));
    if (!a) {
        fprintf(stderr, "Boom 1\n");
        return NULL;
    }

    // alocarea a reusit cu totul!
    return a;
}

// Functie pentru eliberare matrice n x m, de int, dar in forma liniarizata.
// Din punct de vedere al limbajului C, este un vector de int!
void free_matrix_linear(int n, int m, int *a) // TODO: trebuie/este util n/m aici? :D
{
    free(a);
}

// Functie pentru citirea de la STDIN a unei matrice a, cu n x m elemente.
void scanf_matrix_linear(int n, int m, int *a)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", (a + i * m + j)); // (a + i * m + j) e deja o adresa catre int-ul de il doresc a il modifica!
        }
    }
}

// Functie pentru afisarea la STDOUT a unei matrice a, cu n x m elemente.
void printf_matrix_linear(int n, int m, int *a)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", *(a + i * m + j)); // *(a + i * m + j) este int-ul pe care vreau sa il afisez
        }
        printf("\n");
    }
    printf("\n");
}

long long int product_matrix_linear(int n, int m, int *a)
{
    long long int p = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            p *= *(a + i * m + j);
        }
    }

    return p;
}

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    int *a = alloc_matrix_linear(n, m);
    if (!a) {
        fprintf(stderr, "alloc_matrix() failed\n");
        return 1;
    }

    scanf_matrix_linear(n, m, a);
    printf_matrix_linear(n, m, a);

    long long int p = product_matrix_linear(n, m, a); // - TODO: implementati product_matrix_linear
    printf("produs = %llu\n", p);

    free_matrix_linear(n, m, a);

    return 0;
}

// TODO: Să se citească o matrice a cu n x m elemente. Să se calculeze transpusa.
// Să se folosească o matrice liniarizată pentru a benefica de localitatea datelor.
// Ce este o matrice liniarizata? Avem toate elementele n x m alaturate, ca in cazul
// de alocare pe stiva, si le accesez prin indici (formula).
// Din n linii, m coloane
//      ... a[i - 1][j - 1] a[i - 1][j  ] a[i - 1][j + 1] ...
//      ... a[i    ][j - 1] a[i    ][j  ] a[     ][j + 1] ...
//      ... a[i + 1][j - 1] a[i + 1][j  ] a[i + 1][j + 1] ...
//
// Obtinem un vector cu n * m elemente
//      ... a[i - 1][j - 1] a[i - 1][j  ] a[i - 1][j + 1] ... a[i    ][j - 1] a[i    ][j  ] a[     ][j + 1] ... a[i + 1][j - 1] a[i + 1][j  ] a[i + 1][j + 1] ...
//
// a[i][j] de pe prima notatie este echivalent cu *(a + i * m + j) in a doua notatie. De ce?

// TODO: Comparati logul de la valgrind cu cel din sursa anterioara. Ce observati?
// $ make && valgrind ./22-matrix_linearization
// make: Nothing to be done for 'build'.
// ==252606== Memcheck, a memory error detector
// ==252606== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
// ==252606== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
// ==252606== Command: ./22-matrix_linearization
// ==252606==
// 3 4
// 1 2 3 4
// 5 6 7 8
// 9 0 0 0
// 1 2 3 4
// 5 6 7 8
// 9 0 0 0

// ==252606==
// ==252606== HEAP SUMMARY:
// ==252606==     in use at exit: 0 bytes in 0 blocks
// ==252606==   total heap usage: 3 allocs, 3 frees, 2,096 bytes allocated
// ==252606==
// ==252606== All heap blocks were freed -- no leaks are possible
// ==252606==
// ==252606== For lists of detected and suppressed errors, rerun with: -s
// ==252606== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
