// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 100

int v[NMAX];

// Functie pentru citirea de la STDIN a unui vector v, cu n elemente.
void scanf_vector(int n, int *v)
{
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

// Functie pentru afisarea la STDOUT a unui vector v, cu n elemente.
void printf_vector(int n, int *v)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Functie pentru inversarea unui vector v, cu n elemente.
void reverse_vector(int n, int *v)
{
    for (int i = 0; i < n / 2; i++) {
        v[i] ^= v[n - i - 1] ^= v[i] ^= v[n - i - 1]; // Tema de curs. Ce e vrajitoria asta? Ce operator este ^?
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    scanf_vector(n, v);
    reverse_vector(n, v);
    printf_vector(n, v);

    return 0;
}

// TODO: Reparam programul anterior mutand vectorul ca si variabila globala, doar ca sa vedem ca putem.
// TODO: NU folosim variabile globale! Din motivele discutate anterior la curs.
// Concluzie: Singura solutie stiuta pana acum e sa declaram vectorul global. NU FACEM ASTA!
// Ne trebuie altceva atunci... Ce?
