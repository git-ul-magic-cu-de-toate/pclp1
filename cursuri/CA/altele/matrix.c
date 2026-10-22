// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include "matrix.h" // includem semnaturile functiilor de implementat

#include <stdio.h>

// Functie pentru citirea de la STDIN a unei matrice a, cu n x m elemente.
void scanf_matrix(int n, int m, int a[MATRIX_NMAX][MATRIX_NMAX])
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
}

// Functie pentru afisarea la STDOUT a unei matrice a, cu n x m elemente.
void printf_matrix(int n, int m, int a[MATRIX_NMAX][MATRIX_NMAX])
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Functie pentru calcul produs matrice: c = a * b,
// unde a, b sunt matrice de dimensiuni (n x m), respectiv (m x p).
void compute_product_matrix(int n, int m, int p,
							int a[MATRIX_NMAX][MATRIX_NMAX],
							int b[MATRIX_NMAX][MATRIX_NMAX],
							int c[MATRIX_NMAX][MATRIX_NMAX])
{
	// tmp = O_NMAX(matrice nula de dimensiune maxima)
	int tmp[MATRIX_NMAX][MATRIX_NMAX] = {0};

	// Aplicam algoritmul de inmultire: tmp = a * b.
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p; ++j) {
			for (int k = 0; k < m; ++k) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	// Copiam rezultatul temporar in c: c = tmp.
	copy_matrix(n, p, tmp, c);
}

// Functie pentru calcul putere matrice: p = a ^ k,
// unde p si a sunt matrice n x n, iar k este un numar natural.
void compute_power_matrix(int n, int a[MATRIX_NMAX][MATRIX_NMAX], int k,
						  int p[MATRIX_NMAX][MATRIX_NMAX])
{
	// tmp = I(n)
	int tmp[MATRIX_NMAX][MATRIX_NMAX];
	set_identity_matrix(n, tmp); // tmp = I(n)

	// Aplicam algoritmul de putere, prin inmultire repetata.
	for (int i = 1; i <= k; ++i) {
		compute_product_matrix(n, n, n, a, tmp, tmp); // <=> tmp *= a;
	}

	// Copiam inapoi rezultatul: p = tmp.
	copy_matrix(n, n, tmp, p);
}

// Functie pentru copiere: b = a.
void copy_matrix(int n, int m,
				 int a[MATRIX_NMAX][MATRIX_NMAX],
				 int b[MATRIX_NMAX][MATRIX_NMAX])
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			b[i][j] = a[i][j];
		}
	}
}

// Functie care initializeaza pe a cu matricea identitate.
void set_identity_matrix(int n, int a[MATRIX_NMAX][MATRIX_NMAX])
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = (i == j ? 1 : 0);
		}
	}
}
