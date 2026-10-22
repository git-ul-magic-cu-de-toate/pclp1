#include <stdio.h>
#define NMAX 100

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

// simuleaza b = a
void copy_matrix(int n, int m, int a[NMAX][NMAX], int b[NMAX][NMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = a[i][j];
        }
    }
}

// c = a * b
// unde a are dimensiune n x m, iar b are dimensiune m x p
void product_matrix(int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX])
{
    int tmp[NMAX][NMAX] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // c = tmp
    copy_matrix(n, p, tmp, c);
}

// calculeza a = In (matrice identitate)
void set_identity_matrix(int n, int a[NMAX][NMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = (i == j ? 1 : 0);
        }
    } 
}

// calculeza p = a^k, unde a e matrice n x n
void power_matrix(int n, int a[NMAX][NMAX], int k, int p[NMAX][NMAX])
{
    set_identity_matrix(n, p);
    for (int i = 1; i <= k; ++i) {
        product_matrix(n, n, n, a, p, p); // <=> p *= a;
    }
}

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);

    int a[NMAX][NMAX];
    scanf_matrix(n, n, a);
    printf_matrix(n, n, a);

    int p[NMAX][NMAX];
    power_matrix(n, a, k, p);
    printf_matrix(n, n, p);

    return 0;
}

// TODO 0: P = A^n


