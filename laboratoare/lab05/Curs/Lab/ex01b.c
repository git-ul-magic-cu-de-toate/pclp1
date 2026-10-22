#include <stdio.h>

int main(void)
{
	int n, *v;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", v + i);
	}

	for (int i = 0; i < n; ++i) {
		printf("%d %p\n", *(v + i), v + i);
	}

	return 0;
}