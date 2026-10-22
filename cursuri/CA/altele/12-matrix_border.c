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

void printf_matrix_border(int n, int a[NMAX][NMAX])
{
    for (int j = 0; j < n; ++j) {
        printf("%d ", a[0][j]);
    }
    for (int i = 1; i < n; ++i) {
        printf("%d ", a[i][n - 1]);
    }
    for (int j = n - 2; j >= 0; --j) {
        printf("%d ", a[n - 1][j]);
    }
    for (int i = n - 2; i >= 1; --i) {
        printf("%d ", a[i][0]);
    }
}

void printf_matrix_border_corner(int n, int x, int y, int a[NMAX][NMAX])
{
    for (int j = y; j < y + n; ++j) {
        printf("%d ", a[x][j]);
    }
    for (int i = x; i < x + n; ++i) {
        printf("%d ", a[i][y]);
    }
    for (int j = y + n - 1; j >= y; --j) {
        printf("%d ", a[x][j]);
    }
    for (int i = x + n- 1; i >= x; --i) {
        printf("%d ", a[i][y]);
    }
}

void printf_matrix_zigzag(int n, int a[NMAX][NMAX])
{
    for (int i = 0; i < n; i += 2) {
        printf_matrix_border_corner(n - i, i / 2, i / 2, a);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[NMAX][NMAX];
    scanf_matrix(n, a);
    printf_matrix(n, a);
    printf_matrix_zigzag(n, a);

    return 0;
}

// TODO 0: declarare, citire, afisare, suma elemente
