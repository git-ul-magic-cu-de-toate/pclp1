// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	int **a;

	*(*(a + 2) + 3) = 100;

	printf("%d %p\n", a[2][3], *(a + 100) + 3);

	return 0;
}

// TODO: deseneaza matrice alocata static.
// TODO: explica cum o accesam prin pointers.
// TODO: citire, afisare + suma
