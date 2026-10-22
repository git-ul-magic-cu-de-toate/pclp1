#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#






#
typedef struct
{
    int n;
    int nn;
    int *x;
    int *poz;
} SparceArray;

int *decomp(SparceArray sa);

SparceArray comp(int n, int *v);

int *aduna_2(int n, int *x, int *y);

int read_sparce(SparceArray *a, FILE *in);

void out_sparce(SparceArray sa, FILE *out);













int main(int argc, char **argv)
{
    int n1, n2;
    if (argc < 5) {
        printf("Nu avem suficiente argumente\n");
        return 1;
    }
    n1 = atoi(argv[3]);
    n2 = atoi(argv[4]);
    FILE *in = fopen(argv[1], "rt");
    FILE *out = fopen(argv[2], "wt");
    SparceArray *sa;
    sa = (SparceArray *)malloc(1 * sizeof(SparceArray));
    int cnt = 0;
    while (read_sparce(&sa[cnt], in)) {
        cnt++;
        SparceArray *tmp = realloc(sa, (cnt + 1) * sizeof(SparceArray));
        if (!tmp) {
            printf("Error allocating\n");
            return 2;
        }
        sa = tmp;
    }
    for (int i = 0; i < cnt - 1; i++)
        for (int j = i + 1; j < cnt; j++)
            if (sa[i].n == sa[j].n && sa[i].n >= n1 && sa[i].n <= n2) {
                int *x = decomp(sa[i]);
                int *y = decomp(sa[j]);
                int *z = aduna_2(sa[i].n, x, y);
                SparceArray arr = comp(sa[i].n, z);
                out_sparce(arr, out);
                free(x);
                free(y);
                free(z);
                free(arr.poz);
                free(arr.x);
            }
    for (int i = 0; i < cnt; i++) {
        free(sa[i].poz);
        free(sa[i].x);
    }
    free(sa);
    fclose(in);
    fclose(out);
    return 0;
}

int *decomp(SparceArray sa)
{
    int *v = (int *)calloc(sa.n, sizeof(int));
    for (int i = 0; i < sa.nn; i++)
        v[sa.poz[i]] = sa.x[i];
    return v;
}

SparceArray comp(int n, int *v)
{
    SparceArray sa;
    sa.n = n;
    sa.nn = 0;
    for (int i = 0; i < n; i++)
        if (v[i] != 0)
            sa.nn++;
    sa.x = (int *)malloc(sa.nn * sizeof(int));
    sa.poz = (int *)malloc(sa.nn * sizeof(int));
    sa.nn = 0;
    for (int i = 0; i < n; i++)
        if (v[i] != 0) {
            sa.x[sa.nn] = v[i];
            sa.poz[sa.nn] = i;
            sa.nn++;
        }
    return sa;
}

int *aduna_2(int n, int *x, int *y)
{
    int *z = (int *)malloc(n * sizeof(int));
    if (!z) {
        printf("Error summing\n");
        return NULL;
    }
    for (int i = 0; i < n; i++)
        z[i] = x[i] + y[i];
    return z;
}

int read_sparce(SparceArray *a, FILE *in)
{
    SparceArray sa;
    int read = fscanf(in, "%d", &sa.n);
    if (read <= 0) {
        return 0;
    }
    fscanf(in, "%d", &sa.nn);
    sa.x = (int *)malloc(sa.nn * sizeof(int));
    sa.poz = (int *)malloc(sa.nn * sizeof(int));
    for (int i = 0; i < sa.nn; i++)
        fscanf(in, "%d", &sa.x[i]);
    for (int i = 0; i < sa.nn; i++)
        fscanf(in, "%d", &sa.poz[i]);
    *a = sa;
    return 1;
    
}

void out_sparce(SparceArray sa, FILE *out)
{
    fprintf(out, "%d\n", sa.n);
    fprintf(out, "%d\n", sa.nn);
    for (int i = 0; i < sa.nn; i++)
        fprintf(out, "%d ", sa.x[i]);
    fprintf(out, "\n");
    for (int i = 0; i < sa.nn; i++)
        fprintf(out, "%d ", sa.poz[i]);
    fprintf(out, "\n");

}
