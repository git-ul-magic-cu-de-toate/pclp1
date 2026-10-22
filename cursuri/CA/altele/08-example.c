// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int *f(int n)
{
	static int g;

	if (n > 0) {
		return &g;
	}

	return NULL;
}

int main(void)
{
	// conventie: daca nu avem cu se sa initializam aici un pointer
	// il initializam cu NULL
	int *p = NULL;

	// ...
	// ... va imaginati ca era cod aici
	// ...

	// apelam o functie care ar trebuie sa ne dea un pointer VALID
	p = f(1);
	if (!p) { // daca e INVALID
		printf("Pointer invalid\n"); // eroare
		return -1;
	}

	// altfel e pointer valid, deci il pot DEREFENTIA (*p)
	*p = 180;
	printf("Am stocat in memoria la adresa %p numarul %d\n", p, *p);

	return 0;
}
