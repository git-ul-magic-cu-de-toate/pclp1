// Copyright 2017 PC Team
#include <stdio.h>   // functii de citire
#include <string.h>  // functii de prelucrare siruri de caractere
#include <stdlib.h>  // functii pentru alocare dinamica

#define NMAX 1000    // presupun ca o linie are maximum 1000 de caractere
#define INCLUDE_DIR "#include"
#define INCLUDE_LEN 8

void fappend(FILE *out, FILE *in);
char *get_header_name(char *line);

int main(int argc, char *argv[]) {
    // ma asigur ca voi primi mereu un argument pentru comanda
    if (argc != 2) {
        fprintf(stderr, "Usage: expandinc <input_file> ");
        return -2;
    }

    // numele fisierului de intrate
    char *in_file = argv[1];

    // deschid fisierul
    FILE *in = fopen(in_file, "rt");
    if (in == NULL) {
        fprintf(stderr, "cannot open %s", in_file);
        return -1;
    }
    fprintf(stdout, "expanding %s ...\n", in_file);

    // aloc un nou sir de caractere, am grija sa am loc pentru noua extensie
    int len_name = strlen(in_file) + strlen(".inc");
    char *out_file = (char *) malloc(len_name * sizeof(char));
    strcpy(out_file, in_file);

    // trebuie sa inlocuiesc extensia: gasesc unde e punctul
    char *dot_position = strrchr(out_file, '.');
    *dot_position = '\0';      // termin stringul aici
    strcat(out_file, ".inc");  // adaug noua extensie

    // deschid fisierul de iesire
    FILE *out = fopen(out_file, "wt");
    if (out == NULL) {
        fprintf(stderr, "cannot open %s\n", out_file);
        free(out_file);
        return -1;
    }
    fprintf(stdout, "creating  %s...\n", out_file);

    char line[NMAX + 1];
    while (fgets(line, NMAX, in)) {
        // exrage numele fisierului
        char *filename = get_header_name(line);

        if (filename == NULL) {  // nu era linie cu include
            fprintf(out, "%s", line);
            continue;
        }

        // incerc sa deschid fisierul
        FILE *h = fopen(filename, "rt");
        if (h == NULL) {
            fprintf(stderr, "cannot open %s", filename);
            free(filename);
            continue;
        }

        fappend(out, h);
        fclose(h);
        free(filename);
    }

    fclose(in);
    fclose(out);
    free(out_file);

    return 0;
}

// functia returneaza:
//      - NULL daca lina nu este de tipul includere directiva
//      - numele fisierului inclus in caz contrar
/*
    O linie de acest tip este de forma:
    WS #include WS "nume_fisier.h" CS

    unde WS = oricate whitespaces
*/

int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

char *get_header_name(char *line) {
    // sar toate caracterele albe de dinainte de un posibil #
    while (is_whitespace(*line)) ++line;

    // verific daca s-a terminat sirul
    if (*line == '\0') {
        // linie plina de whitespace
        return NULL;
    }

    // verific daca in continuare am stringu; "#include"
    if (strncmp(line, INCLUDE_DIR, INCLUDE_LEN) != 0) {
        // prima instructiune nu este #include
        //  sau care incepe cu comentarii
        return NULL;
    }

    // din acest moment sunt sigur ca am o linie de tipul
    // #include "nume.h" (se presupune ca fisierul de input e corect)
    line += INCLUDE_LEN;

    char *start = strchr(line, '"') + 1;  // aici incepe numele
    char *end   = strrchr(line, '"'); // aici este " de dupa nume
    *end = '\0';  // acum intre start si end se gaseste nume.h (inclusiv '\0')

    // returnez o copie
    return strdup(start);
}

void fappend(FILE *out, FILE *in) {
    char line[NMAX + 1];
    while (fgets(line, NMAX, in)) {
        fprintf(out, "%s", line);
    }
}
