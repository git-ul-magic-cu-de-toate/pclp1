#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *out = fopen("-fname", "wb");
    int n = 4;
    char x = '9', y = '3', z = '1';
    fwrite(&n, sizeof(int), 1, out);
    fwrite(&x, sizeof(char), 1, out);
    fwrite(&x, sizeof(char), 1, out);
    fwrite(&x, sizeof(char), 1, out);
    fwrite(&x, sizeof(char), 1, out);
    fwrite(&n, sizeof(int), 1, out);
    fwrite(&y, sizeof(char), 1, out);
    fwrite(&x, sizeof(char), 1, out);
    fwrite(&x, sizeof(char), 1, out);
    fwrite(&z, sizeof(char), 1, out);
    fwrite(&n, sizeof(int), 1, out);
    fwrite(&z, sizeof(char), 1, out);
    fwrite(&z, sizeof(char), 1, out);
    fwrite(&x, sizeof(char), 1, out);
    fwrite(&x, sizeof(char), 1, out);
    fwrite(&n, sizeof(int), 1, out);
    fwrite(&y, sizeof(char), 1, out);
    fwrite(&x, sizeof(char), 1, out);
    fwrite(&y, sizeof(char), 1, out);
    fwrite(&z, sizeof(char), 1, out);
    return 0;
}