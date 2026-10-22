#include <stdio.h>

typedef struct complex {
        float re, im;
} complex;

complex adunare(complex a, complex b)
{
        complex c;
        c.re = a.re + b.re;
        c.im = a.im + b.im;
        return c;
}

complex scadere(complex a, complex b)
{
        complex c;
        c.re = a.re - b.re;
        c.im = a.im - b.im;
        return c;
}

complex inmultire(complex a, complex b)
{
        complex c;
        c.re = a.re * b.re - a.im * b.im;
        c.im = a.im * b.re + a.re * b.im;
        return c;
}

complex putere(complex a, int putere)
{
        complex c;
        int i;
        c.re = 1;
        c.im = 0;
        for (i = 0; i < putere; i++)
                c = inmultire(c, a);
        return c;
}

void scrie(complex a)
{
        printf("(%.2f, %.2f)\n", a.re, a.im);
}

int main()
{
        int n, i;
        float c[100];
        complex x, p, aux;
        scanf("%d", &n); //grad
        for (i = 0; i <= n; i++)
                scanf("%f", &c[i]); // coeficientii
        scanf("%f", &x.re); // partea reala
        scanf("%f", &x.im); //partea imaginara
        p.re = p.im = 0;
        for (i = 0; i <= n; i++) {
                aux.re = c[i];
                aux.im = 0;
                p = adunare(p, inmultire(aux, putere(x, i)));
        }
        scrie(p);
        return 0;
}

