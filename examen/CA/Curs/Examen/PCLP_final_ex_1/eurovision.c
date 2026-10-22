/* eurovision.c, Created on: 13.01.2012, Author: Florin Pop */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_LEN 16

void swapc(char **s, char **d) {
	char *buffer = *s; *s = *d; *d = buffer;
}

void swapi(int *x, int *y) {
	int aux = *x; *x = *y; *y = aux;
}

int search(char *country, int n, char *countries[]) {
	int i;
	for (i = 0; i < n; i++) {
		if (!strcmp(country, countries[i])) {
			return i;
		}
	}
	return -1;
}

void sort(int n, int p, char *countries[], int *score) {
	int i, j, poz;
	for (i = 0; i < p; i++) {
		poz = i;
		for (j = i + 1; j < n; j++) {
			if (score[j] > score[poz]) {
				poz = j;
			}
		}
		if (poz != i) {
			swapi(&score[poz], &score[i]);
			swapc(&countries[poz], &countries[i]);
		}
	}
}

int main() {
	int n, i, j, k = 0, *score, nc = 0;
	char filename[C_LEN], *top[C_LEN], country[C_LEN], **countries;
	FILE *f;

	scanf("%d %s", &n, filename);

	if ((countries = (char **)malloc(n * sizeof(char *))) == NULL) {
		fprintf(stderr, "Error: Out of memory.");
		return -1;
	}

	if ((score = (int *)malloc(n * sizeof(int))) == NULL) {
		fprintf(stderr, "Error: Out of memory.");
		return -1;
	}

	if ((f = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Error: Unable to open input file: %s.", filename);
		return -1;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < 13; j++) {
			fscanf(f, "%s", country);
			top[j] = strdup(country);
		}

		if (search(top[0], 12, top + 1) >= 0) {
			printf("Juriu descalificat: %s\n", top[0]);
		} else {
			countries[nc] = strdup(top[0]);
			score[nc] = 0;

			for (j = 1; j < 13; j++) {
				k = search(top[j], nc, countries);

				if (k < 0) {
					countries[nc] = strdup(top[j]);
					score[nc++] = 13 - j;
				} else {
					score[k] += 13 - j;
				}
			}
		}
	}

	fclose(f);

	sort(nc, 10, countries, score);

	printf("\nClasament final:\n");
	for (i = 0; i < 10; i++) {
		printf("\t%2d. [%3d] %s\n", i + 1, score[i], countries[i]);
	}

	printf("\n%d tari nu au obtinut nici un vot:\n", n - nc);
	for (i = nc; i < n; i++) {
		printf("\t%2d. %s\n", i, countries[i]);
	}

	free(score); free(countries);

	return 0;
}
