// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include "vector.h" // includem semnaturile functiilor de implementat

#include <stdio.h>
#include "util.h"

// Functie pentru citirea de la STDIN a unui vector v, cu n elemente.
void scanf_vector(int n, int v[VECTOR_NMAX])
{
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
}

// Functie pentru afisarea la STDOUT a unui vector v, cu n elemente.
void printf_vector(int n, int v[VECTOR_NMAX])
{
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

// Functie pentru sortarea crescatoare a unui vector v, cu n elemente.
// Complexitate: O(n^2).
void sort_vector(int n, int v[VECTOR_NMAX])
{
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (v[i] > v[j]) {
				swap_int(&v[i], &v[j]);
			}
		}
	}
}

// Functie pentru inversarea unui vector v, cu n elemente.
void reverse_vector(int n, int v[VECTOR_NMAX])
{
	for (int i = 0; i < n / 2; i++) {
		swap_int(&v[i], &v[n - i - 1]);
	}
}
