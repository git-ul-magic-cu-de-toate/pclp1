// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	int *a;             // variabila de tip pointer: pe scurt pointer
	int b = 5;          // variabila de tip numar intreaga: pe scurt intreg
	char *c;            // pointer catre un caracter (sau sir de caractere)
	void *buff = NULL;  // pointer catre void, initializat la NULL

	printf("initial\n");
	printf("a  = %p, *a = BUBA"
		" (NU am voie sa pun * pe un pointer neinitializat)\n", a);
	printf("&b = %p,  b = %d\n", &b, b);

	// *a = 1; // asignare invalida pentru ca a este un pointer neinitializat
	// gcc semnaleaza acest lucru
	// demo-01.c:10:5: warning: ‘a’ is used
	//   uninitialized in this function [-Wuninitialized]

	// a ia adresa variabilei b -> a este initializat
	a = &b;
	printf("\nexecute: a = &b\n");
	printf("a  = %p, *a = %d\n", a, *a);
	printf("&b = %p,  b = %d\n", &b, b);

	// Continutul memoriei de la adresa a (care a fost initializata mai sus)
	// ia valoarea 5.
	// Acest lucru este echivalent cu "b = 5;"
	*a = 5; // atribuire valida
	printf("\nexecute: *a = 5\n");
	printf("a  = %p, *a = %d\n", a, *a);
	printf("&b = %p,  b = %d\n", &b, b);

	return 0;
}
