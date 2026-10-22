// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

// Hai sa asamblam ce am invatat pana acum:
// - coding style: cum declar o structura?
//	typedef struct student {..} student_t;
//	Apoi peste tot in codul meu folosesc "student_t" (mai scurt, mai clar)
//
// - e OK ca si print_student si read_student sa primeasca pointer
//	AVANTAJ => putem afisa o structura alocata DINAMIC/STATIC fara copii
//
//	Ce ne scapa totusi? In functia printf NU ar trebui sa putem modifica structua
//	(adica e logic ca aceata functie doar sa afiseze, sa nu aiba drept de WRITE)
//	Solutie: const
//
//	* trebuie sa modificam cu datele citite de la tastatura
//	- void read_student(student_t *s);
//
//	* trebuie doar sa citesc datele
//	- void print_student(const student_t *s);
//
#include <stdio.h>

typedef struct {
	char nume[100]; // Gigel
	char grupa[6];  // 341C3
	float medie;    // 4
} student_t;

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

	read_student(&student);
	print_student(&student);

	return 0;
}

// Compile:
// $ make
//
// Run:
// ./03-demo_struct_ptr
// student: Gigel, grupa: 312XX, medie: 10.00
// nume = GigelOrNotGigel
// grupa = UCL
// medie = 2020
// student: GigelOrNotGigel, grupa: UCL, medie: 2020.00
//
