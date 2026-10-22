// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	// Stocarea datelor la o anumită adresă;
	// Citirea datelor de la o anumită adresă
	int *p, y = 2, x, z;

	p = &z;
	printf("adresa lui z  = %p, iar p este tot %p\n", &z, p);
	*p = y; // Ia valoarea y si pune-o la adresa indicata de p
	x = *p; // Ia valoarea de la adresa indicata de p si pune-o in variabila x
	printf("%d %d\n", x, y);

	// fie 2 vectori
	int v[5] = {1, 2, 3, 4, 5};
	int w[5]; // neinitializat
	// vreau sa copiez elementele din v in w folosind 2 pointeri de tip int
	// (evident ca o pot face si fara pointer - acesta este un exemplu didactic)

	// v si w sunt pointeri (v = &v[0], w = &w[0])
	int *source = v, *destination = w;
	for (int i = 0; i < 5; ++i) {
		*destination = *source;
		destination++;
		source++;

		// precedentele 3 instructiuni le pot scrie intr-una singura
		// *destination++ = *source++;
		// vezi tabel lab 2 cu precedenta operatorilor
	}

	// afisez w
	for (int i = 0; i < 5; ++i) {
		printf("%d ", w[i]);
	}
	printf("\n");

	return 0;
}
