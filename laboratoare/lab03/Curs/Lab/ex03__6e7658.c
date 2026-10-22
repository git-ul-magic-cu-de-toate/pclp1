#include <stdio.h>
#include <math.h>
#include "functions.h"

int main(void)
{
    double a, b, c, u, v;
    double delta, minim, maxim;

    scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &u, &v);

    delta = b * b - 4 * a * c;

    if (a > 0)
    {
        if (u < -b / (2 * a) && -b / (2 * a) < v)
        {
            minim = -delta / (4 * a);
            if (f(a, b, c, u) > f(a, b, c, v))
                maxim = f(a, b, c, u);
            else
                maxim = f(a, b, c, v);
        }
        if (v < -b / (2 * a))
        {
            minim = f(a, b, c, v);
            maxim = f(a, b, c, u);
        }
        if (-b / (2 * a) < u)
        {
            minim = f(a, b, c, u);
            maxim = f(a, b, c, v);
        }
    }
    else
    {
        if (u < -b / (2 * a) && -b / (2 * a) < v)
        {
            maxim = -delta / (4 * a);
            if (f(a, b, c, u) < f(a, b, c, v))
                minim = f(a, b, c, u);
            else
                minim = f(a, b, c, v);
        }
        if (v < -b / (2 * a))
        {
            maxim = f(a, b, c, v);
            minim = f(a, b, c, u);
        }
        if (-b / (2 * a) < u)
        {
            maxim = f(a, b, c, u);
            minim = f(a, b, c, v);
        }
    }

    printf("minim = %lf\n", minim);
    printf("maxim = %lf\n", maxim);

    double x1, x2;
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);

    if (u <= x1 && x1 <= v)
        printf("%lf\n", x1);
    if (u <= x2 && x2 <= v)
        printf("%lf\n", x2);
    
    return 0;
}