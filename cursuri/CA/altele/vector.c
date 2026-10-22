// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include "vector.h" // prima linie din fisierul .c
#include <stdio.h>

void read_vector(int n, int v[NMAX])
{
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
}

void print_vector(int n, int v[NMAX])
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
