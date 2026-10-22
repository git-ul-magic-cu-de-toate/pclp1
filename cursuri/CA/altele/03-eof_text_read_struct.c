// Copyright 2020 Sabina Horincar (sabina.horincar@gmail.com)

// Citire student cu student dintr-un fisier.
// Nu cunoastem numarul de studenti.

#include <stdio.h>

// citim elementele unei structuri din fisier
typedef struct {
	char name[100];
	int age;
} student_t;

int main(void)
{
	FILE *file = fopen("03-eof_text_read_struct.txt", "rt");
	if (!file) {
		return -1;
	}

	int n = 0;
	student_t stud;
    // atata timp cat fscanf a reusit sa citeasca un student
	// (cu 2 atribute: string si int)continui
	while (fscanf(file, "%s%d", stud.name, &stud.age) == 2) {
		printf("%s %d\n", stud.name, stud.age);
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
// $ cat 03-eof_text_read_struct.txt
// Gigel 25
// Hex 20
// Andrei 19
//
//
//
//			Adina		10
// Isabela				18
// Sabina 1
// (note: random whitespaces)
//
// $ ./03-eof_text_read_struct
// Gigel 25
// Hex 20
// Andrei 19
// Adina 10
// Isabela 18
// Sabina 1
//
// n = 6
//
