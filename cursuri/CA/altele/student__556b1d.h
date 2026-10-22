// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#pragma once

#define FIRSTNAME_LEN 19
#define LASTNAME_LEN 9
#define FILENAME "student.bin"

#include <stdio.h>

typedef struct __attribute__((packed))
{
	char firstname[FIRSTNAME_LEN + 1]; // e.g. 20B
	char lastname[LASTNAME_LEN + 1];   // e.g. 10B
	int age;					       // e.g. 4B
} student_t;                           // e.g. 34B (20 + 10 + 4)
// requires shallow copy
// e.g. student src = ...;
//      ...
//      student dst;
//		dst = src; // shallow copy == correct copy
//		memcpy(&dst, &src, sizeof(student_t)); // shallow copy == correct copy
//

// note "__attribute__((packed))" <=> __packed on GNU

// read a student from STDIN
void scanf_student(student_t *s);

// print a student to STDOUT
void printf_student(const student_t *s);

// read a student from a binary file
int fread_student(FILE *in, student_t *s);

// write a student in a binary file
void fwrite_student(const student_t *s, FILE *out);
