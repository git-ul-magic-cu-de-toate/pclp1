// Copyright 2024 Darius Neatu (neatudarius@gmail.com)
#include <stdio.h>

// Exemplu compilare conditionala.
// Detectare system de operare: Windows, Linux, Mac.
// Syntaxa:
// #if defined(__linux__) // explicatie: daca simbolul __linux__ este definit, inseamna ca compilam pe Linux, deci compilam codul din interiorul acestui bloc.
// // ...
// // ...
// // ...
// #elif defined(__APPLE__) // explicatie: daca simbolul __APPLE__ este definit, inseamna ca compilam pe Mac, deci compilam codul din interiorul acestui bloc.
// // ...
// // ...
// // ...
// #elif defined(_WIN32) // explicatie: daca simbolul _WIN32 este definit, inseamna ca compilam pe Windows, deci compilam codul din interiorul acestui bloc.
// // ...
// // ...
// // ...
// #else // explicatie: daca nu stim pe ce sistem de operare compilam, afisam un mesaj de eroare.
// #error "Nu stiu ce sistem de operare e asta!"
// #endif
//
// Directiva #if este folosita pentru a evalua o expresie conditionala.
// Directiva #elif este folosita pentru a evalua o alta expresie conditionala, daca prima expresie conditionala este falsa.
// Directiva #else este folosita pentru a evalua o alta expresie conditionala, daca niciuna dintre expresiile conditionale anterioare nu este adevarata.
// Directiva #error este folosita pentru a afisa un mesaj de eroare si a opri compilarea.
// Directiva #warning este folosita pentru a afisa un mesaj de avertizare.

#if defined(__linux__)
#define MY_OS "Linux"
#elif defined(__APPLE__)
#define MY_OS "Mac"
#elif defined(_WIN32)
#define MY_OS "Windows"
#else
#error "Unknown OS!"
#endif

int main(void)
{
    printf("MY_OS = %s\n", MY_OS);
    return 0;
}

// TODO 1: Rulati codul si observati ce se intampla!
// Vom compila acest cod pe Linux si Mac/Windows.
// Vom observa ce sistem de operare este detectat.
//
// TODO 2: Modificati codul astfel incat sa detecteze sistemul de operare pe care rulati codul si
// sa se genereze un warning care sa sublinieze sistemul de operare detectat.
// Hint: folositi directiva #warning.
