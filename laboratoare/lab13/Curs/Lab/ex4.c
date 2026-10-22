#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NMAX 100

#ifdef SORT_ASC
int compare_int(const void *a, const void *b)
{
	return -(*(int *)b - *(int *)a);
}
#endif

#ifdef SORT_DESC
int compare_int(const void *a, const void *b)
{
	return (*(int *)b - *(int *)a);
}
#endif

int main(int argc, char *argv[])
{
	if (argc < 3) {
		fprintf(stderr, "Gigele, cel putin doua!\n");
		return 2;
	}

	// check natural numbers
	for (int i = 1; i < argc; ++i) {
		int len = strlen(argv[i]);
		for (int j = 0; j < len; ++j) {
			if (argv[i][j] < '0' || argv[i][j] > '9') {
				fprintf(stderr, "Gigele, da-mi numere naturale!\n");
				return -1;
			}
		}
	}

	// convert string to int
	int v[NMAX];
	for (int i = 1; i < argc; ++i) {
		v[i - 1] = strtol(argv[i], NULL, 10);
	}

	int n = argc - 1;
	qsort(v, n, sizeof(int), compare_int);

	for (int i = 0; i < n; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}
