// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

// Am modificat structura student_t asftel incat numele si grupa
// sa fi alocate dinamic.
//
// 1. shallow copy == copy bit by bit
//	(copiere bit cu bit)
//
//	student_t a, b;
//	a = b; // pot sa copiez informatia din b in a
//		   practic pt fiecare mebru "m" se face a.m = b.m
//
//			a.medie = b.medie   <=> float = float   =>     OK (se copiaza un numar)
//			a.nume  = b.nume    <=> char * = char * => NOT OK (se copiaza un pointer)
//			a.grupa = b.grupa   <=> char * = char * => NOT OK (se copiaza un pointer)
//
//			De ce nu e ok ca se copiaza un pointer?
//				Poi o sa am 2 pointeri (a.nume, b.nume) care pointeaza catre acelasi
//				sir => modific pe unul, se modifica si celalalt.
//			Ex.
//				student_t a = {"Gigel",     "x", 1};
//				student_t b;
//				b = a; // b are aceleasi valori ca si a
//
//				b.medie = 2; // media lui b este 2, a lui a este tot 1
//				b.nume[0] = 'X'; // ups am modificat primul caracter in ambele nume!
//
// 2. deep copy - new copy objects are created for any referenced objects
// (daca in structura am pointer la o variabila, fac o copie varibilei
// in alta zona de memorie si copiez noul pointer)
//
// Ex.
//	student_t a = {"Gigel",     "x", 1};
//	student_t b;
//	b.medie = a.medie;
//	b.nume = strdup(a.nume);
//	b.grupa = strdup(b.grupa);
//
//	b.medie = 2; // media lui b este 2, a lui a este tot 1
//	b.nume[0] = 'X'; // b.nume == "Xigel"
//					 // a.nume == "Gigel"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX 100 // lungimea celui mai lung sir folosit in acest program
				 // fac asta de lene, ca sa nu citesc lungimile de la tastatura

typedef struct {
	char *nume;  // pointer (semnifica un sir de caractere de lungime variabila)
	char *grupa; // pointer (semnifica un sir de caractere de lungime variabila)
	float medie;
} student_t;

void print_student(const student_t *s)
{
	printf("student: %s, grupa: %s, medie: %2.2f\n",
		   s->nume, s->grupa, s->medie);
}

void read_student(student_t *s)
{
	char word[NMAX]; // aici voi citi un cuvant cu scanf

	printf("nume = ");
	scanf("%s", word);
	s->nume = (char *)strdup(word); // fac propria copie a numelui

	printf("grupa = ");
	scanf("%s", word);
	s->grupa = (char *)strdup(word); // fac propria copie a grupei

	printf("medie = ");
	scanf("%f", &s->medie);
}

void copy_student(student_t *d, student_t *s)
{
	d->medie = s->medie;
	d->nume = (char *)strdup(s->nume);    // +1 alloc
	if (!d->nume) {
		fprintf(stderr, "strdup() failed\n");
		return;
	}
	d->grupa = (char *)strdup(s->grupa);  // +1 alloc
	if (!d->grupa) {
		fprintf(stderr, "strdup() failed\n");
		return;
	}
}

void release_resource(student_t *s)
{
	free(s->nume);   // -1 free
	free(s->grupa);  // -1 free

	// Practica buna este sa si setezi acesti POINTERI PE NULL
	s->nume = NULL;
	s->grupa = NULL;
}

// shallow copy - copy bit by bit
// se copiaza bit cu bit - la propriu!!!
void shallow_copy(void)
{
	printf("%s:%s()\n", __FILE__, __func__);

	student_t student;
	read_student(&student);
	print_student(&student);

	student_t alt_student;

	printf("\nshallow & nume[0] = 'X'\n");
	alt_student = student;
	alt_student.nume[0] = 'X';
	print_student(&student);
	print_student(&alt_student);
	printf("(schimbarea a afectat pe amandoi)\n");

	// eu am o singura data alocate stringurile in memorie, deci o data dau free
	release_resource(&student);
}

void deep_copy(void)
{
	printf("%s:%s()\n", __FILE__, __func__);

	student_t student;
	read_student(&student);
	print_student(&student);

	// deep copy - copy bit by bit
	// EXCEPTIE fac pointerii, unde nu vrem sa se copieze pointerul,
	// ci informatia spre care pointeaza acel pointer

	student_t alt_student;

	printf("\ndeepcopy & nume[0] = 'X'\n");
	copy_student(&alt_student, &student);
	alt_student.nume[0] = 'X';
	print_student(&student);
	print_student(&alt_student);
	printf("(schimbarea a afectat DOAR pe al doilea - EXACT CUM AM VRUT)\n");

	// acum are sens sa eliberez separat resursel (am alocate separat stringurile pt fiecare student)
	release_resource(&student);
	release_resource(&alt_student);
}

int main(void)
{
	shallow_copy();
	deep_copy();

	return 0;
}

// Compile:
// $ make
//
// Run:
// ./05-demo_deep_copy
// 05-demo_deep_copy.c:shallow_copy()
// nume = Gigel
// grupa = UCL
// medie = 13
// student: Gigel, grupa: UCL, medie: 13.00
//
// shallow & nume[0] = 'X'
// student: Xigel, grupa: UCL, medie: 13.00
// student: Xigel, grupa: UCL, medie: 13.00
// (schimbarea a afectat pe amandoi)
//
// 05-demo_deep_copy.c:deep_copy()
// nume = Gigel
// grupa = UCL
// medie = 13
// student: Gigel, grupa: UCL, medie: 13.00
//
// deepcopy & nume[0] = 'X'
// student: Gigel, grupa: UCL, medie: 13.00
// student: Xigel, grupa: UCL, medie: 13.00
// (schimbarea a afectat DOAR pe al doilea - EXACT CUM AM VRUT)
//
