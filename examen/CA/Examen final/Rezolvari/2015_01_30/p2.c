#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_lines(FILE *in, int n, char type);

void print_chars(FILE *in, int n, char type);

int main(int argc, char **argv)
{
    int n = 10;
    char where = '+', type = 'L';
    if (argc < 2) {
        printf("N-am destule argumente vere\n");
        return 1;
    }
    for (int i = 1; i < argc - 1; i++) {
        if (argv[i][0] == '-')
            where = '-';
        else if (argv[i][0] >= '0' && argv[i][0] <= '9')
            n = atoi(argv[i]);
        else
            type = argv[i][0];
    }
    FILE *in = fopen(argv[argc - 1], "rt");
    if (!in) {
        printf("N-am putut deschide fisierul vere\n");
        return 2;
    }
    if (type == 'L')
        print_lines(in, n, where);
    else if (type == 'C')
        print_chars(in, n, where);
    else
        print_chars(in, n * 512, where);
    fclose(in);
    return 0;
}

void print_lines(FILE *in, int n, char type)
{
    char line[500];
    if (type == '+') {
        int cnt = 1;
        while (cnt <= n && fgets(line, 500, in)) {
            printf("%s", line);
            cnt++;
        }
    } else {
        int cnt = 1;
        while (fgets(line, 500, in)) {
            cnt++;
        }
        fseek(in, 0, SEEK_SET);
        int k = 1;
        while (fgets(line, 500, in)) {
            if (k >= cnt - n + 1)
                printf("%s", line);
            k++;
        }
    }
}

void print_chars(FILE *in, int n, char type)
{
    char c;
    if (type == '+') {
        int cnt = 1;
        while (cnt <= n && fscanf(in, "%c", &c) != EOF) {
            printf("%c", c);
            cnt++;
        }
    } else {
        int cnt = 1;
        while (fscanf(in, "%c", &c) != EOF) {
            cnt++;
        }
        int k = 1;
        fseek(in, 0, SEEK_SET);
        while (fscanf(in, "%c", &c) != EOF) {
            if (k >= cnt - n + 1)
                printf("%c", c);
            k++;
        }
    }
}