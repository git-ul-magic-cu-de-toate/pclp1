#include <stdio.h>
#define NMAX 1000

void scanf_matrix(int n, int m, int a[NMAX][NMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
}

void printf_matrix(int n, int m, int a[NMAX][NMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// c = a * b
// unde a are dimensiune n x m, iar b are dimensiune m x p
void product_matrix(int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(void)
{
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);

    int a[NMAX][NMAX]; // = {0};
    scanf_matrix(n, m, a);
    printf_matrix(n, m, a);

    int b[NMAX][NMAX];
    scanf_matrix(m, p, b);
    printf_matrix(m, p, b);

    int c[NMAX][NMAX];  
    product_matrix(n, m, p, a, b, c);
    printf_matrix(n, p, c);

    return 0;
}

// TODO 0: C = A * B, dimensiuni n x m x p
