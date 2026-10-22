// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <string.h>
#define NMAX 100

void print_vector_int(int n, int *v)
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void print_vector_double(int n, double *v)
{
    for (int i = 0; i < n; ++i) {
        printf("%.5lf ", v[i]);
    }
    printf("\n");
}

void print_vector_char(int n, char *v)
{
    for (int i = 0; i < n; ++i) {
        printf("%c ", v[i]);
    }
    printf("\n");
}

int main(void)
{
    int v[NMAX] = {1, 2, 3, 4};
    int n = 4;
    print_vector_int(n, v);

    int w[NMAX];
    // w = v;
    // copy_vector(n, v, w);
    memcpy(w, v, n * sizeof(int));
    print_vector_int(n, w);

    memset(w, 255, n * sizeof(int));
    print_vector_int(n, w);

	return 0;
}

// TODO: man memcpy
// TODO: man memset
// TODO: man memmove
