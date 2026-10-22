// Copyright 2024 Darius Neatu (darius.neatu@upb.ro)
// Se cere doar functia parse().
// Acesta este un program complet folosit pentru a testa functia parse().
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_MAX 1000

// Numara cate linii are un fisier text deschis.
int count_lines(FILE *file) {
    // Se salveaza pozitia curenta in fisier.
    long pos = ftell(file);

    // Se pozitioneaza la inceputul fisierului.
    fseek(file, 0, SEEK_SET);

    // Se numara cate linii are fisierul.
    int n = 0;
    char line[LINE_MAX + 1];
    while (fgets(line, LINE_MAX, file) != NULL) {
        n++;
    }

    // Se revine la pozitia initiala in fisier.
    fseek(file, pos, SEEK_SET);

    return n;
}

// Sa afiseze primele/ultimele k linii dintr-un fisier dat.
void parse(const char *filename, int k) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    int n = count_lines(file);
    if (n == 0) {
        fprintf(stderr, "File %s is empty\n", filename);
        fclose(file);
        return;
    }

    if (k > 0) { // primele k linii din fisier
        char line[LINE_MAX + 1];
        while (k > 0 && fgets(line, LINE_MAX, file) != NULL) {
            printf("%s", line);
            k--;
        }
    } else { // ultimele k linii din fisier
        k = -k;

        // Citim si ignoram primele n - k linii.
        int cnt = n - k;
        char line[LINE_MAX + 1];
        while (cnt > 0 && fgets(line, LINE_MAX, file) != NULL) {
            cnt--;
        }

        // Afisam ultimele k linii.
        while (k > 0 && fgets(line, LINE_MAX, file) != NULL) {
            printf("%s", line);
            k++;
        }
    }

    fclose(file);
}

// Functia main() este folosita pentru a testa functia parse().
// NU face parte din rezolvarea ceruta.
int main(void)
{
    char filename[] = "03-bonus-parse.in"; // Continutul fisierului: "Line 1\nLine 2\n...\nLine 10\n".

    printf("Afisam primele 5 linii din fisier. (k = 5)\n");
    parse(filename, 5);
    printf("Afisam ultimele 5 linii din fisier. (k = -5)\n");
    parse(filename, -5);
    printf("Afisam primele 10 linii din fisier. (k = 10)\n");
    parse(filename, 10);
    printf("Afisam ultimele 10 linii din fisier. (k = -10)\n");
    parse(filename, -10);
    printf("Afisam primele 15 linii din fisier. (k = 15)\n");
    parse(filename, 15);
    printf("Afisam ultimele 15 linii din fisier. (k = -15)\n");
    parse(filename, -15);

    return 0;
}


// $ make && ./03-parse
// gcc -Wall -Wextra -g -o 04-parse 04-parse.c -lm
// Afisam primele 5 linii din fisier. (k = 5)
// Line 1
// Line 2
// Line 3
// Line 4
// Line 5
// Afisam ultimele 5 linii din fisier. (k = -5)
// Line 6
// Line 7
// Line 8
// Line 9
// Line 10
// Afisam primele 10 linii din fisier. (k = 10)
// Line 1
// Line 2
// Line 3
// Line 4
// Line 5
// Line 6
// Line 7
// Line 8
// Line 9
// Line 10
// Afisam ultimele 10 linii din fisier. (k = -10)
// Line 1
// Line 2
// Line 3
// Line 4
// Line 5
// Line 6
// Line 7
// Line 8
// Line 9
// Line 10
// Afisam primele 15 linii din fisier. (k = 15)
// Line 1
// Line 2
// Line 3
// Line 4
// Line 5
// Line 6
// Line 7
// Line 8
// Line 9
// Line 10
// Afisam ultimele 15 linii din fisier. (k = -15)
// Line 1
// Line 2
// Line 3
// Line 4
// Line 5
// Line 6
// Line 7
// Line 8
// Line 9
// Line 10