#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#








#
typedef struct {
    char nume[17];
    int voturi;
    int disq;
} tara_t;

tara_t *read_tari(FILE *in, int *n)
{
    tara_t *tari;
    int cnt = 0;
    char line[1000];
    while (fgets(line, 1000, in)) {
        cnt++;
        char *q = strtok(line, "\n ");
        if (cnt == 1) {
            tari = (tara_t *)malloc(1 * sizeof(tara_t));
            if (!tari) {
                printf("Eroare mare\n");
                *n = -1;
                return tari;
            }
        } else {
            tara_t *tmp = realloc(tari, cnt * sizeof(tara_t));
            if (!tmp) {
                printf("Eroare mare de tot\n");
                *n = -1;
                return tari;
            }
            tari = tmp;
        }
        strcpy(tari[cnt - 1].nume, q);
        int ok = 1;
        q = strtok(NULL, "\n ");
        while (q) {
            if (strcmp(q, tari[cnt - 1].nume) == 0)
                ok = 0;
             q = strtok(NULL, "\n ");
        }
        if (ok == 1) {
            tari[cnt - 1].disq = 0;
            tari[cnt - 1].voturi = 0;
        } else {
            tari[cnt - 1].disq = 1;
            tari[cnt - 1].voturi = -1;
        }
    }
    *n = cnt;
    return tari;
}

void count_votes(FILE *in, tara_t *tari, int n)
{
    fseek(in, 0 , SEEK_SET);
    char line[1000];
    int cnt = 0;
    while (fgets(line, 1000, in)) {
        cnt++;
        if (tari[cnt - 1].disq == 0) {
            char *p = strtok(line, "\n ");
            int k = 0;
            p = strtok(NULL, "\n ");
            while (p) {
                k++;
                for (int i = 0; i < n; i++)
                    if (strcmp(p, tari[i].nume) == 0 && tari[i].disq == 0) {
                        tari[i].voturi += (12 - k + 1);
                    }
                p = strtok(NULL, "\n ");
            }
        }
    }
}

void print_disq(tara_t *tari, int n)
{
    for (int i = 0; i < n; i++)
        if (tari[i].disq == 1)
            printf("Juriu descalificat: %s\n", tari[i].nume);
    printf("\n");
}


void sort_tari(tara_t *tari, int n)
{
    int t = 0;
    while (t == 0) {
        t = 1;
        for (int i = 0; i < n - 1; i++)
            if (tari[i].voturi < tari[i + 1].voturi) {
                tara_t aux = tari[i];
                tari[i] = tari[i + 1];
                tari[i + 1] = aux;
                t = 0;
            }
    }
}

void print_top10(tara_t *tari, int n)
{
    for (int i = 0; i < 10; i++) 
        if (tari[i].disq == 0)
            printf("Tara = %s, voturi = %d\n", tari[i].nume, tari[i].voturi);
    printf("\n");
    for (int i = 0; i < n; i++)
        if (tari[i].disq == 0 && tari[i].voturi == 0)
            printf("Tara %s nu are voturi\n", tari[i].nume);
}












int main()
{
    int numar_tari;
    char input[50];
    scanf("%d", &numar_tari);
    scanf("%s", input);
    FILE *in = fopen(input, "rt");
    tara_t *tari;
    int n = 0;
    tari = read_tari(in, &n);
    if (n == -1) {
        printf("avem probleme mari de tot\n");
        return 1;
    }
    count_votes(in, tari, n);
    print_disq(tari, n);
    sort_tari(tari, n);
    print_top10(tari, n);
    free(tari);
    fclose(in);
    return 0;
}