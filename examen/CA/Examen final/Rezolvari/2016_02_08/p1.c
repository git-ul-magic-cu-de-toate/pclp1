#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double x, y;
} punct;

typedef struct {
    punct c;
    double r;
} cerc;

typedef struct {
    punct st;
    punct dr;
} dreptunghi;

typedef struct {
    int n;
    punct *p;
} nor;

int in_dreptunghi(punct a, dreptunghi d);

int in_cerc(punct a, cerc c);

int main()
{
    dreptunghi drept;
    cerc cerc;
    nor nor;
    scanf("%d", &nor.n);
    nor.p = (punct *)malloc(nor.n * sizeof(punct));
    for (int i = 0; i < nor.n; i++)
        scanf("%lf%lf", &nor.p[i].x, &nor.p[i].y);
    for (int i = 0; i < nor.n - 1; i++)
        for (int j = i + 1; j < nor.n; j++)
            if (nor.p[i].x == nor.p[j].x && nor.p[i].y == nor.p[j].y) {
                for (int k = j; k < nor.n - 1; k++)
                    nor.p[k] = nor.p[k + 1];
                j--;
                nor.n--;
            }
    punct *tmp = realloc(nor.p, nor.n * sizeof(punct));
    if (!tmp) {
        free(nor.p);
        printf("Avem probleme vere\n");
        return 1;
    }
    nor.p = tmp;
    scanf("%lf%lf%lf", &cerc.c.x, &cerc.c.y, &cerc.r);
    scanf("%lf%lf%lf%lf", &drept.dr.x, &drept.dr.y, &drept.st.x, &drept.st.y);
    int cntdr = 0, cntcerc = 0;
    for (int i = 0; i < nor.n; i++) {
        if (in_cerc(nor.p[i], cerc))
            cntcerc++;
        if (in_dreptunghi(nor.p[i], drept))
            cntdr++;
    }
    printf("In dreptunghi : %d\n", cntdr);
    printf("In cerc : %d\n", cntcerc);
    return 0;
}

int in_dreptunghi(punct a, dreptunghi d)
{
    if (a.x >= d.st.x && a.x <= d.dr.x && a.y >= d.st.y && a.y <= d.dr.y)
        return 1;
    return 0;
}

int in_cerc(punct a, cerc c)
{
    if ((a.x - c.c.x) * (a.x - c.c.x) + (a.y - c.c.y) * (a.y - c.c.y) <= c.r * c.r)
        return 1;
    return 0;
}   