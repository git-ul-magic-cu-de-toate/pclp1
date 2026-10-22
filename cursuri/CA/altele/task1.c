// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include "vector.h" // includ suport sa port lucra cu vectori
#include "matrix.h" // includ suport sa port lucra cu matrice

void test_vector(void)
{
	// Citesc n, v (vector cu n elemente),
	// il sortez, il afisez, il inversez, il afisez.
	int n;
	scanf("%d", &n);

	int v[VECTOR_NMAX];
	scanf_vector(n, v);

	// Sortez si afisez.
	sort_vector(n, v);
	printf_vector(n, v);

	// Inversez si afisez.
	reverse_vector(n, v);
	printf_vector(n, v);
}

void test_matrix(void)
{
	// Citesc n, a (matrice n x n), k. Calculez si afisez a^k.
	int n, k;
	scanf("%d%d", &n, &k);

	int a[MATRIX_NMAX][MATRIX_NMAX];
	scanf_matrix(n, n, a);

	// Calculez a = a^k, apoi afisez.
	compute_power_matrix(n, a, k, a);
	printf_matrix(n, n, a);
}

int main(void)
{
	test_vector();
	test_matrix();
	return 0;
}
