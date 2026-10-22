// Copyright 2020 Sabina Horincar (sabina.horincar@gmail.com)

// Citire int cu int dintr-un fisier.
// Nu cunoastem numarul de numere.

#include <stdio.h>

int main(void)
{
	FILE *file = fopen("02-eof_text_read_int.txt", "rt");
	if (!file) {
		return -1;
	}

	int n = 0;
	int x;
	while (fscanf(file, "%d", &x) == 1) {
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
// $ cat 02-eof_text_read_int.txt
// 12 2 149
// 429
//
//     9593   1     483
//
//
//
//
//
//
//
//
//
// 2
// (note: blank linkes, random whitespaces etc)
//
// $ ./02-eof_text_read_int
// 12 2 149 429 9593 1 483 2
// n = 8
//
