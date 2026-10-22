// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	int numar = 305419896; // Exemplu de număr (0x12345678 în hexazecimal)
	unsigned char *bytePtr = (unsigned char *)&numar;

	printf("Numărul %d reprezentat byte cu byte este:\n", numar);

	for (int i = 0; i < sizeof(numar); i++) {
		printf("Byte %d: %p\n", i, bytePtr[i]);
	}

	return 0;
}

// TODO: exemplu cast - hai sa printam byte cu byte un tip intreg mai mare
