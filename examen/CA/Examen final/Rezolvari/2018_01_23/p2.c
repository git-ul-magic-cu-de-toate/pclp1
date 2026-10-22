#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_BILET_LEN 14
#define MAX_NUME 50
typedef struct {
    char nume[MAX_NUME];
    char prono[MAX_BILET_LEN];
    int exacte;
} bilet_t;


int numara_egale(char *v1, int n1, char *v2, int n2)
{
    int cnt = 0;
    for (int i = 0; i < n1 && i < n2; i++)
        if (v1[i] == v2[i])
            cnt++;
    return cnt;
}
void sort_bilete(bilet_t *b, int n)
{
    int t = 0;
    while (t == 0) {
        t = 1;
        for (int i = 0; i < n - 1; i++)
            if (b[i].exacte < b[i + 1].exacte) {
                t = 1;
                bilet_t aux = b[i];
                b[i] = b[i + 1];
                b[i + 1] = aux;
            }
    }
}
int main()
{
    bilet_t *bilete;
    char line[1000];
    char delim[] = " {},";
    int n; 
    scanf("%d", &n);
    fgets(line, 1001, stdin);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            bilete = malloc(1 * sizeof(bilet_t));
        } else {
            bilet_t *tmp = realloc(bilete, (i + 1) * sizeof(bilet_t));
            if (!tmp) {
                free(bilete);
                printf("eroare\n");
                return 1;
            }
            bilete = tmp;
        }
        fgets(line, 1001, stdin);
        char *p = strtok(line, delim);
        int cnt = 0;
        strcpy(bilete[i].nume, "");
        strcpy(bilete[i].prono, "");
        while (p) {
            cnt++;
            if (cnt <= 2) {
                strcat(bilete[i].nume, p);
            } else {
                strcat(bilete[i].prono, p);
            }
            p = strtok(NULL, delim);
        }
    }
    char rez[14];
    strcpy(rez, "");
    fgets(line, 1001, stdin);
    char *p = strtok(line, delim);
    while (p) {
        strcat(rez, p);
        p = strtok(NULL, delim);
    }
    for (int i = 0; i < n; i++) {
        bilete[i].exacte = numara_egale(bilete[i].prono, 13, rez, 13);
        printf("%s - %d\n", bilete[i].nume, bilete[i].exacte);
    }
    sort_bilete(bilete, n);
    for (int i = 0; i < n; i++) {
        printf("%s, ", bilete[i].nume);
    }
    return 0;
}

