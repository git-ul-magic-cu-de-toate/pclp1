// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 100

int main(void)
{
	// NU putem citi vectori printr-un singur apel de scanf

	// Exista insa o SINGURA exceptie
	// Putem citi un sir de caractere!!!

	// v este un vector de caractere
	char v[NMAX];

	// v e pointer catre primul element - deci nu are sens sa pun &v
	scanf("%s", v);

	// afisez sirul de caractere stocat in v
	printf("%s\n", v);

	return 0;
}
