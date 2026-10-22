// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	// x este un numar intreg iniatilizat cu o constanta hexa
	int x = 0xCAFEBABE;

	// pi e un pointer de tipul int initalizat cu adresa lui x
	// deci pi + 1 sare cu 4 bytes (sizeof(int))
	// *pi reprezinta int-ul de la adresa indicata de pi
	int *pi = &x;

	// pc e un pointer de tipul char initalizat cu adresa lui x
	// deci pc + 1 sare cu 1 bytes (sizeof(char))
	// *pc reprezinta char-ul de la adresa indicata de pc
	char *pc = (char *)&x;

	printf("&x  = %p\n", &x);
	printf(" x  = %X\n", x);

	printf("pi  = %p\n", pi);
	printf("*pi = %X\n", *pi);

	for (int i = 0; i < 4; ++i) {
		printf("\n incerc sa extrag byte-ul %d\n", i);
		printf("*pc = %X\n", (unsigned char)*pc);
		printf("pc  = %p\n", pc);

		++pc;
	}

	return 0;
}
