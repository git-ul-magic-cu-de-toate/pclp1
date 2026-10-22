#include <stdio.h>
#include <stdlib.h>

void read_vect(int *n, int **v)
{
	scanf("%d", n);

	*v = malloc((*n) * sizeof(int *));

	if (!v) {
		printf("Could not allocate v\n");
		return;
	}

	for (int i = 0; i < *n; ++i) {
		scanf("%d", *v + i);
	}
}

int **alloc_matrix_varlen(int n, int *m)
{
	int **a;
	a = (int **)malloc(n * sizeof(int *));   // Alocare pentru vector de pointeri

	for (int i = 0; i < n; i++) {
		*(a + i) = malloc(*(m + i) * sizeof(int)); // Alocare pentru o linie si initializare la zero
	}

	return a;
}

void read_matrix(int n, int *m, int **a)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < *(m + i); ++j) {
			scanf("%d", *(a + i) + j);
		}
	}
}

void print_matrix(int n, int *m, int **a)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < *(m + i); ++j) {
			printf("%d ", *(*(a + i) + j));
		}
		printf("\n");
	}
}

void free_matrix_varlen(int n, int **a)
{
	for (int i = 0; i < n; i++) {
		free(*(a + i));
	}

	free(a);
}

int main(void)
{
	int n, *m; // declar n nr de linii si m un vector

	read_vect(&n, &m); // fac citirea pt m

	// aloc dinamic o matrice cu dim liniilor variabila
	int **a = alloc_matrix_varlen(n, m);

	read_matrix(n, m, a); // citire matrice cu linii variabile

	print_matrix(n, m, a); // afisare matrice cu linii variabile

	free_matrix_varlen(n, a);

	return 0;
}