#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int zi, luna, an;
} date_t;

typedef struct {
    date_t data;
    char nume[31];
} eveniment_t;
typedef struct {
    char nume[31], prenume[31];
    date_t data_nastere;
    int n;
    eveniment_t *ev;
} persoana_t;

int get_age(date_t date, persoana_t pers);

persoana_t *read_persons(FILE *in, int *n);

eveniment_t *read_events(FILE *in, int *n);

int compare_dates(date_t a, date_t b);

void sort_events(int n, eveniment_t *events);

void print_events(int n_ev, eveniment_t *ev, int n_p, persoana_t *pers);






int main()
{
    FILE *fp = fopen("persoane.bin", "rb");
    FILE *fev = fopen("evenimente.bin", "rb");
    if (!fp || !fev) {
        fclose(fp);
        fclose(fev);
        printf("Could not open file\n");
        return 1;
    }
    persoana_t *pers;
    int n_p = 0, n_ev = 0;
    pers = read_persons(fp, &n_p);
    eveniment_t *ev;
    ev = read_events(fev, &n_ev);
    sort_events(n_ev, ev);
    print_events(n_ev, ev, n_p, pers);
    for (int i = 0; i < n_p; i++)
        free(pers[i].ev);
    free(pers);
    free(ev);
    return 0;
}

int get_age(date_t date, persoana_t pers)
{
    if (pers.data_nastere.luna >= date.luna && pers.data_nastere.zi >= date.zi)
        return pers.data_nastere.an - date.an;
    else
        return pers.data_nastere.an - date.an - 1;
}

persoana_t *read_persons(FILE *in, int *n)
{
    persoana_t *pers;
    int cnt = 0;
    while (1) {
        cnt++;
        if (cnt == 1) {
            pers = malloc(1 * sizeof(persoana_t));
            if (!pers) {
                printf("eroare\n");
                return NULL;
            }
        } else {
            persoana_t *tmp = realloc(pers, cnt * sizeof(persoana_t));
            if (!tmp) {
                free(pers);
                printf("Eroaare\n");
                return NULL;
            }
            pers = tmp;
        }
        if (fread(pers[cnt - 1].nume, sizeof(char), 31, in) <= 0) {
            break;
            cnt--;
        }
        fread(pers[cnt - 1].prenume, sizeof(char), 31, in);
        fread(&pers[cnt - 1].data_nastere.zi, sizeof(int), 1, in);
        fread(&pers[cnt - 1].data_nastere.luna, sizeof(int), 1, in);
        fread(&pers[cnt - 1].data_nastere.an, sizeof(int), 1, in);
        fread(&pers[cnt - 1].n, sizeof(int), 1, in);
        pers[cnt - 1].ev = malloc(pers[cnt - 1].n * sizeof(eveniment_t));
        if (!pers[cnt - 1].ev) {
            printf("eroare mare\n");
            free(pers);
            return NULL;
        }
        for (int i = 0; i < pers[cnt - 1].n; i++) {
            fread(&pers[cnt - 1].ev[i].nume, sizeof(char), 31, in);
            fread(&pers[cnt - 1].ev[i].data.zi, sizeof(int), 1, in);
            fread(&pers[cnt - 1].ev[i].data.luna, sizeof(int), 1, in);
            fread(&pers[cnt - 1].ev[i].data.an, sizeof(int), 1, in);
        }
    }
    *n = cnt;
}

eveniment_t *read_events(FILE *in, int *n)
{
    eveniment_t *events;
    int cnt = 0;
    while (1) {
        cnt++;
        if (cnt == 1) {
            events = malloc(1 * sizeof(eveniment_t));
            if (!events) {
                printf("Erori...erori...\n");
                return NULL;
            }
        } else {
            eveniment_t *tmp = realloc(events, cnt * sizeof(eveniment_t));
            if (!tmp) {
                printf("Erori..iarasi..\n");
                free(events);
                return NULL;
            }
            events = tmp;
        }
        if (fread(&events[cnt - 1].nume, sizeof(char), 31, in)) {
            cnt--;
            break;
        }
        fread(&events[cnt - 1].data.zi, sizeof(int), 1, in);
        fread(&events[cnt - 1].data.luna, sizeof(int), 1, in);
        fread(&events[cnt - 1].data.an, sizeof(int), 1, in);
    }
    *n = cnt;
    return events;
}

int compare_dates(date_t a, date_t b)
{
    if (a.an < b.an)
        return -1;
    else if (a.an == b.an && a.luna < b.luna)
        return -1;
    else if (a.an == b.an && a.luna == b.luna && a.zi < b.zi)
        return -1;
    else if (a.an == b.an && a.luna == b.luna && a.zi == b.zi)
        return 0;
    return 1;
}

void sort_events(int n, eveniment_t *events)
{
    int t = 0;
    while (t == 0) {
        t = 1;
        for (int i = 0; i < n - 1; i++)
            if (compare_dates(events[i].data, events[i + 1].data) > 0) {
                date_t aux = events[i].data;
                events[i].data = events[i + 1].data;
                events[i + 1].data = aux;
                t = 0;
            }
    }
}

void print_events(int n_ev, eveniment_t *ev, int n_p, persoana_t *pers)
{
    for (int i = 0; i < n_ev; i++) {
        printf("%d %d %d %s\n", ev[i].data.zi, ev[i].data.luna, ev[i].data.an, ev[i].nume);
        for (int j = 0; j < n_p; j++) {
            for (int k = 0; k < pers[j].n; k++)
                if (compare_dates(pers[j].data_nastere, pers[j].ev[k].data) <= 0 &&
                    compare_dates(pers[j].ev[k].data, ev[i].data) == 0) {
                    printf("%s %s\n", pers[j].nume, pers[j].prenume);
                }
        }
        printf("\n");
    }
}
