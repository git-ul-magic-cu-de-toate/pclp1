// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

// Să se scrie o funcție polymorphic_sort care poate sorta un array de elemente.
//
// Hint: Funcția va primi ca argumente un pointer la începutul array-ului, un număr de elemente,
// dimensiunea unui element și un pointer la o funcție de comparare a două elemente.

#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy

// cmp_func_ptr_t este un pointer la o funcție care compară două elemente (generice).
// de exemplu, pentru a sorta un array de int-uri,
//      cmp_func_ptr_t va fi un pointer la o funcție care compară două int-uri.
// de exemplu, pentru a sorta un array de float-uri,
//      cmp_func_ptr_t va fi un pointer la o funcție care compară două float-uri.
// Reuniunea tuturor acestor funcții de comparare este cmp_func_ptr_t.
typedef int (*cmp_func_ptr_t)(const void *, const void *);

// Functie polimorfica de swap.
// Implementare 1: folosire buffer temporar - tmp.
// Implementare 2: fara buffer temporar - copiere byte cu byte.
// TODO: Care e mai bună? Ce trade-off alegem și când?
void swap_polymorphic(void *a, void *b, int n_bytes)
{
    unsigned char* tmp = (unsigned char*) malloc(n_bytes * sizeof(unsigned char*));
    if (!tmp) {
        fprintf(stderr, "malloc failed - swap_polymorphic failed.\n");
        return;
    }

    // actual swap
    memcpy(tmp, a, n_bytes); // tmp = a;
    memcpy(a, b, n_bytes);   // a = b;
    memcpy(b, tmp, n_bytes); // b = tmp;

    free(tmp);
}

// Funcția de sortare polymorphic_sort primește ca argumente:
// - array: un pointer la începutul array-ului
// - num_elements: numărul de elemente din array
// - element_size: dimensiunea unui element din array
// - cmp: un pointer la o funcție care compară două elemente
void polymorphic_sort(void *array, size_t num_elements, size_t element_size, cmp_func_ptr_t cmp)
{
    // bytes este un pointer către aceeași zona de memorie unde putem
    // accesa datele byte cu byte
    unsigned char *bytes = (unsigned char *) array;
    // La ce este util? accesăm byte-ul cu numărul i cu bytes[i],
    // iar adresa acelui bytes este expresia: bytes + i

    // Schițăm algoritmul general de sortare.
    for (size_t i = 0; i < num_elements; ++i) {
        for (size_t j = i + 1; j < num_elements; ++j) {
            unsigned char *array_i = bytes + i * element_size;     // fixăm "array[i]"
            unsigned char *array_j = bytes + j * element_size;     // fixăm "array[j]"

            if (cmp(array_i, array_j) > 0) {                       // simulam "array[i] > array[j]"
                swap_polymorphic(array_i, array_j, element_size);  // facem interschimbarea elementelor
                                                                   // care incep la adresele indicare si
                                                                   // care au acelasi numar de bytes!
            }
        }
    }
}

// Funcție de comparare a două int-uri, date prin 2 pointers de tip void *.
// const void *a - pointer catre prima variabila.
// const void *a - pointer catre a doua variabila.
// Apelantul functiei nu stie ca datele sunt int <=> void *.
// NU avem nevoie sa modificăm datele în funcție <=> const.
//
// Conventie: pornind de la echivalenta a < b <=> a - b < 0 (aici a si b sunt 2 int-uri),
// functia va returna 3 tipuri de valori:
// * +1 (sau >0) dacă a > b
// * -1 (sau <0) dacă a < b
// *  0 (sau <0) dacă a == b
int cmp_int(const void *a, const void *b)
{
    // a și b sunt pointers.

    // actual_a and actual_b sunt valorile de tip int de la capătul pointerilor.
    int actual_a = *(int *) a;
    int actual_b = *(int *) b;

    return actual_a - actual_b;

    // // Echivalent logic cu:
    // if (actual_a < actual_b) {
    //     return -1;
    // } else if (actual_a > actual_b) {
    //     return +1;
    // } else {
    //     return 0;
    // }
}

// Funcție de comparare a două double-uri.
// Convenția de mai sus.
int cmp_double(const void *a, const void *b)
{
    double actual_a = *(double *) a;
    double actual_b = *(double *) b;

    if (actual_a < actual_b) {
        return -1;
    } else if (actual_a > actual_b) {
        return +1;
    }

    return 0;
}

// Facem si un exemplu cu struct:
typedef struct {
    char name[100];
    int age;
} student_t;
// Functie de comparare a doi studenti.
int cmp_student(const void *a, const void *b)
{
    student_t actual_a = *(student_t *) a;
    student_t actual_b = *(student_t *) b;

    // Sa sortam descrescator dupa varsta.
    return actual_b.age - actual_a.age;    // ATENTIE: ordinea operanzilor!
}

// Aici exemplificam cum se foloseste functia polymorphic_sort
// pentru a sorta un array de int-uri.
void test_int(void)
{
    printf("Test int\n");

    int data[] = {3, -1, 4, 1, 5, 9, 2, 6, 5, -3};
    const int n = sizeof(data) / sizeof(data[0]);

    // Apelul funcției de sortare, folosind cmp_int pentru a compara două int-uri.
    polymorphic_sort(data, n, sizeof(int), cmp_int);

    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

// Aici exemplificam cum se foloseste functia polymorphic_sort
// pentru a sorta un array de double-uri.
void test_double(void)
{
    printf("Test double\n");

    double data[] = {3.14, 1.41, 2.71, 1.61, -5.12, 9.81, 2.72, -6.28, 5.25, 3.14};
    const int n = sizeof(data) / sizeof(data[0]);

    // Apelul funcției de sortare, folosind cmp_double pentru a compara două double-uri.
    polymorphic_sort(data, n, sizeof(double), cmp_double);

    for (int i = 0; i < n; i++) {
        printf("%.5lf ", data[i]);
    }
    printf("\n");
}

// Aici exemplificam cum se foloseste functia polymorphic_sort
// pentru a sorta un array de studenti.
void test_student(void)
{
    printf("Test student\n");

    student_t data[] = {
        {"Alice", 20},
        {"Bob", 22},
        {"Charlie", 21},
        {"David", 19},
        {"Eve", 23},
    };
    const int n = sizeof(data) / sizeof(data[0]);

    // Apelul funcției de sortare, folosind cmp_student pentru a compara doi studenti.
    polymorphic_sort(data, n, sizeof(student_t), cmp_student);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", data[i].name, data[i].age);
    }
    printf("\n");
}

int main(void)
{
    test_int();
    test_double();
    test_student();
    return 0;
}


// Compile:
// $ make
// Run:
// $ ./03-application_polymorphic_sort
// Test int
// -3 -1 1 2 3 4 5 5 6 9
// Test double
// -6.28000 -5.12000 1.41000 1.61000 2.71000 2.72000 3.14000 3.14000 5.25000 9.81000
// Test student
// Eve 23
// Bob 22
// Charlie 21
// Alice 20
// David 19
