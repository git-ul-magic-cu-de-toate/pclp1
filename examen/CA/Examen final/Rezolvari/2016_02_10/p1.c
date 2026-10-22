#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#








#
typedef struct {
    int n;
    char *digits;
} LongInt;

LongInt read_next_LI(FILE *in);

LongInt read_k_LI(FILE *in, int k);

void addLI(LongInt *sum, LongInt x);

void printLI(LongInt x);

void procLI(LongInt *res, LongInt x, int k, char op);























int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Not enough arguments\n");
        return 1;
    }
    FILE *in = fopen(argv[argc - 1], "rb");
    if (!in) {
        printf("Cant open input file\n");
        return 2;
    }
    LongInt sum;
    sum.n = 1;
    sum.digits = malloc(1 * sizeof(char));
    if (!sum.digits) {
        printf("eroare\n");
        fclose(in);
    }
    sum.digits[0] = '0';
    LongInt x;
    if (argc == 2) {
        while (1) {
            x = read_next_LI(in);
            if (x.n > 0) {
                addLI(&sum, x);
            } else {
                break;
            }
            free(x.digits);
        }
    } else {
        for (int i = 1; i < argc - 1; i++) {
            x = read_k_LI(in, atoi(argv[i]));
            if (x.n <= 0)
                break;
            addLI(&sum, x);
            free(x.digits);
        }
    }
    printLI(sum);
    printf("\n");
    LongInt prod;
    prod.n = 0;
    procLI(&prod, sum, 2, '*');
    printLI(prod);
    printf("\n");
    procLI(&prod, sum, 2, '/');
    printLI(prod);
    printf("\n");
    free(sum.digits);
    fclose(in);
    return 0;
}

LongInt read_next_LI(FILE *in)
{
    LongInt x;
    if (fread(&x.n, sizeof(int), 1, in) <= 0) {
        x.n = -1;
        return x;
    }
    x.digits = (char *)malloc(x.n * sizeof(char));
    if (!x.digits) {
        printf("COuld not alloc\n");
        x.n = -1;
        return x;
    }
    for (int i = 0; i < x.n; i++)
        fread(&x.digits[i], sizeof(char), 1, in);
    return x;
}

LongInt read_k_LI(FILE *in, int k)
{
    fseek(in, 0, SEEK_SET);
    LongInt x;
    for (int i = 1; i <= k; i++) {
        if (i >= 2)
            free(x.digits);
        x = read_next_LI(in);
        if (x.n == -1)
            return x;
    }
    return x;
}

void addLI(LongInt *sum, LongInt x)
{
    LongInt res;
    int min;
    if (x.n > sum->n)
        res.n = x.n + 1;
    else 
        res.n = sum->n + 1;
    if (x.n < sum->n)
        min = x.n;
    else
        min = sum->n;
    res.digits = malloc(res.n * sizeof(char));
    int tr = 0;
    for (int i = 0; i < min; i++) {
        tr = tr + sum->digits[i] + x.digits[i] - '0' - '0';
        res.digits[i] = (tr % 10) + '0';
        tr /= 10;
    }
    for (int i = min; i < sum->n; i++) {
        tr = tr + sum->digits[i] -'0';
        res.digits[i] = (tr % 10) + '0';
        tr /= 10;
    }
    for (int i = min; i < x.n; i++) {
        tr = tr + x.digits[i] - '0';
        res.digits[i] = (tr % 10) + '0';
        tr /= 10; 
    }
    if (tr)
        res.digits[res.n - 1] = tr + '0';
    else {
        res.n--;
        char *tmp = realloc(res.digits, res.n * sizeof(char));
        if (!tmp) {
            printf("erori mari\n");
            free(res.digits);
        }
        res.digits = tmp;
    }
    free(sum->digits);
    *sum = res; 
}

void printLI(LongInt x)
{
    for (int i = x.n - 1; i >= 0; i--)
        printf("%d", x.digits[i] - '0');
}

void procLI(LongInt *res, LongInt x, int k, char op)
{
    if (res->n > 0)
        free(res->digits);
    if (op == '*') {
        res->n = x.n + k;
        res->digits = (char *)malloc(res->n * sizeof(char));
        for (int i = 0; i < k; i++)
            res->digits[i] = '0';
        for (int i = k; i < res->n; i++)
            res->digits[i] = x.digits[i - k]; 
    } else {
        res->n = x.n - k;
        res->digits = (char *)malloc(res->n * sizeof(char));
        for (int i = k; i < x.n; i++)
            res->digits[i - k] = x.digits[i];
    }
}
