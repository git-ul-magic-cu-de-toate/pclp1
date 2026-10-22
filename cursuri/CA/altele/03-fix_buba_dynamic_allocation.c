// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>
// observati ca am sters NMAX!!!

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
        v[i] ^= v[n - i - 1] ^= v[i] ^= v[n - i - 1]; // Tema de curs. Ce e vrajitoria asta? Ce operator este ^?
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    // alocare statica:
    // 1.  declarare + initializare.
    // Nu exista dealocare
    // int v[NMAX];
    // 2. Folosire
    // v[i] = ...;

    // alocare dinamica:
    // 1. declarare vector + alocare
    // int *v; + v = (int *) malloc(n * sizeof(int))
    // Putem face direct intr-o linie:
    int *v = (int *)malloc(n * sizeof(int));
    // calloc este malloc + initializare cu 0 - TODO: cautati si folositi functia memset. Ce face?
    // int *v = (int *) calloc(n, sizeof(int));
    if (!v) {           // programare defensiva: !v sau v != NULL
        fprintf(stderr, "Malloc failed\n"); // printare la stderr
        return 1;
    }

    // 2. Utilizare este ca mai jos:
    scanf_vector(n, v); // citire/modificare
    reverse_vector(n, v); // modificare
    printf_vector(n, v); // afisare
    // v[n - 1] = 5; // orice fel de utiliare!

    // 3. dealocare manuala: orice pointer returnat de malloc/calloc/realloc trebuie
    // eliberat cu free
    free(v);

    return 0;
}

// TODO: Vom folosi alocare dinamica sa corectam sursa 00-buba.c.
// ATENTIE! Vom schimba doar declararea + alocarea vectorului, functiile scanf_vector/printf_vector/reverse_vector
// vor ramane la fel intrucat DOAR folosesc vectorul deja declarat/alocat.
