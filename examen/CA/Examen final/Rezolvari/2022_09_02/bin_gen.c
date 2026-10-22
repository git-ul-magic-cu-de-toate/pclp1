#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // FILE *f = fopen("bin1", "wb");
    // for (int i = 1; i <= 10; i++)
    //     fwrite(&i, sizeof(int), 1, f);
    // f = fopen("bin2", "wb");
    // for (int i = 5; i <= 9; i++)
    //     fwrite(&i, sizeof(int), 1, f);
    // f = fopen("bin3", "wb");
    // for (int i = 15; i <= 18; i++)
    //     fwrite(&i, sizeof(int), 1, f);
    // f = fopen("bin4", "wb");
    // for (int i = 1; i <= 2; i++)
    //     fwrite(&i, sizeof(int), 1, f);
    FILE *f = fopen("output.bin", "rb");
    int x;
    while (1) {
        if (fread(&x, sizeof(int), 1, f) <= 0) {
            break;
        }
        printf("%d ", x);
    }
}