#include <stdio.h>
#define NMAX 100

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

void shift_left(int n, int v[NMAX])
{
    int tmp = v[0];
    for (int i = 0; i < n - 1; ++i) {
        v[i] = v[i + 1];
    }
    v[n - 1] = tmp;
}

void shift_right(int n, int v[NMAX])
{
    int tmp = v[n - 1];
    for (int i = n - 1; i >= 0; --i) {
        v[i] = v[i - 1];
    }
    v[0] = tmp;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int v[NMAX];
    scanf_vector(n, v);
    
    shift_left(n, v);

    printf_vector(n, v);

    shift_right(n, v);

    printf_vector(n, v);

    return 0;
}

// TODO 0: faceti o functie shift_left si o functie shift_right, care primeste ca parametru
// un vector v cu n elemente si care aplica o rotatie a elementelor (la stanga sau la dreapta).

