// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 100

// man stdio.h
//
// FILE -> stdio.h
//
// typedef struct {
//      ...
// } FILE;
//
// Obs: utilizare doar cu functii din stdio.h care mereu primesc un FILE*
//
// mapare: 1 fisier pe disc <-> 1 structura FILE
//
// operatii uzuale cu fisier:
// - fopen() (deschidere fisier existent SAU creare fisier pe disc; in ambele cazuri se face alocare de structura)
// - fclose() (inchidere fisier pe disc + dealocare structura)
// - citire/scriere
// - mutare in fisier
//
//
// Exista 3 variabile globale in stdio.h.
// FILE* stdin;
// FILE* stdout;
// FILE* stderr;
//

int main(void)
{
	int x;
	char s[NMAX];

	// scanf, printf <-> fscanf(file, ), fprintf(file, )
	// scanf("...", ...) <=> fscanf(stdin, "...", ...)
	// printf("...", ...) <=> fprintf(stdout, "...", ...)

	fscanf(stdin, "%d%s", &x, s);     // <=> scanf("%d%s", &x, s);
	fprintf(stdout, "%d %s\n", x, s); // printf("%d %s\n", x, s);

	return 0;
}

// TODO: Refacem exemplul anterior cu citire si afisare din/in fisiere text.
// Momentan consideram ca fisierele sunt doar text, deci fisiere.
