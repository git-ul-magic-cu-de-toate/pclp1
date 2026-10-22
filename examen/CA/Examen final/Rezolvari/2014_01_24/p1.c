#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#






typedef struct
{
    int lin, col;
    double val;
} termen;

typedef struct 
{
    int nl, nc, nn;
    termen *term;
} matrice_rara;

matrice_rara get_next_mat(FILE *in)
{
    matrice_rara a;
    if (fread(&a.nl, sizeof(int), 1, in) <= 0) {
        a.nn = -1;
        return a;
    }
    
    fread(&a.nc, sizeof(int), 1, in);
    fread(&a.nn, sizeof(int), 1, in);
    a.term = (termen *)malloc(a.nn * sizeof(termen));
    for (int i = 0; i < a.nn; i++) {
        fread(&a.term[i].lin, sizeof(int), 1, in);
        fread(&a.term[i].col, sizeof(int), 1, in);
        fread(&a.term[i].val, sizeof(double), 1, in);
    }
    return a;
}

matrice_rara get_k_mat(FILE *in, int k)
{
    fseek(in, 0, SEEK_SET);
    matrice_rara a;
    for (int i = 1; i <= k; i++) {
        if (i >= 2)
            free(a.term);
        a = get_next_mat(in);
        if (a.nn == -1)
            return a;
    }
    return a;
}

void print_mat(matrice_rara a)
{
    printf("%d %d %d\n", a.nl, a.nc, a.nn);
    for (int i = 0; i < a.nn; i++)
        printf("(%d, %d, %lf), ", a.term[i].lin, a.term[i].col, a.term[i].val);
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("N-avem destui parametri\n");
        return 1;
    }
    FILE *in = fopen(argv[1], "rb");
    for (int i = 2; i < argc; i++) {
        matrice_rara a;
        a = get_k_mat(in, atoi(argv[i]));
        if (a.nn >= 1) {
            print_mat(a);
            free(a.term);
        } else {
            printf("N-avem destule matrici rare\n");
        }
    }
}
    fclose(in);
    return 0;
}
