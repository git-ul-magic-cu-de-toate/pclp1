// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	int n = 5;
	int arr[10];

	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", *(arr + i));
	}

	printf("\n");

	return 0;
}

// TODO: deseneaza vector alocat static.
// TODO: explica cum il accesam prin pointers.
// TODO: citire, afisare + cautare binara (daca nu e timp, fa suma :D)
