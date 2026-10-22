// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	int v[3] = { 10, 20, 30 };

	// Acces normal
	printf("v[0]: %d\n", v[0]);  // Ar trebui să afișeze 10

	// Acces greșit (undefined behavior)
	printf("v[-1]: %d\n", v[-1]); // Acces la o locație nevalidă

	return 0;
}

// TODO: exemplu v[-1]
