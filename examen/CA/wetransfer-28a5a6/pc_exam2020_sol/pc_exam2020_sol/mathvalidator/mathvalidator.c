// Copyright 2020 Echipa de Programarea Calculatoarelor, Seria CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 129

// functia returneaza 1 daca expresia e valida, 0 altfel
int is_valid(char *expr);

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file.txt", argv[0]);
        return -1;
    }

    // deschid fisierul de intrare
    char* in_filename = argv[1];
    FILE* in = fopen(in_filename, "rt");
    if (!in) {
        fprintf(stderr, "Cannot open %s\n", in_filename);
        return -1;
    }

    // generez numele fisierul de output
    char out_filename[NMAX];
    strcpy(out_filename, "corect_");
    strcat(out_filename, in_filename);

    // creez fisierul
    FILE *out = fopen(out_filename, "wt");
    if (!out) {
        fprintf(stderr, "Cannot open %s\n", out_filename);
        return -1;
    }

    int valid_cnt = 0, invalid_cnt = 0;

    char line[NMAX];
    while (fgets(line, NMAX, in)) {
        // sterg newline
        line[ strlen(line) - 1] = '\0';

        // daca linia este un comentariu
        if (line[0] == '#') {
            // se va ignora
            continue;
        }

        if (is_valid(line)) {
            ++valid_cnt;
            fprintf(out, "%s\n", line);
        } else {
            ++invalid_cnt;
        }
    }

    printf("%d expresii valide\n", valid_cnt);
    printf("%d expresii invalide\n", invalid_cnt);

    fclose(in);
    fclose(out);
    return 0;
}

int is_valid(char *line) {
    char line_copy[NMAX];
    strcpy(line_copy, line);

    char *expr = line_copy;
    while (1) {
        // gasesc prima paranteza inchisa
        char* close = strchr(expr, ')');
        if (!close) {
            // nu mai sunt ')'
            break;
        }

        // gasesc paranteza deschisa (perechea) la stanga
        char* open = close - 1;
        while (open >= expr && *open != '(') {
            --open;
        }
        if (open < expr) {
            // nu exista perechea
            return 0;
        }

        // expr ... open ... close, close +1 ... expr+strlen(expr)-1
        // trebuie sa sterg ce este intre open si close
        // sau sa mut totul la stanga
        memmove(open, close + 1, strlen(close + 1) + 1);
    }

    while (*expr) {
        if (*expr == '(') {
            // expresia contine paranteze care nu sunt inchise
            return 0;
        }

        ++expr;
    }

    // a trecut toate verificarile
    return 1;
}
