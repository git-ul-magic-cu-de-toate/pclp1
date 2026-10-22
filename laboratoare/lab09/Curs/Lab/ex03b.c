#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NMAX 100

int main(void)
{
	char filename[NMAX] = "random.bin";

	// 1. DESCHIDERE (poate include si operatia de CREARE) + VERIFICARE
	FILE *in = fopen(filename, "rb");
	if (!in) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	// 2. UTILIZARE (citire/scriere/mutare in fisier):

	int cnt = -1;
	int ignore;

	while (!feof(in)) {
		fread(&ignore, sizeof(int), 1, in);
		cnt++;
	}

	printf("%d\n", cnt);

	fseek(in, 0, SEEK_SET);

	int *v = (int *)malloc(cnt * sizeof(int));

	fread(v, sizeof(int), cnt, in);

	for (int i = 0; i < cnt; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");

	// 3. INCHIDERE (love your ponies)
	free(v);
	fclose(in);

	return 0;
}