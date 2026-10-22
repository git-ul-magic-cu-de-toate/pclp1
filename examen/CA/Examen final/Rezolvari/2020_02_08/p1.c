#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#



#
typedef struct 
{
    double x, y;

}punct;

typedef struct
{
    double b; // taietura cu axa OY (0, b)
    double a; // panta dreptei
}dreapta;

void determina_pozite(dreapta d1, dreapta d2, punct *inters, short *poz);
void elimina_dubluri(dreapta *d, int *n);
void print_dreapta(dreapta d);
void print_punct(punct p);













int main(void)
{
    int n;
    dreapta *d;
    scanf("%d", &n);
    d = (dreapta *)malloc(n * sizeof(dreapta));
    if (!d) {
        printf("NU am putut aloca\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &d[i].a, &d[i].b);
    }
    elimina_dubluri(d, &n);
    dreapta *tmp = (dreapta *)realloc(d, n * sizeof(dreapta));
    if (!tmp) {
        printf("NU am putut realoca\n");
        return 2;
    }
    d = tmp;
    printf("%d\n", n);
    for (int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) {
            short poz = -1;
            punct p;
            determina_pozite(d[i], d[j], &p, &poz);
            if (poz == 0) {
                printf("paralele: ");
                print_dreapta(d[i]);
                print_dreapta(d[j]);
                printf("\n");
            } else {
                printf("concurente: ");
                print_dreapta(d[i]);
                print_dreapta(d[j]);
                print_punct(p);
                printf("\n");
            }
        }
    free(d);
    return 0;
}

void determina_pozite(dreapta d1, dreapta d2, punct *inters, short *poz)
{
    if (d1.a == d2.a) {
        *poz = 0;
        return;
        // nu se intersecteaza
        // *inters ramane ceva garbage
    }
    // cele 2 drepte se intersecteaza, deci avem sistemul
    // y = a1 * x + b1
    // y = a2 * x + b2
    // x = (b2 - b1) / (a1 - a2)
    // y = a1 * (b2 - b1) / (a1 - a2) + b1
    *poz = 1;
    inters->x = (d2.b - d1.b) / (d1.a - d2.a);
    inters->y = d1.a * inters->x + d1.b;
}

void elimina_dubluri(dreapta *d, int *n)
{
    for (int i = 0; i < (*n) - 1; i++)
        for (int j = i + 1; j < (*n); j++) {
            if (d[i].a == d[j].a && d[i].b == d[j].b) {
                dreapta aux = d[j];
                d[j] = d[(*n) - 1];
                d[(*n) - 1] = d[j];
                (*n)--;
                j--;
            } // drepte confundate
        }
}

void print_dreapta(dreapta d)
{
    printf("y = %lf * x + %lf ", d.a, d.b);
}
void print_punct(punct p)
{
    printf("(%lf, %lf) ", p.x, p.y);
}
