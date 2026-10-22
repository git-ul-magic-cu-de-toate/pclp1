#include <stdio.h>

int suma_divizori(int n)
{
    int sum = 0, d;
    for (d = 2; d * d < n; d++)
        if (n % d == 0)
            sum = sum + d + n / d; // perechea a caror membrii inmultiti dau nr
    if (d * d == n)                  // in caz ca este patrat perfect adunam doar o data
        sum = sum + d;
    return sum;
}

void list_divizori(int x)
{
    for (int d = 2; d <= x/2; d++)
        if (x % d == 0)
            printf("%d ", d);
    printf("\n");
}

int f(int a, int b, int c, int x)
{
    return a * x * x + b * x + c;
}

int baza2_baza10(int x)
{
    int nr = 0, pow = 1;
    while (x)
    {
        nr += pow * x % 10;
        x /= 10;
        pow *= 2;
    }
    return nr;
}

int baza10_baza2(int x)
{
    int nr = 0, pow = 1;
    while (x)
    {
        nr += pow * (x % 2);
        pow *= 10;
        x /= 2;
    }
    return nr;
}