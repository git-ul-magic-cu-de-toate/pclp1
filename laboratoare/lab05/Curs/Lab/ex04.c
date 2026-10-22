#include <stdio.h>

void swap_ptr(int **n, int **m)
{
	int *tmp = *n;
	*n = *m;
	*m = tmp;
}

int main(void)
{
	int *n, *m;

	printf("%p %p\n", n, m);

	swap_ptr(&n, &m);

	printf("%p %p\n", n, m);

	return 0;
}
