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
	if (scanf("%d", &n) != 1) {
		fprintf(stderr, "Failed to read n\n");
		return -1;
	}

	for (int i = 0; i < n; ++i) {
		student_t s; // junk
		if (scanf_student(&s) != 1) {
			fprintf(stderr, "scanf_student() failed for student %i\n", i);
			return -1;
		}

		if (fwrite_student(&s, out) != 1) {
			fprintf(stderr, "fwrite_student() failed for student %i\n", i);
			return -1;
		}

		destroy_student(&s); // free
	}

	fclose(out);

	printf("hint: sizeof(char) = %zu\n", sizeof(char));
	printf("hint: sizeof(int) = %zu\n", sizeof(int));
	printf("hint: sizeof(size_t) = %zu\n", sizeof(size_t));

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
//
// $ hexdump  -v -C student.bin
// 00000000  05 00 00 00 00 00 00 00  47 49 47 45 4c 05 00 00  |........GIGEL...|
// 00000010  00 00 00 00 00 67 69 67  65 6c 14 00 00 00 08 00  |.....gigel......|
// 00000020  00 00 00 00 00 00 4e 4f  54 47 49 47 45 4c 08 00  |......NOTGIGEL..|
// 00000030  00 00 00 00 00 00 6e 6f  74 67 69 67 65 6c 15 00  |......notgigel..|
// 00000040  00 00 09 00 00 00 00 00  00 00 47 49 47 45 4c 49  |..........GIGELI|
// 00000050  4e 48 4f 09 00 00 00 00  00 00 00 67 69 67 65 6c  |NHO........gigel|
// 00000060  69 6e 68 6f 13 00 00 00                           |inho....|
// 00000068
//
// Explanation:
// * we should see 3 students in the binary file
// * each student has VARIABLE size in bytes (see student.h)
// $ ls -l student.bin
// -rw-rw-r-- 1 darius 104 Dec 15 15:44 student.bin
// (104 % 3 != 0)
// * 1st student:"GIGEL gigel 20"
//   GIGEL <=> 5 GIGEL <=>             05 00 00 00 00 00 00 00  47 49 47 45 4c ........
//      * 5        == 05 00 00 00 00 00 00 00  (check sizeof(size_t))
//      * GIGEL    == 47 49 47 45 4c           (no '\0')
//   gigel <=> 5 gigel <=>             ....................................... 05 00 00
//                                     00 00 00 00 00 67 69 67  65 6c .................
//      * 5         == 05 00 00 00 00 00 00 00  (check sizeof(size_t))
//      * gigel     == 67 69 67  65 6c          (no '\0')
//
//   20    <=>                         .............................. 14 00 00 00 .....
//      * 20        == 14 00 00 00              (check sizeof(int))
//
// * 2nd student:"NOTGIGEL notgigel 21"
//   NOTGIGEL <=> 8 NOTGIGEL <=>       ...........................................08 00
//                                     00 00 00 00 00 00 4e 4f  54 47 49 47 45 4c .....
//      * 8         == 08 00 00 00 00 00 00 00  (check sizeof(size_t))
//      * NOTGIGEL  == 4e 4f  54 47 49 47 45 4c           (no '\0')
//   notgigel <=> 5 notgigel <=>       ...........................................08 00
//                                     00 00 00 00 00 00 6e 6f  74 67 69 67 65 6c .....
//      * 8         == 07 00 00 00 00 00 00 00  (check sizeof(size_t))
//      * notgigel  == 6e 6f 74 67 69 67 65 6c          (no '\0')
//
//   21    <=>                          .............................. 15 00 00 00 .....
//      * 20        == 15 00 00 00              (check sizeof(int))
//
// * 3rd student:"GIGELINHO gigelinho 19"
//   GIGELINHO <=> 6 GIGELINHO <=>     09 00 00 00 00 00  00 00 47 49 47 45 4c 49 ......
//                                     4e 48 4f ........................................
//      * 9         == 09 00 00 00 00 00 00 00  (check sizeof(size_t))
//      * GIGELINHO == 47 49 47 45 4c 49 4e 48 4f          (no '\0')
//   gigelinho <=> 9 gigelinho <=>     ........ 09 00 00 00 00  00 00 00 67 69 67 65 6c
//                                     69 6e 68 6f ....................................
//      * 9         == 09 00 00 00 00 00 00 00  (check sizeof(size_t))
//      * gigelinho == 67 69 67 65 6c 69 6e 68 6f         (no '\0')
//
//   19    <=>                         ........... 13 00 00 00
//      * 19        == 13 00 00 00              (check sizeof(int))
//
// Homework: check with valgrind!
//
