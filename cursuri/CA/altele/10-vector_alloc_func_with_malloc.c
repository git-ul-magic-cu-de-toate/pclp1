// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>

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
double average_vector(int n, int *v)
{
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }

    return 1.0 * sum / n;
}

// Functie care aloca un vector cu n elemente intregi.
// In caz de eroare, returneaza NULL.
int *alloc_vector(int n)
{
    int *v = (int *)malloc(n);
    if (!v) {
        fprintf(stderr, "Malloc failed - %p\n", v);
        return NULL;
    }
    return v;
}

// Eliberam mai multi vectori alocati dinamic.
void free_all(int *v, int *w)
{
    free(v);
    free(w);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    // Aloc primul vector.
    int *v = alloc_vector(n);
    if (!v) {
        // Nimic de eliberat, am 0 vectori alocati aici.
        return 1;
    }
    scanf_vector(n, v);
    printf_vector(n, v);
    printf("average = %lf\n", average_vector(n, v));

    int *w = alloc_vector(2 * n);
    if (!w) {
        free(v); // Am un vector alocat, v, in acest punct.
        return 2;
    }

    free_all(v, w);
    return 0;
}

// TODO: Sa se citeasca un vector v cu n elemente reprezentand notele studentilor. Dorim sa facem media
// notelor.
// Pentru aceasta problema, se va gestiona eficient memoria. Atentie la modularizare!
// https://man7.org/linux/man-pages/man3/malloc.3.html
