// Copyright 2024 Darius Neatu (neatudarius@gmail.com)
#include <stdio.h>

// Exemplu cu macro-uri complexe.
// - SQR(2) -> 2 * 2
// - MAX(2, 3) -> 2 > 3 ? 2 : 3
#define SQR(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
// Avem nevoie de paranteze in jurul lui x si y pentru a evita problemele de prioritate a operatorilor.
// Si paranteze in jurul rezultatului pentru a evita problemele de prioritate a operatorilor.

int main(void)
{
    printf("Patratul lui 2 este: %d\n", SQR(2));
    printf("Patratul lui 3 + 2 este: %d\n", SQR(3 + 2));
    printf("Maximul dintre 2 si 3 este: %d\n", MAX(2, 3));
    printf("Maximul dintre 2 + 3 si 3 + 2 este: %d\n", MAX(2 + 3, 3 + 2));

    return 0;
}