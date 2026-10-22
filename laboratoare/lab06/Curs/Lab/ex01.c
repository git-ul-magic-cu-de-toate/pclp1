#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	int *v = (int *)malloc(n * sizeof(int));

	free(v);

	return 0;
}