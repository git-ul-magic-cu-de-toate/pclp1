#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    double c;
    int exp;
} termen;

typedef struct {
    int ntn;
    int grd;
    termen *t;
} polinom_rar;

polinom_rar get_k_th_poly(FILE *in, int k);

polinom_rar get_next_poly(FILE *in);

void elib_poly(polinom_rar *poly);

void print_poly(polinom_rar poly);

int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("Avem prea putine date vere\n");
        return 1;
    }
    FILE *in = fopen(argv[1], "rb");
    if (!in) {
        printf("N avem treaba\n");
        return 1;
    }
    for (int i = 2; i < argc; i++) {
        polinom_rar poly;
        poly = get_k_th_poly(in, atoi(argv[i]));
        if (poly.ntn == -1)
            printf("NU avem suficiente polinoame\n");
        else {
            print_poly(poly);
            free(poly.t);
        }
    }
    fclose(in);
    return 0;
}

polinom_rar get_k_th_poly(FILE *in, int k)
{
    polinom_rar poly;
    fseek(in, 0, SEEK_SET);
    int i = 1;
    while (i <= k) {
        if (i >= 2)
            elib_poly(&poly);
        poly = get_next_poly(in);
        if (poly.ntn == -1)
            return poly;
        i++;
    }
    return poly;
}

polinom_rar get_next_poly(FILE *in)
{
    polinom_rar poly;
    if (fread(&poly.ntn, sizeof(int), 1, in) <= 0) {
        poly.ntn = -1;
        return poly;
    }
    fread(&poly.grd, sizeof(int), 1, in);
    poly.t = (termen *)malloc(poly.ntn * sizeof(termen));
    for (int i = 0; i < poly.ntn; i++) {
        fread(&poly.t[i].c, sizeof(double), 1, in);
        fread(&poly.t[i].exp, sizeof(int), 1, in);
    }
    return poly;
}

void elib_poly(polinom_rar *poly)
{
    free(poly->t);
}

void print_poly(polinom_rar poly)
{
    printf("%d %d\n", poly.ntn, poly.grd);
    for (int i = 0; i < poly.ntn; i++)
        printf("{%lf, %d}\n", poly.t[i].c, poly.t[i].exp);
}