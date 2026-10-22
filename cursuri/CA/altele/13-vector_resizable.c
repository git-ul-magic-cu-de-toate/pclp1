// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>

// Functie pentru afisarea la STDOUT a unui vector v, cu n elemente.
void printf_vector(int n, int *v)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(void)
{

    int n = 0;
    int *v = NULL;

    int x = -1;
    while (scanf("%d", &x)) { // sau while (scanf("%d", &x) == 1) - https://man7.org/linux/man-pages/man3/scanf.3.html
        if (x < 0) {
            break;
        }

        // alocam un vector cu un element mai mult
        int *tmp = (int *)realloc(v, (n + 1) * sizeof(int));
        if (!tmp) {
            free(v);
            return 2; // allocation failed, ups
        }
        v = tmp;

        // Adaugam elementul  pe ultima pozitie, care este noual
        v[n++] = x;
    }

    printf_vector(n, v);

    free(v);
    return 0;
}

// TODO: Se citește un șir de numere naturale până la întâlnirea unui număr negativ.
// Dorim să citim șirul și să îl salvăm într-un vector.
// Dorim să gestionăm eficient memoria pe tot parcursul programului!
// https://man7.org/linux/man-pages/man3/malloc.3.html

//$ make && ./13-vector_resizable
// 1
// 2
// 3
// 4
// 10
// 20
// 30
// -1
// 1 2 3 4 10 20 30

// $ make && valgrind ./13-vector_resizable
// gcc -Wall -Wextra -o 13-vector_resizable 13-vector_resizable.c -lm
// ==251968== Memcheck, a memory error detector
// ==251968== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
// ==251968== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
// ==251968== Command: ./13-vector_resizable
// ==251968==
// 1
// 2
// 3
// 4
// 10
// 20
// 30
// -1
// 1 2 3 4 10 20 30
// ==251968==
// ==251968== HEAP SUMMARY:
// ==251968==     in use at exit: 0 bytes in 0 blocks
// ==251968==   total heap usage: 9 allocs, 9 frees, 2,160 bytes allocated
// ==251968==
// ==251968== All heap blocks were freed -- no leaks are possible
// ==251968==
// ==251968== For lists of detected and suppressed errors, rerun with: -s
// ==251968== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
// TODO: Este OK sa avem 9 alocari? Cate stim sigur ca am facut noi?
//       Dar eliberari de memorie?
