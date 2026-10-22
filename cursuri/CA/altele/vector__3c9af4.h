// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

// Explicatie in laborator pentru pragma once:
// ne ajuta sa nu includem de mai multe ori acest fisier.
// (https://ocw.cs.pub.ro/courses/programare/laboratoare/lab13),
#pragma once

// Putem include alte biblioteci de care depindem (stdio, math etc)
#include <stdio.h>

// Orice vector din acest modul, are maxim 1000 de elemente.
#define VECTOR_NMAX 1000

// Declaram semnaturi de functii:

// Functie pentru citirea de la STDIN a unui vector v, cu n elemente.
void scanf_vector(int n, int v[VECTOR_NMAX]);

// Functie pentru afisarea la STDOUT a unui vector v, cu n elemente.
void printf_vector(int n, int v[VECTOR_NMAX]);

// Functie pentru sortarea crescatoare a unui vector v, cu n elemente.
void sort_vector(int n, int v[VECTOR_NMAX]);

// Functie pentru inversarea unui vector v, cu n elemente.
void reverse_vector(int n, int v[VECTOR_NMAX]);
