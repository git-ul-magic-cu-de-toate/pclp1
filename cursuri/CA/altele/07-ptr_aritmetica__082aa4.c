// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	int array[] = { 10, 20, 30, 40, 50 };
	int *ptr = array; // Pointer la primul element din array

	// Afișăm elementele din array folosind aritmetica pointerilor
	for (int i = 0; i < 5; i++) {
		printf("Elementul %d este: %d\n", i, *(ptr + i));
	}

	// Exemplu de mutare a pointerului
	ptr += 2; // Acum pointează la al treilea element (30)
	printf("Pointerul mutat pointează la: %d\n", *ptr);

	return 0;
}

// TODO: exemplu aritmetica pointers
