#pragma once

typedef struct __attribute__((packed))
{
	char firstname[20]; // 20
	char lastname[20];  // 20
	int age;            // 4
} student_t; // requires shallow copy

// read a student from STDIN
void read_student(student_t *s);

// print a student to STDOUT
void print_student(const student_t *s);
