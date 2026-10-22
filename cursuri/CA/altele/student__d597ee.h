#pragma once

typedef struct __attribute__((packed)) {
	char *firstname; // 8
	char *lastname;  // 8
	int age;         // 4
} student_t; // requires deep copy

// read a student from STDIN
void read_student(student_t *s);

// print a student to STDOUT
void print_student(const student_t *s);

// release all resources related to student s
// (e.g. free allocated memory, close open files etc)
void free_student(student_t *s);

// deep copy a student (dst = stc)
void copy_student(student_t *dst, student_t *src);
