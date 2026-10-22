#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int **alloc_matrix(int n, int m)
{
	int **a;
	a = (int **)malloc(n * sizeof(int *));   // Alocare pentru vector de pointeri

	for (int i = 0; i < n; i++) {
		*(a + i) = malloc(m * sizeof(int)); // Alocare pentru o linie si initializare la zero
	}

	return a;
}

int main(void)
{
	int n, m, a[2][3];

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%p ", &a[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	int **b = alloc_matrix(n, m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%p ", &b[i][j]);
		}
		printf("\n");
	}

	return 0;
}