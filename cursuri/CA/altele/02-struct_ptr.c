// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nume[100]; // Gigel
	char grupa[6];  // 341C3
	float medie;    // 4
} student_t;

void print_student(student_t *s)
{
	printf("student: %s, grupa: %s, medie: %2.2f\n",
		   s->nume, s->grupa, s->medie);
}

void read_student(student_t *s)
{
	printf("nume = ");
	scanf("%s", s->nume);

	printf("grupa = ");
	scanf("%s", s->grupa);

	printf("medie = ");
	scanf("%f", &s->medie);
}

int main(void)
{
    // alocare dinamica structura
	student_t *stud = (student_t *)malloc(sizeof(student_t));
	if (!stud) {
		fprintf(stderr, "malloc() failed\n");
		return -1;
	}

    // accesare membru - MOD 1 (versiunea normala cu pointeri, NERECOMANDAT)
	(*stud).medie = 5;

    // accesare membru - MOD 2 (VERSIUNEA RECOMANDATA)
	stud->medie = 5;

	strcpy(stud->nume, "Gigel");
	strcpy(stud->grupa, "312CA");

	print_student(stud);

    // obligatoriu: eliberam memoria
	free(stud);

    // ACEEASI functie o folosesc sa afisez ORICE structure
    // alocata STATIC sau DINAMIC (mai sus am aratat cum facem pt dinamic)
	student_t s = {"Gigelinio", "312XX", 10};
	print_student(&s);

    // citesc o structura de la tastatura intr-o functie
	student_t restantier; // e alocat static. cum il pasez functiei sa il modifice?
	read_student(&restantier); // solutie: ii dau pointer la structura mea
	print_student(&restantier);

	stud = (student_t *)malloc(sizeof(student_t));
	if (!stud) {
		fprintf(stderr, "malloc() failed\n");
		return -1;
	}
	read_student(stud);
	print_student(stud);
	free(stud);

	return 0;
}

// Compile:
// $ make
//
// Run:
// ./02-demo_struct_ptr
// student: Gigel, grupa: 312CA, medie: 5.00
// student: Gigelinio, grupa: 312XX, medie: 10.00
// nume = not_gigel
// grupa = UCL
// medie = 12
// student: not_gigel, grupa: UCL, medie: 12.00
// nume = gigel_again
// grupa = UCL_FINALS
// medie = 13
// student: gigel_again, grupa: UCL_FINA, medie: 13.00
//
// Homework: valgrind checks
//
