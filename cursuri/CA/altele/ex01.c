#include <stdio.h>

int main(void) 
{
    long n, S, i, x;

    scanf("%ld", &n);

    for (i = 0, S = 0; scanf("%ld", &x), i < n; i++, S += x);

    S += x;

    printf("%ld\n", S);

    // int a = 1, b = a, c = b;
    // printf("%d %d %d\n", a, b, c);
    return 0;
}