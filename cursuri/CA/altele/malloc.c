#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int *v = malloc(n * sizeof(int));
	if (!v) {
		printf("Error\n");
		free(v);
		return 1;
	}

	printf("%ld\n", sizeof(v));

	free(v);

	return 0;
}