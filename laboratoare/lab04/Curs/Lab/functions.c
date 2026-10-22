#include <stdio.h>

int factorial_iterativ(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact = fact * i;
    return fact;
}

int factorial_recursiv(int n)
{
    if(n == 0)
        return 1;
    return n * factorial_recursiv(n - 1);
}

int suma_cifre_iterativ(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;  
}

int suma_cifre_recursiv(int n)
{
    return n % 10 + suma_cifre_recursiv(n / 10);
}

int este_prim(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int d = 3; d * d <= n; d += 2)
        if (n % d == 0)
            return 0;
    return 1;
}

int este_palindrom(int n)
{
    int invers = 0, copie_n;
    copie_n = n;
    while (n)
    {
        invers = invers * 10 + n % 10;
        n /= 10;
    }

    if (copie_n == invers)
        return 1;
    else
        return 0;
}

void divizori_palindrom(int n)
{
    int d, contor_div_palindrom;
    for (int d = 1; d <= n/2; d++)
        if (n % d == 0)
        {
            if (este_palindrom(d) == 1)
            {
                printf("%d ", d);
                contor_div_palindrom++;
            }
        }
    if (este_palindrom(n) == 1)
    {
        printf("%d ", d);
        contor_div_palindrom++;   
    }

    printf("\n");
    printf("%d\n", contor_div_palindrom);
}

void numere_prime_citire(int contor_prim)
{
    int x;
    scanf("%d", &x);
    if (x == 0)
    {
        printf("%d\n", contor_prim);
        return;
    }
    numere_prime_citire(este_prim(x)+contor_prim);
}