// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

// Definim un guard pentru a evita includerea multipla a header-ului.
// Conventie: numele guardului este format din numele header-ului, in uppercase, cu caracterele speciale inlocuite cu _.
// Exemplu: pentru vector.h, guardul este VECTOR_H.
// Exemplu: pentru GIGEL/docs/2024/tema3/vector.h, guardul este GIGEL_DOCS_2024_TEMA3_VECTOR_H.
#ifndef VECTOR_H
#define VECTOR_H

// Dimensiunea maxima a unui vector din biblioteca.
#define NMAX 100

// Functii pentru citirea si afisarea unui vector.
void read_vector(int n, int v[NMAX]);
void print_vector(int n, int v[NMAX]);

#endif // VECTOR_H
