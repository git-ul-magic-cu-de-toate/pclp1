// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

// Refaceți rezolvarea de la exercițiul anterior, folosind qsort din C.
// De data aceasta, implementați doar funcțiile de comparare pentru int, double și student.

#include <stdio.h>
#include <stdlib.h> // qsort

// Funcție de comparare a două int-uri, date prin 2 pointers de tip void *.
int cmp_int(const void *a, const void *b)
{
    int actual_a = *(int *) a;
    int actual_b = *(int *) b;

    return actual_a - actual_b;
}

// Funcție de comparare a două double-uri, date prin 2 pointers de tip void *.
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
    qsort(data, n, sizeof(int), cmp_int);

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
    qsort(data, n, sizeof(double), cmp_double);

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
    qsort(data, n, sizeof(student_t), cmp_student);

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
// $ ./04-qsort_example
// Test int
// -3 -1 1 2 3 4 5 5 6 9
// Test double
// -6.28000 -5.12000 1.41000 1.61000 2.71000 2.72000 3.14000 3.14000 5.25000 9.81000
// Test student
// Eve 23
// Bob 22
// Charlie 21
// Alice 20
// David 1


// Concluzie:
// - Dacă scopul problemei este să scriem noi logica de sortare, facem precum în exercițiile anterioare.
// - Dacă scopul problemei este să folosim o funcție de sortare deja implementată, folosim qsort.
