#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

char **alloc_matrix(int n)
{
	char **a;
	a = (int **)malloc(n);

	for (int i = 0; i < n; i++) {
		*(a + i) = malloc(3);
	}

	return a;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	char **student = alloc_matrix(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%s", student[i][j]);
		}
	}

	int opt;
	scanf("%d", &opt);

	if (opt == 0) {

	}

	return 0;
}