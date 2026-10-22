#include <stdio.h>
#include <string.h>
#define NMAX 100

int main(void)
{
	int n, v[NMAX];

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}

	char filename[NMAX] = "random.txt";

	// 1. DESCHIDERE (poate include si operatia de CREARE) + VERIFICARE
	FILE *out = fopen(filename, "wt");
	if (!out) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	// 2. UTILIZARE (citire/scriere/mutare in fisier):

	for (int i = 0; i < n; ++i) {
		fprintf(out, "%d ", v[i]);
	}

	// 3. INCHIDERE (love your ponies)
	fclose(out);

	return 0;
}
