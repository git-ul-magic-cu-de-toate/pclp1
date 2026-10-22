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

int main()
{
    FILE *in = fopen("bin_in", "wb");
    polinom_rar poly;
    poly.ntn = 3;
    poly.grd = 2012;
    poly.t = malloc(poly.ntn * sizeof(termen));
    poly.t[0].c = 1.0;
    poly.t[0].exp = 2020;
    poly.t[1].c = -2.0;
    poly.t[1].exp = 2;
    poly.t[2].c = 1.0;
    poly.t[2].exp = 0;
    fwrite(&poly.ntn, sizeof(int), 1, in);
    fwrite(&poly.grd, sizeof(int), 1, in);
    for (int i = 0; i < poly.ntn; i++) {
        fwrite(&poly.t[i].c, sizeof(double), 1, in);
        fwrite(&poly.t[i].exp, sizeof(int), 1, in);
    }

    poly.ntn = 3;
    poly.grd = 2020;
    poly.t = malloc(poly.ntn * sizeof(termen));
    poly.t[0].c = 2.0;
    poly.t[0].exp = 2020;
    poly.t[1].c = -10.0;
    poly.t[1].exp = 4;
    poly.t[2].c = 1.0;
    poly.t[2].exp = 0;
    fwrite(&poly.ntn, sizeof(int), 1, in);
    fwrite(&poly.grd, sizeof(int), 1, in);
    for (int i = 0; i < poly.ntn; i++) {
        fwrite(&poly.t[i].c, sizeof(double), 1, in);
        fwrite(&poly.t[i].exp, sizeof(int), 1, in);
    }
}