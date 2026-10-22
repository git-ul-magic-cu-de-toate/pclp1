// Copyright 2020 Sabina Horincar (sabina.horincar@gmail.com)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX_LEN 100
#define FILENAME_MAX_LEN 100

int main(void)
{
	char filename[FILENAME_MAX_LEN + 1];
	scanf("%s", filename);

	FILE *file = fopen(filename, "rb");
	if (!file) {
		return -1;
	}

	int n = 0;
	int age;
	char name[NAME_MAX_LEN];
	while (fread(&age, sizeof(int), 1, file) == 1) {
		int len;
		fread(&len, sizeof(int), 1, file);
		fread(name, sizeof(char), len, file);
		// in fisier nu exista '\0'
		name[len] = '\0';

		++n;
		printf("%d %s\n", age, name);
	}
	printf("n = %d\n", n);

	fclose(file);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ hexdump -v -C mystuds.bin
// 00000000  0a 00 00 00 02 00 00 00  78 03 14 00 00 00 02 00  |........x.......|
// 00000010  00 00 78 78                                       |..xx|
// 00000014
//
// $ ./08-read_bin_student
// mystuds.bin
// 10 x
// 20 xx
// n = 2
