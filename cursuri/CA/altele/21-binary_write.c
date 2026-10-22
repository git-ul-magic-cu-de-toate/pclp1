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
	FILE *out = fopen(filename, "wb");
	if (!out) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	// 2. UTILIZARE (citire/scriere/mutare in fisier):
	int x = 2020;
	char s[100] = "gigel";
	fwrite(&x, sizeof(int), 1, out);

	int len = strlen(s);
	fwrite(&len, sizeof(int), 1, out);
	fwrite(s, sizeof(char), strlen(s), out);

	// 3. INCHIDERE (love your ponies)
	fclose(out);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./05-binary_write
//
// Check:
// $ hexdump -C example.bin
// 00000000  e4 07 00 00 67 69 67 65  6c                       |....gigel|
// 00000009
//
//
// ls -l example.bin
// -rw-rw-r-- 1 darius 9 Dec  9 23:40 example.bin
// expected size: 4 (sizeof(int)) + 5 (strlen("gigel"))
// Obs: Less space than the text version.
//
