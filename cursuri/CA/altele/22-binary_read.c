// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <string.h>
#define NMAX 100

//
// man stdio
//
// FILE* fopen(const char* filepath, const char* flags);
//      filepath = cale catre fisier
//      flags = sir cu specificatori
//              r (read) sau w (write) sau a (append)
//              t (text) sau b (binary) - default: t
// Obs. fopen aloca o structura FILE cu malloc. Prin urmare, avem aceeasi
// verificare ca la malloc!
//
// int fclose(FILE *file);
//  Obs. fopen aloca o structura FILE, fclose o dealoca.
// Daca nu apelam fclose, avem memory leaks.
//
// int fread(void *p, int size_elem, int num_elem, FILE *in);
//  - functia citeste din fisierul binar in, num_elem elemente,
// fiecare element avand exact size_elem bytes, si salveaza tot
// sirul citit la adresa p
//      ex.
//          * citire int
//          int n;
//          int num_bytes = fread(&n, sizeof(int), 1, in);
//          * citire un T
//          T t;
//          int num_bytes = fread(&t, sizeof(T), 1, in);
//
// int fwrite(void *p, int size_elem, int num_elem, FILE *out);
// - la fel ca si fread, doar ca scrie elementele de la adresa p
// in fisierul out
//      ex.
//          * scriere int
//          int n = 2020;
//          int num_bytes = fwrite(&n, sizeof(int), 1, out);
//          * citire un T
//          T t;
//          int num_bytes = fwrite(&t, sizeof(T), 1, out);
//

int main(void)
{
	char filename[NMAX] = "example.bin";

	// 1. deschidere si verificare
	FILE *in = fopen(filename, "rb");
	if (!in) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	// 2. UTILIZARE (citire/scriere/mutare in fisier):
	int x;
	fread(&x, sizeof(int), 1, in);
	int len;
	fread(&len, sizeof(int), 1, in);
	char s[NMAX];
	fread(s, sizeof(char), len, in);

	printf("%d %s\n", x, s);

	// 3. INCHIDERE (love your ponies)
	fclose(in);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./06-binary_write
// 2020 gigel
//
// Check:
// $ hexdump -C example.bin
// 00000000  e4 07 00 00 67 69 67 65  6c                       |....gigel|
// 00000009
//
