#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

int pos_file(FILE *in, int start) {
	// fseek(in, 0, SEEK_SET);
	char buff[NMAX + 1];

	int n = start - 1;;
	for (int i = 0; i < n; ++i) {
		if (fgets(in, NMAX, buff) == NULL) {
			return -1; // prea putine linii in fisire
		}
	}	

	return 0; // totul a fost ok
}

int main(int argc, char*argv[]) {
	if (argc != 2) {
		fprintf(stderr, "./gigel fisier.txt\n");
		return -1;
	} 
	char *filename = argv[1];
	printf("%s\n", filename);

	char *p = strrchr(filename, '.');

	int n = p - filename + 1;
	char *out_name = malloc((n + 4) * sizeof(char));
	strncpy(out_name, filename, n);
	strcat(out_name, "cpl");

	printf("%s\n", out_name);

	FILE *in = fopen(filename, "rt");
	FILE *out = fopen(out_name, "wt");

	char fn[1000];
	char line[1000000];
	int start, n;
	
	int size = 0;
	int capacity = 10; // v[0], ..., v[capacity-1]
	char* *v = malloc(capacity * sizeof(char *));

	while (fscanf(in, "%s%d%d", fn, &start, &n) == 3) {
		FILE *f = fopen(fn, "rt");

		if (f == NULL) {
			fprintf(stderr, "%s nu exista\n", fn);
			continue;
		}

		// pozitioneaza in fisierul f inainte de linia
		// cu indicele start
		if (pos_file(f, start) == -1) {
			// nu exista linia start in fisier
			fclose(f);
			continue;
		}

		int i = 0;
		while (i < n  && fgets(f, 1000000-1, line)) {
			fprintf(out, "%s", line);
		}

		fclose(f);

		int ok = 1; // presupun ca fn NU este in v
		// v are size elemente puse
		for (int i = 0; i < size; ++i) {
			if (!strcmp(v[i], fn)) {
				ok = 0;  // am presupus prost
				// nu il voi adauga
				break;
			}
		}

		// dpar daca fn nu exista in vectorul v
		// il adaug in v
		if (!ok) {
			if (size == capacity) {
				capacity *= 2;
				// capacit++;
				
				v = realloc(v, capacity * sizeof(char *));
			}
			v[size] = strdup(fn);
			size++;
		}
	}
	v = realloc(v, size * sizeof(char *));

	// printeaza size si v

	free(out_name);
	fclose(in);
	fclose(out);
	free(v);

	return 0;
}