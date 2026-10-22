#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    FILE *outin, *outout, *outechiv;
    outin = fopen("input", "wb");
    //outout = fopen("output", "wb");
    outechiv = fopen("echiv", "wb");
    char nume[21] = "DUBADUBADUBADUBADUBA";
    fwrite(nume, sizeof(char), 21, outin);
    int n = 3;
    double cant = 20.5;
    fwrite(&n, sizeof(int), 1, outin);
    char medic[21] = "AMOXICILINAHIDRAT_NA";
    for (int i = 0; i < 3; i++) {
        fwrite(medic, sizeof(char), 21, outin);
        fwrite(&cant, sizeof(double), 1, outin);
    }
    char dci[21] = "AMOXICILINAHIDRAT_NA";
    fwrite(dci, sizeof(char), 21, outechiv);
    int nr = 2;
    fwrite(&nr, sizeof(int), 1, outechiv);
    char alias[21] = "PULAPULAPULAPULAPULA";
    double val = 2.0;
    for (int i = 0; i < nr; i++) {
        fwrite(alias, sizeof(char), 21, outechiv);
        fwrite(&val, sizeof(double), 1, outechiv);
    }
}