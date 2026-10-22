#include <stdio.h>

int main(void)
{
	double a[100][100];
	int n, m;

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%lf", (*(a + i) + j));
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%lf ", *(*(a + i) + j));
		}
		printf("\n");
	}

	double *p;

	p = *(a + 2) + 3;

	if (&a[2][3] == p)
		printf("%p\n", *(a + 2) + 3);
	else
		printf("Nu\n");

	return 0;
}
