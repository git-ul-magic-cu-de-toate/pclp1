// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

// Explicatie in laborator pentru pragma once:
// ne ajuta sa nu includem de mai multe ori acest fisier.
// (https://ocw.cs.pub.ro/courses/programare/laboratoare/lab13),
#pragma once

// Putem include alte biblioteci de care depindem (stdio, math etc)
#include <stdio.h>

// Orice matrice din acest modul, are maxim 1000x1000 de elemente.
#define MATRIX_NMAX 100

// Declaram semnaturi de functii:

// Functie pentru citirea de la STDIN a unei matrice a, cu n x m elemente.
void scanf_matrix(int n, int m, int a[MATRIX_NMAX][MATRIX_NMAX]);

// Functie pentru afisarea la STDOUT a unei matrice a, cu n x m elemente.
void printf_matrix(int n, int m, int a[MATRIX_NMAX][MATRIX_NMAX]);

// Functie pentru calcul produs matrice: c = a * b,
// unde a, b sunt matrice de dimensiuni (n x m), respectiv (m x p).
void compute_product_matrix(int n, int m, int p,
							int a[MATRIX_NMAX][MATRIX_NMAX],
							int b[MATRIX_NMAX][MATRIX_NMAX],
							int c[MATRIX_NMAX][MATRIX_NMAX]);

// Functie pentru calcul putere matrice: p = a ^ k,
// unde p si a sunt matrice n x n, iar k este un numar natural.
void compute_power_matrix(int n, int a[MATRIX_NMAX][MATRIX_NMAX], int k,
						  int p[MATRIX_NMAX][MATRIX_NMAX]);

// Functie pentru copiere: b = a.
void copy_matrix(int n, int m,
				 int a[MATRIX_NMAX][MATRIX_NMAX],
				 int b[MATRIX_NMAX][MATRIX_NMAX]);

// Functie care initializeaza pe a cu matricea identitate.
void set_identity_matrix(int n, int a[MATRIX_NMAX][MATRIX_NMAX]);
