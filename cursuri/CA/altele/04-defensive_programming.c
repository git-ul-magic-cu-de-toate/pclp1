// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int *v = malloc(n * sizeof(int));
	v[0] = -1; // ce este gresit? ce putem face: hint programare defensiva
	free(v);

	return 0;
}

// TODO: Ce lipseste programului sa fie un program corect?
