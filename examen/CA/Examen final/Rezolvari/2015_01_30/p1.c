#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#




#
typedef struct 
{
    char nume[400];
    int votes;
} actor_t;

actor_t *read_actor(int *n, FILE *in);

void sort_actori(int n, actor_t *actori);

void print_actori(int n, actor_t *actori);






















int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("N-avem destui parametri\n");
        return 1;
    }
    FILE *in = fopen(argv[1], "rt");
    if (!in) {
        printf("N-am putut deschide fisierul in\n");
        return 1;
    }
    int n = 0;
    actor_t *actori = read_actor(&n, in);
    if (!actori) {
        printf("N-am putut citi vere\n");
        return 1;
    }
    sort_actori(n, actori);
    print_actori(n, actori);
    free(actori);
    fclose(in);
    return 0;
}

actor_t *read_actor(int *n, FILE *in)
{
    int nn = 0;
    char line[400];
    actor_t *actori;
    while (fgets(line, 400, in)) {
        line[strlen(line) - 1] = '\0';
        if (nn == 0) {
            actori = (actor_t *)malloc(1 * sizeof(actor_t));
            if (!actori) {
                printf("N-am putut aloca vere\n");
                return NULL;
            }
            strcpy(actori[0].nume, line);
            actori[0].votes = 1;
            nn++;
        } else {
            int ok = 0;
            for (int i = 0; i < nn; i++)
                if (strcmp(actori[i].nume, line) == 0) {
                    // printf("%s\n", actori[i].nume);
                    actori[i].votes++;
                    ok = 1;
                    break;
                }
            if (ok == 0) {
                actor_t *tmp;
                tmp = realloc(actori, (nn + 1) * sizeof(actor_t));
                if (!tmp) {
                    free(actori);
                    printf("N-am putut aloca vere\n");
                    return NULL;
                }
                actori = tmp;
                strcpy(actori[nn].nume, line);
                actori[nn].votes = 1;
                nn++;
            }
        }
    }
    *n = nn;
    return actori;
}

void sort_actori(int n, actor_t *actori)
{
    int t = 0;
    while (t == 0) {
        t = 1;
        for (int i = 0; i < n - 1; i++)
            if (actori[i].votes < actori[i + 1].votes) {
                actor_t aux = actori[i];
                actori[i] = actori[i + 1];
                actori[i + 1] = aux;
                t = 0;
            }
    }
}

void print_actori(int n, actor_t *actori)
{
    int i = 0;
    while (i < n) {
        int val = actori[i].votes;
        printf("%d - %d\n", val, val - 10);
        while (i < n && actori[i].votes >= val - 10) {
            printf("%s ", actori[i].nume);
            if ((i < n - 1 && actori[i].votes == actori[i + 1].votes) || (i > 0 && actori[i].votes == actori[i - 1].votes)) {
                printf("+");
            }
            printf("\n");
            i++;
        }
        printf("\n");
    }
}