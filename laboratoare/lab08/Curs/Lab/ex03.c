#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char *nume;
	char grupa[5];
	double medie;
} student_t;

int main(void)
{
	student_t *student;
	student = (student_t *)malloc(sizeof(student_t));

	student->nume = (char *)malloc(30);
	fgets(student->nume, 30, stdin);
	student->nume[strlen(student->nume) - 1] = '\0';

	scanf("%s", student->grupa);
	getchar();

	scanf("%lf", &student->medie);
	getchar();

	// printf("%s\t%s\t%lf\n", student->nume, student->grupa, student->medie);

	// new student
	student_t *student_copy;
	student_copy = (student_t *)malloc(sizeof(student_t));

	// student_copy->nume = (char *)malloc(30);

	student_copy->nume = strdup(student->nume);

	strcpy(student_copy->grupa, student->grupa);

	student_copy->medie = student->medie;

	// change the name of the student copy
	strcpy(student_copy->nume, "Alex Negrescu");

	// print the first student
	printf("%s\t%s\t%lf\n", student->nume, student->grupa, student->medie);

	// print the student copy
	printf("%s\t%s\t%lf\n", student_copy->nume, student_copy->grupa, student_copy->medie);

	free(student->nume);
	free(student);

	free(student_copy->nume);
	free(student_copy);

	return 0;
}