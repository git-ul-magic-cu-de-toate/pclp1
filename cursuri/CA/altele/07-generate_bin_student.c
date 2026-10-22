// Copyright 2020 Sabina Horincar (sabina.horincar@gmail.com)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX_LEN 100
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

	for (int i = 1; i <= n; ++i) {
		// student i: are age = 10 *i, name = "x...x" (i caractere 'x')

		int age = 10 * i; // genereaza varsta
		fwrite(&age, sizeof(int), 1, file); // scrie varsta

		// genereaza name
		char name[NAME_MAX_LEN];
		memset(name, 'x', i);

		// scrie name: lungime name + bytes name
		int len = strlen(name);
		fwrite(&len, sizeof(int), 1, file);
		fwrite(name, sizeof(char), len, file);
	}

	fclose(file);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./07-generate_bin_student
// 2 mystuds.bin
//
// $ hexdump -v -C mystuds.bin
// 00000000  0a 00 00 00 02 00 00 00  78 03 14 00 00 00 02 00  |........x.......|
// 00000010  00 00 78 78                                       |..xx|
// 00000014
//
