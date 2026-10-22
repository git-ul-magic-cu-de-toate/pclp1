// Copyright 2024 Darius Neatu (neatudarius@gmail.com)
#include <stdio.h>

// Exemplu cu macro-uri complexe definite pe mai multe linii.
// SWAP -> interschimba valorile a doua variabile
#define SWAP_INT(a, b) \
    do {               \
        a ^= b;        \
        b ^= a;        \
        a ^= b;        \
    } while (0)
// De ce folosim \ la finalul fiecarei linii in macro-uri multiline? Pentru a spune compilatorului ca macro-ul continua pe urmatoarea linie.
// De ce folosim do { ... } while (0) in macro-uri multiline? Pentru a evita problemele legate de scopul variabilelor si de evaluarea expresiilor.
// Limitare: SWAP_INT e doar pentru tipul int (sau alte tipuri de date intregi).

// Putem defini un macro care sa interschimbe valorile a doua variabile de orice tip.
// SWAP -> interschimba valorile a doua variabile
#define SWAP(a, b, type) \
    do {                 \
        type aux = a;    \
        a = b;           \
        b = aux;         \
    } while (0)
// a si b sunt de tip type, iar aux este de tip type.
// type este un parametru de tip, care poate fi orice tip de date! (int, float, char, double, struct, etc.)
// NOTA! Un macro nu este o functie, deci nu are tipuri de date. Macro-urile sunt text, care se inlocuiesc inainte de compilare,
// deci pot primit si un tip de date ca parametru.

// Exemplu de structura de date.
typedef struct student_t {
    char nume[50];
    int varsta;
} student_t;

void test_swap_int(void)
{
    // Exemplu de utilizare SWAP_INT.
    int x = 10, y = 20;
    printf("Inainte de interschimbare: x = %d, y = %d\n", x, y);
    SWAP_INT(x, y);
    printf("Dupa interschimbare: x = %d, y = %d\n", x, y);
}

void test_swap(void)
{
    // Exemplu de utilizare SWAP.
    // - float:
    float a = 3.14, b = 2.71;
    printf("Inainte de interschimbare: a = %f, b = %f\n", a, b);
    SWAP(a, b, float);
    printf("Dupa interschimbare: a = %f, b = %f\n", a, b);
    // - char:
    char c = 'a', d = 'b';
    printf("Inainte de interschimbare: c = %c, d = %c\n", c, d);
    SWAP(c, d, char);
    printf("Dupa interschimbare: c = %c, d = %c\n", c, d);
    // - student_t:
    student_t s1 = { "Ana", 20 }, s2 = { "Ion", 22 };
    printf("Inainte de interschimbare: s1.nume = %s, s1.varsta = %d, s2.nume = %s, s2.varsta = %d\n", s1.nume, s1.varsta, s2.nume, s2.varsta);
    SWAP(s1, s2, student_t);
    printf("Dupa interschimbare: s1.nume = %s, s1.varsta = %d, s2.nume = %s, s2.varsta = %d\n", s1.nume, s1.varsta, s2.nume, s2.varsta);
}

int main(void)
{
    test_swap_int();
    test_swap();
    return 0;
}

// TODO 1: Rulati codul si observati ce se intampla in functia test_swap_int()!
// TODO 2: Rulati codul si observati ce se intampla in functia test_swap()!
