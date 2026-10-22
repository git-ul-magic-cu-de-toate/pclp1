#include "student.h"

#include <stdio.h>

#define NMAX 100000

void read_student(student_t *s)
{
	scanf("%s%s%d", s->firstname, s->lastname,
		  &s->age);
}

void print_student(const student_t *s)
{
	printf("%s %s %d\n",
		   s->firstname, s->lastname, s->age);
}
