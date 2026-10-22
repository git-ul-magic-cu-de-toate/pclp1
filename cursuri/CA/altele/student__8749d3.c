#include "student.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NMAX 100000

void read_student(student_t *s)
{
	char buff[NMAX + 1];

	scanf("%s", buff);
	// s->firstname = malloc(strlen(buff) + 1);
	// strcpy(s->firstname, buff);
	s->firstname = strdup(buff);

	scanf("%s", buff);
	s->lastname = malloc(strlen(buff) + 1);
	strcpy(s->lastname, buff);

	scanf("%d", &s->age);
}

void print_student(const student_t *s)
{
	printf("%s %s %d\n",
		   s->firstname, s->lastname, s->age);
}

void free_student(student_t *s)
{
	free(s->firstname);
	free(s->lastname);
}

void copy_student(student_t *dst, student_t *src)
{
	dst->firstname = strdup(src->firstname);
	// dst->firstname = malloc(strlen(src->firstname) + 1);
	// strcpy(dst->firstname, src->firstname);

	dst->lastname = strdup(src->lastname);
	// dst->lastname = malloc(strlen(src->lastname) + 1);
	// strcpy(dst->lastname, src->lastname);

	dst->age = src->age;
}
