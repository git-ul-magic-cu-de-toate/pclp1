#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#









#


















int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("Prea putine fisiere\n");
        return 1;
    }
    FILE **in;
    FILE *out = fopen(argv[argc - 1], "wb");
    in = (FILE **)malloc((argc - 2) * sizeof(FILE *));
    for (int i = 0; i < argc - 2; i++)
        in[i] = fopen(argv[i + 1], "rb");
    int *curr, *marked;
    curr = (int *)malloc((argc - 2) * sizeof(int));
    marked = (int *)calloc(argc - 2, sizeof(int));
    for (int i = 0; i < argc - 2; i++)
        fread(&curr[i], sizeof(int), 1, in[i]);
    while (1) {
        int minn = 2000000;
        int pos_min = -1;
        for (int i = 0; i < argc - 2; i++)
            if (curr[i] < minn && !marked[i]) {
                minn = curr[i];
                pos_min = i;
            }
        // printf("%d\n", pos_min);
        if (fread(&curr[pos_min], sizeof(int), 1, in[pos_min]) <= 0)
            marked[pos_min] = 1;
        fwrite(&minn, sizeof(int), 1, out);
        int ok = 0;
        for (int i = 0; i < argc - 2; i++)
            if (!marked[i])
                ok = 1;
        if (!ok)
            break;
    }
    for (int i = 0; i < argc - 2; i++)
        fclose(in[i]);
    fclose(out);
    free(in);
    free(curr);
    free(marked);
    return 0;
}