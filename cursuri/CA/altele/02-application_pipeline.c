// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

// Să se scrie un program care porneste de la un array de int-uri și un array de
// pointeri la funcții și aplică fiecare funcție din array-ul de pointeri la
// fiecare element din array-ul de int-uri. Să se afișeze rezultatele.
// Aceasta este o aplicație a conceptului de pointer la funcție într-un pipeline
// de procesare a datelor.
// Exemplu: pentru array-ul de int-uri {1, 2, 3} și array-ul de funcții
// {f1, f2, f3}, se vor afișa rezultatele f1(1), f2(2), f3(3).
// Hint: se va folosi un for pentru a itera prin array-ul de int-uri și un alt
// for pentru a itera prin array-ul de funcții.

#include <stdio.h>
#define NMAX 100

typedef int (*stage_func)(int);

int f1(int x) { return x + 1; }
int f2(int x) { return x * 2; }
int f3(int x) { return x * x; }

int main(void)
{
    int data[] = { 1, 10, 100 };
    const int n = sizeof(data) / sizeof(data[0]);

    const stage_func stages[] = { f1, f2, f3 };
    const int num_stages = sizeof(stages) / sizeof(stages[0]);

    for (int stage = 0; stage < num_stages; stage++) {
        printf("Stage %d\n", stage);
        for (int i = 0; i < n; i++) {
            printf("Stage %d: f%d(%d) = %d\n", stage, stage + 1, data[i], stages[stage](data[i]));
            data[i] = stages[stage](data[i]);
        }
        printf("\n");
    }

    // print final data
    printf("Final data:\n");
    for (int i = 0; i < n; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }
    return 0;
}
