#include <stdlib.h>
#include "student.h"

int main(void)
{
	student_t s;

	read_student(&s);
	print_student(&s);

	student_t c;
	copy_student(&c, &s);

	s.age = 123;
	s.firstname[0] = 'x';
	print_student(&s);
	print_student(&c);

	c.firstname[0] = 'a';
	print_student(&s);
	print_student(&c);

	free_student(&s);
	free_student(&c);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./02-student-deep_copy
// gigel not_gigel 2020
// gigel not_gigel 2020
// xigel not_gigel 123
// gigel not_gigel 2020
// xigel not_gigel 123
// aigel not_gigel 2020
//
// Homework: Use shallow copy in this source. Analyze it!
//
