// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <string.h>

#define NMAX 100

void print_ints(char *name, int n, int *v)
{
	printf("%10s:", name);
	for (int i = 0; i < n; ++i) {
		printf("%5d ", v[i]);
	}
	printf("\n");
}

void print_double(char *name, int n, double *v)
{
	printf("%10s:", name);
	for (int i = 0; i < n; ++i) {
		printf("%10.5lf ", v[i]);
	}
	printf("\n");
}

void print_floats(char *name, int n, float *v)
{
	printf("%10s:", name);
	for (int i = 0; i < n; ++i) {
		printf("%10.5f ", v[i]);
	}
	printf("\n");
}

void print_chars(char *name, int n, char *v)
{
	printf("%10s:", name);
	for (int i = 0; i < n; ++i) {
		printf("%c ", v[i]);
	}
	printf("\n");
}

int main(void)
{
    // copiere stringuri (C-string)
    // strcpy(dst, src) - copiaza src in dst
    // obs: dst si src NU au voie sa se suprapuna in memorie!
	char src[NMAX] = "gigel e pe val";
	char dst[NMAX];
	strcpy(dst, src); // src e un C-string, dst devine un C-string

    // ce facem daca vrem sa copiam un vector de int-uri? dar un vector de doubles? dar de ponei?
    // ce au toate acestea in comun? pai toate pot fi privite ca un sir de bytes
    // (si nimic mai mult! - un size si un sir de bytes)
    // pentru a manipula SIRURI DE BYTES, exista functiile de forma mem_*

    // memcpy(dst, src, num) - copiaza num bytes din src in dst
    // obs: dst si src NU au voie sa se suprapuna in memorie!
	int isrc[NMAX] = {10, 20, 30, 40, 50};
	int idst[NMAX];
	int inum = 5; // ne intereseaza sa copiam inum int-uri din isrc in idst
	memcpy(idst, isrc, inum * sizeof(int)); // ca la malloc, num reprezinta numarul de bytes!
	printf("copy ints\n");
	print_ints("isrc", inum, isrc);
	print_ints("idst", inum, idst);

    // obs: strcpy e particularizre de memcpy
    // daca am copiat src in dst (care sunt C-strings) cu mempcy am face asa
    // memcpy(dst, src, strlen(src) + 1); // trebuie sa spunem explicit ca vrem sa copiez si terminatorul de sir

	double dsrc[NMAX] = {10.10, 20.20, 30.30};
	double ddst[NMAX];
	int dnum = 3; // ne intereseaza sa copiam inum int-uri din isrc in idst
	memcpy(ddst, dsrc, dnum * sizeof(double)); // ca la malloc, num reprezinta numarul de bytes!
	printf("copy double\n");
	print_double("dsrc", dnum, dsrc);
	print_double("ddst", dnum, ddst);

    // memset(dst, byte, num) - primii num bytes din dst vor fi initializati cu byte
	printf("setting ints to 0\n");
	print_ints("idst", inum, idst);
	memset(idst, 0, inum * sizeof(int)); // seteaza toti bytes pe 0 <-> cu idst[i] = 0
	print_ints("fdst", inum, idst);

    // memmove(dst, src, num) - la fel ca la memcpy, doar ca copiera se face ca si cum exista un buffer temporar
    // obs: dst si src AU VOIE sa se suprapuna in memorie, deoarce logica este urmatoarea:
    //  1. tmp = src
    //  2. dst = tmp

    // Tema: Gasiti un exemplu pentru care memcpy nu merge, dar memmove da.
    // Puteti porni de la un exemplu in care strcpy este apelat gresit!
	printf("Exemplu eronat de folosire strcpy:\n");
	char s[NMAX] = "_mere";
	strcpy(s, s + 1); // apelare gresita, intrucat src si dst se suprapun in memorie -> undefined behaviour
	printf("s=\"%s\" expected \"mere\"\n", s);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./09-mem
// copy ints
//       isrc:   10    20    30    40    50
//       idst:   10    20    30    40    50
//
// copy double
//       dsrc:  10.10000   20.20000   30.30000
//       ddst:  10.10000   20.20000   30.30000
//
// setting ints to 0
//       idst:   10    20    30    40    50
//       fdst:    0     0     0     0     0
//
// Exemplu eronat de folosire strcpy:
// s="mree" expected "mere"
//
