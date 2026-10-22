// Copyright 2020 Sabina Horincar (sabina.horincar@gmail.com)

// Sa se scrie intr-un fisier binar toate numerele de la 0 la n-1.
// Nu se va scrie numarul lor.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME_MAX_LEN 100

int main(void)
{
	int n;
	char filename[FILENAME_MAX_LEN + 1];
	scanf("%d%s", &n, filename);

	FILE *file = fopen(filename, "wb");
	if (!file) {
		return -1;
	}

    // scrie toate numerele de la 0 la n-1 in fisierul binar
	for (int i = 0; i < n; ++i) {
		fwrite(&i, sizeof(int), 1, file);
	}

	fclose(file);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./05-generate_bin_int
// 3 my_ints.bin
//
// $ hexdump -v -C myints.bin
// 00000000  00 00 00 00 01 00 00 00  02 00 00 00              |............|
// 0000000c
//
