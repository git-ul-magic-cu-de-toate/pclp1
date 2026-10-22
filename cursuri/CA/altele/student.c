// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include "student.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NMAX 100000

int scanf_student(student_t *s)
{
	char buff[NMAX + 1];

	// read firstname
	scanf("%s", buff);
	s->firstname = strdup(buff);
	if (!s->firstname) {
		return 0;
	}

	// read lastname
	scanf("%s", buff);
	s->lastname = strdup(buff);
	if (!s->lastname) {
		free(s->firstname);
		return 0;
	}

	// read age
	if (scanf("%d", &s->age) != 1) {
		free(s->firstname);
		free(s->lastname);
		return 0;
	}

	return 1; // success
}

void printf_student(const student_t *s)
{
	printf("%s %s %d\n",
		   s->firstname, s->lastname, s->age);
}

void destroy_student(student_t *s)
{
	free(s->firstname);
	free(s->lastname);
}

int copy_student(student_t *dst, const student_t *src)
{
	dst->firstname = strdup(src->firstname);
	if (!dst->firstname) {
		return 0;
	}

	dst->lastname = strdup(src->lastname);
	if (!dst->lastname) {
		free(dst->firstname);
		return 0;
	}

	dst->age = src->age;

	return 1; // success
}

int fwrite_string(const char *s, FILE *out)
{
	if (!s) {
		return 0;
	}

	size_t len = strlen(s); // don't count/write the terminator
	if (!fwrite(&len, sizeof(size_t), 1, out)) {
		return 0; // failed to write len
	}
	if (fwrite(s, sizeof(char), len, out) != len) {
		return 0; // failed to all chars from s
	}

	return 1; // success
}

int fread_string(FILE *in, char **s)
{
	if (!s) {
		return 0;
	}

	size_t len;
	if (!fread(&len, sizeof(size_t), 1, in)) {
		return 0; // failed to read len
	}
	char *str = (char *)malloc((len + 1) * sizeof(char));
	if (!str) {
		return 0; // failed to alloc str
	}
	if (fread(str, sizeof(char), len, in) != len) {
		return 0; // failed to read str
	}
	str[len] = '\0'; // append terminator
	*s = str; // save new buffer

	return 1; // success
}

int fwrite_student(const student_t *s, FILE *out)
{
	if (!fwrite_string(s->firstname, out)) {
		return 0;
	}

	if (!fwrite_string(s->lastname, out)) {
		return 0;
	}

	if (!fwrite(&s->age, sizeof(int), 1, out)) {
		return 0;
	}

	return 1; // success: all 3 elements were written
			  // a.k.a. 1 student was written
}

int fread_student(FILE *in, student_t *s)
{
	// read firstname
	if (!fread_string(in, &s->firstname)) {
		return 0;
	}

	// read lastname
	if (!fread_string(in, &s->lastname)) {
		free(s->lastname);
		return 0;
	}

	// read age
	if (!fread(&s->age, sizeof(int), 1, in)) {
		free(s->firstname);
		free(s->lastname);
		return 0;
	}

	return 1; // success
}
