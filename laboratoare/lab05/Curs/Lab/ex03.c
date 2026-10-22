#include <stdio.h>

void swap_int(int *n, int *m)
{
	int tmp = *n;
	*n = *m;
	*m = tmp;
}

int main(void)
{
	int n, m;

	scanf("%d%d", &n, &m);

	swap_int(&n, &m);

	printf("%d %d\n", n, m);

	return 0;
}