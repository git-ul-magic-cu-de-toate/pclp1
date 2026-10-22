// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <string.h>

// declarare structura student (nume, grupa, medie)
struct student {
	char nume[100];// Gigel
	char grupa[6]; // 341C3
	float medie;   // 4
};

// functie care primeste ca parametru un student
// si ii afiseaza datele pe ecran
void print_student(struct student s)
{
	printf("student: %s, grupa: %s, medie: %2.2f\n", s.nume, s.grupa, s.medie);
}

int main(void)
{
    // declarare si initializare (ca la vector)
	struct student s = {"Gigel1", "341C3", 7};
	printf("nume = %s\n", s.nume);

    // dragut si recomandat e sa fac o functie sa afiseze tot ce vreau
	print_student(s);

    // declarare fara initializare
	struct student gigel;

    // initializare
	gigel.medie = 13.0;
    // // gigel.nume = "Gigel"; // ilegal (error)... but why?
	strcpy(gigel.nume, "Gigel2");
	strcpy(gigel.grupa, "312CA");
	print_student(gigel);

    // citire de la tastatura
    // scanf("%s %s %f", gigel.nume, gigel.grupa, &gigel.medie);
    // print_student(gigel);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./00-demo_struct
// nume = Gigel1
// student: Gigel1, grupa: 341C3, medie: 7.00
// student: Gigel2, grupa: 312CA, medie: 13.00
//
