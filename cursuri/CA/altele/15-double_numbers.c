// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 100

int main(void)
{
	// numele fisierului de intrare
	char input_filename[] = "15-double_numbers.in";

	// deschidere fisier de intrare pentru
	// citire (r) in modul text (t)
	FILE *in = fopen(input_filename, "rt");
	// verific daca fisierul a fost deschis cu succes
	// altfel opresc executia (in cazul acestei probleme)
	if (!in) {
		fprintf(stderr, "ERROR: Can't open file %s\n", input_filename);
		return -1;
	}

	// numarul de elemente si vectorul
	int n, v[NMAX];

	// citesc n din fisier, apoi citesc tabloul
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; ++i) {
		fscanf(in, "%d", &v[i]);
	}

	// deoarece stiu sigur ca nu mai am nimic de citit
	// pot inchide fisierul de intrare
	fclose(in);

	// dublez elementele din vector
	for (int i = 0; i < n; ++i) {
		v[i] *= 2;
	}

	// deschid fisierul pentru a scrie rezultatele
	char output_filename[] = "15-double_numbers.out";
	// deschid pentru scriere (w) in modul text (t)
	FILE *out = fopen(output_filename, "wt");
	// verific daca fisierul a fost deschis cu succes
	// altfel opresc executia (in cazul acestei probleme)
	if (!out) {
		fprintf(stderr, "ERROR: Can't open file %s\n", output_filename);
		return -1;
	}

	// scriu n in fisier, apoi tabloul
	fprintf(out, "%d\n", n);
	for (int i = 0; i < n; ++i) {
		fprintf(out, "%d ", v[i]);
	}
	fprintf(out, "\n");

	// inchid fisierul de iesire
	fclose(out);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./04-double_numbers
//
// Check:
// $ cat 04-double_numbers.in
// 7
// 2 -1 69 64 32 1024 -10
//
// $ cat 04-double_numbers.out
// 7
// 4 -2 138 128 64 2048 -20
//
