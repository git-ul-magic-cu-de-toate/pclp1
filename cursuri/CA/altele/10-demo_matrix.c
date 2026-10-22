#include <stdio.h>
#define NMAX 1000
#define MMAX 2000

void scanf_matrix(int n, int m, int a[NMAX][MMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
}

void printf_matrix(int n, int m, int a[NMAX][MMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int sum_matrix(int n, int m, int a[NMAX][MMAX])
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum += a[i][j];
        }
    }
    return 0;
}

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    int a[NMAX][MMAX];
    scanf_matrix(n, m, a);
    printf_matrix(n, m, a);
    printf("sum = %d\n", sum_matrix(n, m, a));

    return 0;
}

// TODO 0: declarare, citire, afisare, suma elemente
