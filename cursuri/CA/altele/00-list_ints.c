// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h> // printf
#include <stdarg.h> // va_list, va_arg,
                    // va_start,va_end

// Semnatura functie variadica:
// - Tipul de return nu difera fata de o functie normala.
// - Primii parametri sunt fixi, iar ceilalti sunt variabili.
// - Folosim va_list, va_start, va_arg, va_end pentru a parcurge lista de parametri.
// Exemplu - list_ints: afiseaza o lista de numere intregi pana la un numar negativ
//  - Functia nu intoarce nimic (void).
//  - Primul parametru este fixat (int first).
//  - Functia are un numar variabil de parametri (...).
void list_ints(int first, ...) {
    // Tratam cazul special cand nu avem nici un numar (in afara de delimitator).
    if (first < 0) {
        printf("No numbers present (besides terminator)\n");
        return;
    }

    // Declaram lista de parametri variabili.
    va_list args;

    // Initializam lista de parametri variabili.
    // Note: va_start() poate aloca memorie pentru lista de parametri variabili,
    // deci trebuie sa apelam va_end() pentru a elibera memoria.
    va_start(args, first);

    // Parcurgem lista de parametri variabili.
    printf("These are the numbers (excluding terminator): ");
    int current = first; // Primul numar este fix si exista!
    while (current >= 0) {
        // Afiseaza numarul curent.
        printf("%d ", current);

        // Extrage urmatorul numar intreg din lista.
        current = va_arg(args, int);
    }
    printf("\n"); // Afisam un newline la final.

    // Eliberam lista de parametri variabili.
    va_end(args);
}

int main() {
    list_ints(-1); // nimic de afisat
    list_ints(128, 512, 768, 4096, -1); // afiseaza  pana la -1
    list_ints(128, 512, 768, 4096, -1, -1); // afiseaza  pana la -1
    list_ints('a', 'b', 0xa, 0xb, -2); // afiseaza pana la -2; apel corect deoarece castul la int este valid
    list_ints(1, -1); // afiseaza pana la -1
    list_ints(1, 2, 3, -1, 1, 2, 3); // afiseaza pana la -1
    return 0;
}

// TODO 1: Compilati si rulati codul!
// $ make
// $ ./00-list_ints
// No numbers present (besides terminator)
// These are the numbers (excluding terminator): 128 512 768 4096
// These are the numbers (excluding terminator): 128 512 768 4096
// These are the numbers (excluding terminator): 97 98 10 11
// These are the numbers (excluding terminator): 1
// These are the numbers (excluding terminator): 1 2 3
