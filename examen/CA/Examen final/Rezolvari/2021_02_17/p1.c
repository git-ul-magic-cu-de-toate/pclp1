#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_MAX 33



#
typedef struct {
    char nume[LEN_MAX];
    int cant;
} produs_t;




















int main()
{
    int n, k;
    char **filename;
    scanf("%d", &n);
    scanf("%d", &k);
    printf("%d\n", n);
    filename = (char **)malloc(n * sizeof(char *));
    if (!filename) {
        printf("COuld not alloc\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        filename[i] = (char *)malloc(33 * sizeof(char));
        if (!filename[i]) {
            for (int j = 0; j < i; j++)
                free(filename[j]);
            free(filename);
            printf("Eroare...\n");
            return 2;
        }
        scanf("%s", filename[i]);
    }
    FILE **in;
    in = (FILE **)malloc(n * sizeof(FILE *));
    if (!in) {
        printf("Eroare\n");
        for (int i = 0; i < n; i++)
            free(filename[i]);
        free(filename);
        return 3;
    }
    for (int i = 0; i < n; i++) {
        in[i] = fopen(filename[i], "rt");
        if (!in[i]) {
            printf("Eroare\n");
            for (int j = 0; j < n; j++)
                free(filename[i]);
            free(filename);
            for (int j = 0; j < i; j++)
                fclose(in[i]);
            return 5;
        }
    }
    produs_t *produse;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char p[33];
        int cant;
        while (fscanf(in[i], "%s%d", p, &cant) != EOF) {
            int pos = -1;
            for (int j = 0; j < cnt; j++)
                if (strcmp(produse[j].nume, p) == 0)
                    pos = j;
            if (pos >= 0) {
                produse[pos].cant += cant;
            } else {
                if (cnt == 0) {
                    produse = malloc(1 * sizeof(produs_t));
                    strcpy(produse[0].nume, p);
                    produse[0].cant += cant;
                    cnt++;
                } else {
                    produs_t *tmp = realloc(produse, (cnt + 1) * sizeof(produs_t));
                    if (!tmp) {
                        printf("eroare\n");
                        return 4;
                        free(produse);
                    }
                    produse = tmp;
                    strcpy(produse[cnt].nume, p);
                    produse[cnt].cant += cant;
                    cnt++;
                }
            }
        }
    }
    for (int i = 0; i < cnt; i++)
        if (produse[i].cant <= k)
            printf("%s\n", produse[i].nume);
    FILE *out = fopen("inventar.txt", "wt");
    for (int i = 0; i < cnt; i++)
        fprintf(out, "%s %d\n", produse[i].nume, produse[i].cant);
    free(produse);
    for (int i = 0; i < n; i++)
        fclose(in[i]);
    for (int i = 0; i < n; i++)
        free(filename[i]);
    free(filename);
    return 0;
}