// Aceeași sursă ca precedenta, dar dorim să modularizăm.

// Cum punem ca parametru un vector la o funcție?
// Cum se transmite un vector ca parametru?

#include <stdio.h>
#define NMAX 1000000 

void scanf_vector(int n, int v[NMAX])
{
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
}

void printf_vector(int n, int v[NMAX])
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void sort_vector(int n, int v[NMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (v[i] > v[j]) {
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}


int main(void)
{
    int n;
    scanf("%d", &n);

    int v[NMAX];
    scanf_vector(n, v);
    sort_vector(n, v);
    printf_vector(n, v);

    return 0;
}

// TODO 0: sort