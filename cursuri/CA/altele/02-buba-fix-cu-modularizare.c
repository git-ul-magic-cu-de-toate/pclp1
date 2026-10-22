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

int sum_vector(int n, int v[NMAX])
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
    }
    return sum;
}

double average_vector(int n, int v[NMAX])
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
    }
    return 1.0 * sum / n;
}

void reverse_vector(int n, int v[NMAX])
{
    for (int i = 0; i < n / 2; ++i) {
        int tmp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = tmp;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int v[NMAX];
    scanf_vector(n, v);
    printf_vector(n, v);
    int sum = sum_vector(n, v);
    printf("sum = %d\n", sum);
    printf("average = %5.3lf\n", average_vector(n, v));

    reverse_vector(n, v);
    printf_vector(n, v);

    return 0;
}

// TODO 0: Copiaza main-ul din sursa anterioara aici.
// TODO 1: Modularizare: Ce/cate functii avem nevoie sa scriem?
