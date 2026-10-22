#include <stdio.h>

void citire_vector(int *n, int *v)
{
	scanf("%d", n);

	for (int i = 0; i < *n; ++i) {
		scanf("%d", v + i);
	}
}

int main(void)
{
	int v[10], n;

	citire_vector(&n, v);

	for (int i = 0; i < n; ++i) {
		printf("%d %p\n", *(v + i), v + i);
	}
	printf("\n");

	printf("%p\n", v);

	return 0;
}
