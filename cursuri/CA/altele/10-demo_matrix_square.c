#include <stdio.h>
#define NMAX 1000

void scanf_matrix(int n, int a[NMAX][NMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
}

void printf_matrix(int n, int a[NMAX][NMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int sum_matrix(int n, int a[NMAX][NMAX])
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += a[i][j];
        }
    }
    return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[NMAX][NMAX];
    scanf_matrix(n, a);
    printf_matrix(n, a);
    printf("sum = %d\n", sum_matrix(n, a));

    return 0;
}

// TODO 0: declarare, citire, afisare, suma elemente
