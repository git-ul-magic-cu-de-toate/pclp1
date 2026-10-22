// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 1000000 // TODO: Modificati NMAX a.i. codul sa crape.
                 // Concluzie prea multa memorie alocata, iar uneori nu o folosim (n = 2, NMAX = 10^6).

// Functie pentru citirea de la STDIN a unui vector v, cu n elemente.
void scanf_vector(int n, int *v)
{
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

// Functie pentru afisarea la STDOUT a unui vector v, cu n elemente.
void printf_vector(int n, int *v)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Functie pentru inversarea unui vector v, cu n elemente.
void reverse_vector(int n, int *v)
{
    for (int i = 0; i < n / 2; i++) {
        v[i] ^= v[n - i - 1] ^= v[i]; // Tema de curs. Ce e vrajitoria asta? Ce operator este ^?
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int v[NMAX];
    scanf_vector(n, v);
    // reverse_vector(n, v);
    printf_vector(n, v);

    return 0;
}

// TODO: E corect?
// TODO: Care e buba? Cum reproducem?
