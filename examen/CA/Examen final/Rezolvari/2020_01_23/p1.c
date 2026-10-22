#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#














#























int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Nu avem fisier intrare\n");
        return 1;
    }
    char *output;
    output = (char *)malloc((strlen(argv[1]) + 10) * sizeof(char));
    if (!output) {
        printf("NU am putut creaa iesirea\n");
        return 2;
    }
    FILE *in = fopen(argv[1], "rt");
    if (!in) {
        printf("NU am putut deschide fisierul de intrare\n");
        free(output);
        return 3;
    }
    strcpy(output, "corect_");
    strcat(output, argv[1]);
    FILE *out = fopen(output, "wt");
    if (!out) {
        printf("NU putem crea fisierul de iesire\n");
        free(output);
        fclose(in);
    }
    char line[130];
    int corecte = 0, gresite = 0;
    while (fgets(line, 129, in)) {
        if (line[0] == '#')
            continue;
        int paranteze = 0, ok = 1;
        for (int i = 0; i < strlen(line) - 1; i++) {
            if (line[i] == '(')
                paranteze++;
            if (line[i] == ')')
                paranteze--;
            if (paranteze < 0) {
                ok = 0;
                break;
            }
        }
        if (paranteze == 0 && ok == 1) {
            corecte++;
            fprintf(out, "%s", line);
        } else {
            gresite++;
        }
    }
    printf("%d expresii valide\n", corecte);
    printf("%d expresii invalide\n", gresite);
}