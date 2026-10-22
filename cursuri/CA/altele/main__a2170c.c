// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include "vector.h" // "biblioteca" de procesare de vectori

int main(void)
{
    int n;
    scanf("%d", &n);
    int v[NMAX];
    read_vector(n, v);
    print_vector(n, v);
    return 0;
}

//
// TODO 1: Compilati si rulati codul!
// $ gcc -Wall -Wextra main.c vector.c -o main
// $ ./main
// 4
// 1 -1 2 -2
// 1 -1 2 -2
//
// TODO 2: Analizati codul si intelegeti ce face! De ce am folosit #include "vector.h" si nu #include <vector.h>?
// De ce am pus doar semnatura functiilor in vector.h si nu si implementarea?
// De ce avem garzi in vector.h?
//
// TODO 3: Adaugarati o functie in vector.c care sa sorteze un vector de intregi folosind bubble sort, apoi apelati-o in main.c.
//
// TODO 4: Compilati si rulati codul!
//