// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <string.h>

typedef struct {
	char nume[100];
	char grupa[6];
	float medie;
} student_t;

// shallow copy == copy byte by byte <=> bit by bit
// (copiere bit cu bit)
//
// adica daca am 2 structuri
//
// student_t a, b;
// a = b; // pot sa copiez informatia din b in a
//	   practic pt fiecare mebru "m" se face a.m = b.m
//
//	   m == nume (se copiaza 100 bytes) - vector static de 100 bytes
//	   m == grupa (se copiaza  6 bytes) - vector static de 6 bytes
//	   m == medie (se copiaza  4 bytes)
//

void print_student(const student_t *s)
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
	student_t student = {"Gigel", "312XX", 10};
	print_student(&student);

    // shallow copy - copy bit by bit
    // se copiaza bit cu bit - la propriu!!!
	student_t alt_student = student;
	print_student(&alt_student);

	printf("\nmodific numele din primul... si media\n");
	strcpy(alt_student.nume, "Gigelinio");
	alt_student.medie = 4;

	print_student(&student);
	print_student(&alt_student);
	printf("(schimbarea s-a produs doar pe primul student .."
		" normal.. celalalt e o copie in alta zona de memorie)\n");

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./04-demo_shallow_copy
// student: Gigel, grupa: 312XX, medie: 10.00
// student: Gigel, grupa: 312XX, medie: 10.00
//
// modific numele din primul... si media
// student: Gigel, grupa: 312XX, medie: 10.00
// student: Gigelinio, grupa: 312XX, medie: 4.00
// (schimbarea s-a produs doar pe primul student .. normal.. celalalt e o copie in alta zona de memorie
//
