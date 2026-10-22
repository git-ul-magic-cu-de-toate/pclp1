#include <stdio.h>

int main (void)
{
    int n, k = -1, v[11], nr;

    scanf("%d", &n);

    do {
        v[++k] = n % 10;
        n /= 10;
    } while (n);

    for (int i = 0; i <= k; i++)
        printf("%d ", v[i]);

    for (int i = k; i > 0; i--)
        if (i % 2 == 1)
            nr = nr * 10 + v[i];

    printf("%d\n", nr);

    return 0;
}