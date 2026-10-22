// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <string.h>

// declarare structura student (nume, grupa, medie)
// + folosire typedef

// typedef some_type new_type_name;

// Conventie in C din Linux kernel
// (also si pentru chestii standard; exemplu: size_t)
// typedef some_type new_type_name_t;
// (punem _t la final sa sugeram ca e un nume de tip)

typedef struct {
	char nume[100]; // Gigel
	char grupa[6];  // 341C3
	float medie;    // 4
} student_t;

// functie care primeste ca parametru un student
// si ii afiseaza datele pe ecran
void print_student(student_t s)
{
	printf("student: %s, grupa: %s, medie: %2.2f\n", s.nume, s.grupa, s.medie);
}

int main(void)
{
	student_t s = {"Gigel", "341C3", 4};
	print_student(s);

	strcpy(s.nume, "Gigelinio");
	print_student(s);

	return 0;
}

// Compile:
// $ make
// Run:
// $.//01-demo_typedef
// student: Gigel, grupa: 341C3, medie: 4.00
// student: Gigelinio, grupa: 341C3, medie: 4.00
//
// Homework:
// * Compile the next code. Explain why it works.
//		typedef int foo;
//		foo;
//		foo = 2;
//
