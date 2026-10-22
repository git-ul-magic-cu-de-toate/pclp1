#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *out = fopen("space.bin", "wb");
    char c = 169;
    char d = 100;
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&d, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&d, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&d, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&d, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&d, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);
    fwrite(&c, sizeof(char), 1, out);

}