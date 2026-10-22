// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

// Read n (number of students) and students (from STDIN).
// Write student by student in a binary file.

#include <stdio.h>
#include "student.h"

int main(void)
{
	FILE *out = fopen(FILENAME, "wb");
	if (!out) {
		fprintf(stderr, "Cannot open %s file", FILENAME);
		return -1;
	}

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		student_t s; // junk
		scanf_student(&s);
		fwrite_student(&s, out);
	}

	fclose(out);

	printf("hint: sizeof(char) = %zu\n", sizeof(char));
	printf("hint: sizeof(int) = %zu\n", sizeof(int));
	printf("hint: sizeof(size_t) = %zu\n", sizeof(size_t));
	printf("hint: sizeof(student_t) = %zu\n", sizeof(student_t));

	return 0;
}

// Compile:
// $ make
//
// Run:
// cat student.txt
// 3
// GIGEL gigel 20
// NOTGIGEL notgigel 21
// GIGELINHO gigelinho 19
//
// $ ./01-shallow_writer < student.txt
// hint: sizeof(char) = 1
// hint: sizeof(int) = 4
// hint: sizeof(size_t) = 8
// hint: sizeof(student_t) = 34
//
// $ hexdump  -v -C student.bin
// 00000000  47 49 47 45 4c 00 00 00  00 00 00 00 00 00 00 00  |GIGEL...........|
// 00000010  00 00 00 00 67 69 67 65  6c 00 00 00 00 00 14 00  |....gigel.......|
// 00000020  00 00 4e 4f 54 47 49 47  45 4c 00 00 00 00 00 00  |..NOTGIGEL......|
// 00000030  00 00 00 00 00 00 6e 6f  74 67 69 67 65 6c 00 00  |......notgigel..|
// 00000040  15 00 00 00 47 49 47 45  4c 49 4e 48 4f 00 00 00  |....GIGELINHO...|
// 00000050  00 00 00 00 00 00 00 00  67 69 67 65 6c 69 6e 68  |........gigelinh|
// 00000060  6f 00 13 00 00 00                                 |o.....|
// 00000066
//
// Explanation:
// * we should see 3 students in the binary file
// * each student has exactly 34 bytes (see student.h)
// $ls -l student.bin
// -rw-rw-r-- 1 darius 102 Dec 15 13:31 student.bin
// (34 * 3 = 102)
// * 1st student:"GIGEL gigel 20"
//   GIGEL\0 =  47 49 47 45 4c 00 00 00  00 00 00 00 00 00 00 00
//              00 00 00 00 ...
//   (firstname always has 20 bytes!)
//   gigel\0 =  ... 67 69 67 65  6c 00 00 00 00 00 ...
//   (lastname always has 10 bytes!)
//   20      =  ... 14 00 00 00 ...
//   (age always has 4 bytes!)
//
// * 2nd student:"NOTGIGEL notgigel 21"
//   NOTGIGEL\0 =  ... 4e 4f 54 47 49 47  45 4c 00 00 00 00 00 00
//                 00 00 00 00 00 00 ...
//   (firstname always has 20 bytes!)
//   notgigel\0 =  ... 6e 6f  74 67 69 67 65 6c 00 00 ...
//   (lastname always has 10 bytes!)
//   21         =  15 00 00 00
//   (age always has 4 bytes!)
//
// * 3rd student:"GIGELINHO gigelinho 19"
//   GIGELINHO\0 =  ... 47 49 47 45  4c 49 4e 48 4f 00 00 00
//                  00 00 00 00 00 00 00 00 ...
//   (firstname always has 20 bytes!)
//   gigelinho\0 =  ... 67 69 67 65 6c 69 6e 68
//                  6f 00 ...
//   (lastname always has 10 bytes!)
//   19      =  ... 13 00 00 00
//   (age always has 4 bytes!)
//
// Homework: check with valgrind!
//
