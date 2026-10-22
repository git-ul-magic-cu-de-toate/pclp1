// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include "student.h"
#include <string.h>

void scanf_student(student_t *s)
{
	memset(s, 0, sizeof(student_t));
	scanf("%s%s%d", s->firstname, s->lastname,
		  &s->age);
}

void printf_student(const student_t *s)
{
	printf("%s %s %d\n",
		   s->firstname, s->lastname, s->age);
}

int fread_student(FILE *in, student_t *s)
{
	return fread(s, sizeof(student_t), 1, in);
}

void fwrite_student(const student_t *s, FILE *out)
{
	fwrite(s, sizeof(student_t), 1, out);
}
