#include <stdio.h>
#include <string.h>
#define NMAX 100

int sizeof_file(char *filename) {
	// deschidere fisier de intrare pentru
	// citire (r) in modul text (t)
	FILE *file = fopen(filename, "rt");

	// verific daca fisierul a fost deschis cu succes
	// altfel opresc executia
	if (file == NULL) {
		return -1; // nu am putut calcula dimensiunea
	}

	// ma pozitionez la sfarsit
	fseek(file, 0, SEEK_END);
	// acum cursorul este dupa ultimul caracter
	// deci ftell imi va spune pozitia, care este echivalenta cu numarul de bytes
	int bytes_count = ftell(file);

	// inchid fisierul
	fclose(file);

	return bytes_count;
}

int main() {
	// numele fisierului de intrare
	char filename[NMAX];

	fgets(filename, 100, stdin);
	filename[strlen(filename) - 1] = '\0';

	int sz = sizeof_file(filename);
	if (sz < 0) {
		// afisez la stderr
		fprintf(stderr, "ERROR: Can't open file %s", filename);
		return -1;
	}

	// afisez la stdout rezultatul
	printf("fisierul %s are %d bytes\n", filename, sz);

	// pot folosi tot fprintf pentru a afisa la stdout
	// fprintf(stdout, "fisierul %s are %d bytes\n", filename, sz);

	return 0;
}
