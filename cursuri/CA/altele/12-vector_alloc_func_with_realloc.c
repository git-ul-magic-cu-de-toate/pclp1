// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 5;
    int * v = (int*) malloc(n * sizeof(int));
    int *tmp = (int *) realloc(v, 2 * n);
    if (!tmp) {
        free(v); // Mereu eliberam bufferul vechi, daca cel nou nu a putut fi eliberat.
                 // PS Este gresit sa folosim v = reallc(v, ...);
        return -1;
    }
    v = tmp;
    free(v);

    return 0;
}

// TODO: Se alocă un vector cu n elemente. Să se dubleze ulterior dimensiunea acestuia.
// https://man7.org/linux/man-pages/man3/malloc.3.html
// Ce face realloc(NULL, n)? Dar realloc(ptr_valid, 0)?
