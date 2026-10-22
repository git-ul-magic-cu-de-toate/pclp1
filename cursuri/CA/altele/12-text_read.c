// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
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
// int fscanf(FILE *in, const char* fmt, ...)
//      ex. int n;
//          fscanf(in, "%d", &n);
//
// int fprintf(FILE *in, const char* fmt, ...);
//      ex. int n = 2020;
//          fprintf(in, "%d\n", &n);
//

int main(void)
{
	char filename[NMAX] = "example.txt";

	// 1. DESCHIDERE + VERIFICARE
	FILE *in = fopen(filename, "rt");
	if (!in) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	// 2. UTILIZARE (citire/scriere/mutare in fisier):
	int x;
	char s[NMAX];
	fscanf(in, "%d%s", &x, s);
	printf("x = %d s = %s\n", x, s);

	// 3. INCHIDERE (love your ponies)
	fclose(in);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./02-text_write
//
// Check:
// $ cat example.txt
// 2020 gigel
//
// ls -l example.txt
// -rw-rw-r-- 1 darius 11 Dec  9 22:51 example.txt
// expected size: 4 (cifre) + 1 (spatiu) + 5 ("gigel") + 1 ('\n')
//
// Extra check:
//      cat example.txt | wc -l
//      cat example.txt | wc -w
//      cat example.txt | wc -c
