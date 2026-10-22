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

void print_vect(int n, int *v)
{
	for (int i = 0; i < n; ++i) {
		printf("%d ", *v + i);
	}

	printf("\n");
}

int main(void)
{
	int n;
	int *v;

	read_vect(&n, &v);

	print_vect(n, v);

	free(v);

	return 0;
}