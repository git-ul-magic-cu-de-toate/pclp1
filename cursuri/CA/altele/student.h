// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#pragma once

#include <stdio.h>

#define FILENAME "student.bin"

typedef struct {
	char *firstname; // e.g. 8B
	char *lastname;  // e.g. 8B
	int age;         // e.g. 4B
} student_t;         // e.g. 20B (8 + 8 + 4)
// requires shallow copy
// e.g. student src = ...;
//      ...
//      student dst;
//		dst = src; // shallow copy == INCORRECT copy
//		memcpy(&dst, &src, sizeof(student_t)); // shallow copy == INCORRECT copy
//		copy_student(&dst, &src); // deep copy == CORRECT copy
//
// no need for attribute packed here, as we cannot use shallow copy
//

// read a student from STDIN
// return: 1 == success, 0 == error
int scanf_student(student_t *s);

// print a student to STDOUT
// return: 1 == success, 0 == error
void printf_student(const student_t *s);

// release all resources related to student s
// (e.g. free allocated memory, close open files etc)
void destroy_student(student_t *s);

// deep copy a student (dst = stc)
// return: 1 == success, 0 == error
int copy_student(student_t *dst, const student_t *src);

// write a string in a binary file
// convention: len + string (not including '\0')
// e.g. "gigel" -> len = 5
//				5 = 05 00 00 00
//				gigel = 67 69 67 65 6c
// char *s = "gigel";
// fwrite_string(s) -> write: 05 00 00 00 67 69 67 65 6c
//
// return: 1 == success, 0 == error
int fwrite_string(const char *s, FILE *out);

// read a string from a binary file
// convention: len + string (not including '\0')
// e.g. "gigel" -> len = 5
//				5 = 05 00 00 00
//				gigel = 67 69 67 65 6c
// char *s;
// fread_string(&s) -> s will point to a new string "gigel"
//
// return: 1 == success, 0 == error
int fread_string(FILE *in, char **s);

// write a student in a binary file
// return: 1 == success, 0 == error
int fwrite_student(const student_t *s, FILE *out);

// read a student from a binary file
// return: 1 == success, 0 == error
int fread_student(FILE *in, student_t *s);
