#include <stdio.h>
#include "functions.h"

int main(void)
{
    printf("%d\n", factorial_iterativ(5));

    printf("%d\n", factorial_recursiv(6));

    printf("%d\n", suma_cifre_iterativ(1234));

    printf("%d\n", suma_cifre_iterativ(1234));

    printf("%d\n", este_prim(123));

    printf("%d\n", este_palindrom(1223221));

    divizori_palindrom(220);

    numere_prime_citire(0);

    return 0;
}