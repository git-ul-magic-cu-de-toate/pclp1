#include <stdio.h>
#include <limits.h>

// returneaza un int din fiser (int-ul curent)
int get_int(FILE *in, int *done) {
	int n;
	int cnt = fread(&n, 1, sizeof(int), in);

	if (cnt == 0) {
		*done = 1;
		return -1;
	} else {
		*done = 0;
		return n;
	}
}

int main(int argc, char *argv[]) {
	int n = argc - 2;

	if (n < 2) {
		fprintf(stderr, "Usage: ./sort [in_files] output.bin\n");
		return -1;
	}

	FILE *out = fopen(argv[argc - 1], "wb");
	if (n == 0) {
		fprintf(stderr, "no input files\n");
		fclose(out);
		return 0;
	}

	FILE* in[100]; 		// in = malloc(n * sizeof(FILE *));
	for (int i = 0; i < n; ++i) {
		in[i] = fopen(argv[i + 1], "rb");
		
		if (in[i] == NULL) {
			fprintf(stderr, "%s nu exista\n", argv[i + 1]);
			return -2;
		}
	}
	
	int v[100];
	int done[100] = {0};

	// aduc cel mai mic element din fiecare fisier
	for (int i = 0; i < n; ++i) {
		v[i] = get_int(in[i], &done[i]);
	}

	int sorted = 0;
	while (!sorted) { // vectorul output nu este inca complet si sortat
		sorted = 1; // presupun ca e sortat

		int minim = INT_MAX;
		int pos = -1;

		// gasesc cel mai mic element v[i], pt care done[i] == 0
		for (int i = 0; i < n; ++i) {
			if (done[i] == 0) {
				if (v[i] < minim) {
					minim = v[i];
					pos = i;
				}

				sorted = 0; // am presupus prost, inca mai su nt element de procesat
			}
		}

		// daca s-a detectat ca nu este sortat
		// atunci mai am de lucru
		if (sorted == 0) {
			// adaug minimul in fisier
			printf("%d\n", minim);
			fwrite(&minim, 1, sizeof(int), out);

			// recitesc urmatorul element din fisierul cu indexul "pos"
			v[pos] = get_int(in[pos], &done[pos]);
		}
	}

	for (int i = 0; i < n; ++i) {
		fclose(in[i]);
	}
	fclose(out);

	return 0;
}


/*
	v:
	in[0] in[1] in[2]
	v[0]  v[1]  v[2]
    20    3      5

	done:
	0 1 0

	output:
	3
*/