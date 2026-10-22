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

	// Citesc si afisez v.
	int v[VECTOR_NMAX];
	scanf_vector(n, v);
	printf_vector(n, v);
}

void test_matrix(void)
{
	// Citesc n, m, si o matrice a cu n x m elemente.
	int n, m;
	scanf("%d%d", &n, &m);

	// Citesc si afisez a.
	int a[MATRIX_NMAX][MATRIX_NMAX];
	scanf_matrix(n, m, a);
	printf_matrix(n, m, a);
}

int main(void)
{
	test_vector();
	test_matrix();
	return 0;
}
