// Copyright 2024 Darius Neatu (neatudarius@gmail.com)
#include <stdio.h>

// Exemplu cu macro-uri simple.
// - PI -> 3.14159
// - MAX -> 100
// - MSG -> "Hello, world!"
// Convention: uppercase cu underscore intre cuvinte
#define PI 3.14159
#define MAX 100
#define MSG "Hello, world!"

#define NMAX 1000

int main(void)
{
    printf("Valoarea lui PI este: %f\n", PI);
    printf("Valoarea lui MAX este: %d\n", MAX);
    printf("Mesajul este: %s\n", MSG);

    int v[NMAX], w[NMAX];
    // int v[NMAX], w[NMAX];

    return 0;
}

// TODO 1: Rulati codul si observati ce se intampla!
// $ gcc -E 01-simple_macros.c | tail -20
// # 959 "/usr/include/stdio.h" 3 4
// extern int __uflow (FILE *);
// extern int __overflow (FILE *, int);
// # 983 "/usr/include/stdio.h" 3 4
//
// # 3 "01-simple_macros.c" 2
// # 14 "01-simple_macros.c"
//
// # 14 "01-simple_macros.c"
// int main(void)
// {
//     printf("Valoarea lui PI este: %f\n", 3.14159);
//     printf("Valoarea lui MAX este: %d\n", 100);
//     printf("Mesajul este: %s\n", "Hello, world!");
//
//     int v[1000], w[1000];
//
//
//     return 0;
// }
// De ce nu se afiseaza valoarea lui PI, MAX si MSG?
// De ce linia cu comentariul nu este afisata?
//
