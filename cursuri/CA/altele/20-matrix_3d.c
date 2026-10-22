#include <stdio.h>
#define NMAX 1000

void scanf_matrix(int n, int a[NMAX][NMAX][NMAX])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                scanf("%d", &a[i][j][k]);
            }
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    // Decomentati si faceti sa compileze urmatorul cod, care face suma elementelor unui
    // tabloud 3D.
    // int a... // Cum declaram pe a?
    // scanf_matrix3D(n, a);
    // printf_matrix3D(n, a);
    // printf("sum = %d\n", sum_matrix3D(n, a));

    return 0;
}

// TODO 0: declarare, citire, afisare, suma elemente din tabloud 3D.
