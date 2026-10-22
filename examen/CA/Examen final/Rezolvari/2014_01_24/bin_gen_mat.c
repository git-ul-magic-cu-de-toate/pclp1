#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *out = fopen("input.bin", "wb");
    int nl = 3, nc = 3, nn = 2;
    int col[4] = {1, 1}, lin[4] = {1, 2};
    double val[4] = {2.0, 5.5};
    fwrite(&nl, sizeof(int), 1, out);
    fwrite(&nc, sizeof(int), 1, out);
    fwrite(&nn, sizeof(int), 1, out);
    for (int i = 0 ; i < nn; i++) {
        fwrite(&lin[i], sizeof(int), 1, out);
        fwrite(&col[i], sizeof(int), 1, out);
        fwrite(&val[i], sizeof(double), 1, out);
    }

    nl = 2;
    val[0] = 5.0;
    fwrite(&nl, sizeof(int), 1, out);
    fwrite(&nc, sizeof(int), 1, out);
    fwrite(&nn, sizeof(int), 1, out);
    for (int i = 0 ; i < nn; i++) {
        fwrite(&lin[i], sizeof(int), 1, out);
        fwrite(&col[i], sizeof(int), 1, out);
        fwrite(&val[i], sizeof(double), 1, out);
    }

    nl = 4;
    val[1] = 69.69;
    fwrite(&nl, sizeof(int), 1, out);
    fwrite(&nc, sizeof(int), 1, out);
    fwrite(&nn, sizeof(int), 1, out);
    for (int i = 0 ; i < nn; i++) {
        fwrite(&lin[i], sizeof(int), 1, out);
        fwrite(&col[i], sizeof(int), 1, out);
        fwrite(&val[i], sizeof(double), 1, out);
    }
    return 0;
}