// Copyright 2020 Sabina Horincar (sabina.horincar@gmail.com)

// Sa se citeasca dintr-un fisier binar int cu int pana la finalul
// fisierului binar.
// Nu se stie numarul lor.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME_MAX_LEN 100

int main(void)
{
	char filename[FILENAME_MAX_LEN + 1];
	scanf("%s", filename);

	FILE *file = fopen(filename, "rb");
	if (!file) {
		return -1;
	}

	int x;
	int n = 0;
    // fread returneaza cate elemente de tipul specificat a reusit sa citeasca
	// (int), daca s-a terminat fisierul, se returneaza 0
	while (fread(&x, sizeof(int), 1, file) == 1) {
		printf("%d ", x);
		++n;
	}
	printf("\n");
	printf("n = %d\n", n);

	fclose(file);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ hexdump -v -C myints.bin
// 00000000  00 00 00 00 01 00 00 00  02 00 00 00              |............|
// 0000000c
//
// $ ./06-read_bin_int
// myints.bin
// 0 1 2
// n = 3
