#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct 
{
    char nume[21];
    double cant;
} medicament_t;

typedef struct
{
    char pacient[21];
    int n;
    medicament_t *med;
} reteta_t;

typedef struct
{
    char nume[21];
    double val;
} romanesc_t;

typedef struct
{
    char pacient[21];
    int n;
    romanesc_t *med;
    double plata;
}bon_t;

int citire_reteta(reteta_t *reteta, FILE *in);

int gaseste_echivalente(reteta_t reteta, int i, bon_t *bon, FILE *echiv);

void output_bon(bon_t bon, FILE *out);













int main(int argc, char **argv)
{
    FILE *in, *echiv, *out;
    in = fopen(argv[1], "rb");
    echiv = fopen(argv[2], "rb");
    if (!echiv) {
        fclose(in);
        printf("Error opening file\n");
        return 2;
    }
    out = fopen(argv[3], "wb");
    if (!out) {
        fclose(out);
        printf("Error opening file\n");
        return 3;
    }
    reteta_t reteta;
    bon_t bon;
    while (1) {
        int gasit;
        gasit = citire_reteta(&reteta, in);
        if (gasit == 0)
            break;
        bon.med = (romanesc_t *)malloc(reteta.n * sizeof(romanesc_t));
        strcpy(bon.pacient, reteta.pacient);
        int toate_bune = 1;
        bon.n = 0;
        for (int i = 0; i < reteta.n; i++) {
            gasit = gaseste_echivalente(reteta, i, &bon, echiv);
            if (gasit == 0)
                toate_bune = 0;
        }
        if (toate_bune == 1)
            output_bon(bon, out);
        free(bon.med);
        free(reteta.med);
    }
    fclose(in);
    fclose(echiv);
    fclose(out);
    return 0;
}



int citire_reteta(reteta_t *reteta, FILE *in)
{
    int read = fread(reteta->pacient, sizeof(char), 21, in);
    if (read <= 20) {
        return 0;
    }
    fread(&reteta->n, sizeof(int), 1, in);
    reteta->med = (medicament_t *)malloc(reteta->n * sizeof(medicament_t));
    for (int i = 0; i < reteta->n; i++) {
        fread(reteta->med[i].nume, sizeof(char), 21, in);
        fread(&reteta->med[i].cant, sizeof(double), 1, in);
    }
    return 1;
}

int gaseste_echivalente(reteta_t reteta, int i, bon_t *bon, FILE *echiv)
{
    int gasit = 0;
    fseek(echiv, 0, SEEK_SET);
    while (1) {
        char dci[21];
        int read = fread(dci, sizeof(char), 21, echiv);
        printf("%s\n", dci);
        if (read <= 20)
            break;
        int nr;
        char denumire[21], min_denumire[21];
        double pret, min_pret = 20000.0;
        fread(&nr, sizeof(int), 1, echiv);
        for (int i = 0; i < nr; i++) {
            fread(denumire, sizeof(char), 21, echiv);
            fread(&pret, sizeof(double), 1, echiv);
            if (pret < min_pret) {
                min_pret = pret;
                strcpy(min_denumire, denumire);
            }
        }
        if (strcmp(dci, reteta.med[i].nume) == 0) {
            (bon->n)++;
            strcpy(bon->med[bon->n- 1].nume, min_denumire);
            bon->med[bon->n - 1].val = min_pret * reteta.med[i].cant;
            gasit = 1;
        }
    }
    return gasit;
}

void output_bon(bon_t bon, FILE *out)
{
    bon.plata = 0.0;
    for (int i = 0; i < bon.n; i++)
        bon.plata += bon.med[i].val;
    fwrite(bon.pacient, sizeof(char), 21, out);
    fwrite(&bon.n, sizeof(int), 1, out);
    for (int i = 0 ; i < bon.n; i++) {
        fwrite(bon.med[i].nume, sizeof(char), 21, out);
        fwrite(&bon.med[i].val, sizeof(double), 1, out);
    }
    fwrite(&bon.plata, sizeof(double), 1, out);
}


