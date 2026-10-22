#include <stdio.h>
#include <stdlib.h>

// funcția primește ca parametri dimensiunile unei matrice
// aloca tabloul și returnează pointerul
int **alloc_matrix(int n, int m)
{
	int **a;
	a = (int **)malloc(n * sizeof(int *));   // Alocare pentru vector de pointeri

	for (int i = 0; i < n; i++) {
		*(a + i) = malloc(m * sizeof(int)); // Alocare pentru o linie si initializare la zero
	}

	return a;
}

// funcția primește dimensiunile unei matrice și matricea alocată
// va citi elementele și le va salva în matrice
void read_matrix(int n, int m, int **a)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", *(a + i) + j);
		}
	}
}

// funcția va afișa elementele matricei
void print_matrix(int n, int m, int **a)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", *(*(a + i) + j));
		}
		printf("\n");
	}
}

// funcție care primește toate datele necesare pentru
// eliberarea unei matrice alocată cu alloc_matrix
//
// trebuie să deduceți semnătura
void free_matrix(int n, int **a)
{
	for (int i = 0; i < n; i++) {
		free(*(a + i));
	}

	free(a);
}

int main(void)
{
	int n, m;

	scanf("%d%d", &n, &m);

	int **a = alloc_matrix(n, m);

	read_matrix(n, m, a);

	print_matrix(n, m, a);

	free_matrix(n, a);

	return 0;
}