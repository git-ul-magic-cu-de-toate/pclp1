// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

// Read student by student from a binary file.
// Print students at STDOUT.

#include <stdio.h>
#include "student.h"

int main(void)
{
	FILE *in = fopen(FILENAME, "rb");
	if (!in) {
		fprintf(stderr, "Cannot open %s file", FILENAME);
		return -1;
	}

	int n = 0;
	student_t s; // junk
	while (fread_student(in, &s) == 1) {
		printf_student(&s);
		destroy_student(&s);
		++n;
	}
	printf("n = %d\n", n);

	fclose(in);
	return 0;
}

// Compile:
// $ make
//
// Run:
// $ hexdump -v -C student.bin
// 00000000  05 00 00 00 00 00 00 00  47 49 47 45 4c 05 00 00  |........GIGEL...|
// 00000010  00 00 00 00 00 67 69 67  65 6c 14 00 00 00 08 00  |.....gigel......|
// 00000020  00 00 00 00 00 00 4e 4f  54 47 49 47 45 4c 08 00  |......NOTGIGEL..|
// 00000030  00 00 00 00 00 00 6e 6f  74 67 69 67 65 6c 15 00  |......notgigel..|
// 00000040  00 00 09 00 00 00 00 00  00 00 47 49 47 45 4c 49  |..........GIGELI|
// 00000050  4e 48 4f 09 00 00 00 00  00 00 00 67 69 67 65 6c  |NHO........gigel|
// 00000060  69 6e 68 6f 13 00 00 00                           |inho....|
// 00000068
// (see 01-deep_writer.c for explanations)
//
// $ ./02-deep_reader
// GIGEL gigel 20
// NOTGIGEL notgigel 21
// GIGELINHO gigelinho 19
// n = 3
//
// Homework: check with valgrind!
//
