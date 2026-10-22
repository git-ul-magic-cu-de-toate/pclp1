// Copyright 2020 Darius Neatu <neatudarius@gmail.com>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define LINE_LEN 2049

void print_chars(FILE* in, int n);
void print_blocks(FILE* in, int n);
void print_lines(FILE* in, int n);

int main(int argc, char **argv) {
    // verificare ca cel putin numele fisieruli a fost dat
    if (argc < 2) {
        fprintf(stderr, "Usage: ./logview [+-] [n] [LCB] file\n");
        return -1;
    }

    // parsare argumente
    int sign = +1; // codificare : -1 == -, +1 == + (default +1) 
    int n = 10; // default 10
    char mode = 'L'; // default 'L'
    for (int i = 1; i <= argc - 2; ++i) {
        if (strcmp(argv[i], "-") == 0 || strcmp(argv[i], "+") == 0) {
            sign = (argv[i][0] == '+') ? (+1) : (-1);
		} else if (strcmp(argv[i], "L") == 0 || strcmp(argv[i], "B") == 0 || strcmp(argv[i], "C") == 0) {
            mode = argv[i][0];
		} else {
            n = atoi(argv[i]);
        }
    }
    n *= sign;
    char *filename = argv[argc - 1]; // ultimul argument mereu este fisierul

    FILE *in = fopen(filename, "rt");
	if (in == NULL) {
		fprintf(stderr, "%s doesn't exist\n", filename);
		return -2;
	}

    if (mode == 'L') {
        print_lines(in, n);
    } else if (mode == 'B') {
        print_blocks(in, n);
    } else if (mode == 'C') {
        print_chars(in, n);
    }

    fclose(in);
    return 0;
}

// printeaza n caractere
// n < 0, ultimele n
// n > 0, primele n
void print_chars(FILE* in, int n) {
    if (n >= 0) {
        // pozitionare la inceputul fisierului
        fseek(in, 0, SEEK_SET); // cursor = SEEK_SET + offset
    } else {
        // pozitionare cu n caractere inainte de finalul fisierului
        fseek(in, n, SEEK_END); // cursor = SEEK_END + offset

        n = -n; // n = |n|
    }

    for (int i = 0; i < n; ++i) {
		char c;
		if (fscanf(in, "%c", &c) != 1) {
            // s-a terminat fisierul, ma opresc
            return;
        }

        // afisez pe ecran caracterul citit
		printf( "%c", c);
	}
}

// printea n blocuri de cate BLOCK_SIZE caractere
// n < 0, ultimele n
// n > 0, primele n
void print_blocks(FILE* in, int n) {
    // se poate reduce problema la a printa caractere cu caracter
    n *= BLOCK_SIZE; 
	print_chars(in, n);
}

int count_lines(FILE *in) {
    // repozitionare la inceputul fisierului
    fseek(in, 0, SEEK_SET);

    int cnt = 0;
    char line[LINE_LEN];
    while (fgets(line, LINE_LEN, in)) {
        ++cnt;
    }

    return cnt;
}

// printeaza n linii din fisier
// n < 0, ultimele n
// n > 0, primele n
void print_lines(FILE* in, int n) {
    int lines = count_lines(in);

    // vom citi linie cu linie
    char line[LINE_LEN];

    // repozitionare la inceputul fisierului
    fseek(in, 0, SEEK_SET);

    // daca trebuie afisate ultimele n, trebuie sarite primele lines - n linii
    if (n < 0) {
        n = -n;
        for (int i = 0; i < lines - n; ++i) {
            // citesc linia, insa nu fac ceva util cu ea 
            // aceasta operatie este necesara pentru a repozitiona cursorul la inceputul
            // liniei urmatoare
            fgets(line, LINE_LEN, in);
        }
    }

    for (int i = 0; i < n; ++i) {
        // citesc o linie
        if (fgets(line, LINE_LEN, in) == NULL) {
            // s-a terminat fisierul, ma opresc
            return;
        }

        // o afisez
        printf("%s", line);
    }
}
