#include <stdio.h>

int hash(int x)
{
    if (x < 0)
        x = x * -1;

    if (x / 10 == 0)
        return x * 4;

    int sum = x % 10 * 2;
    x /= 10;
    if (x > 9)
        do
        {
            sum += x % 10;
            x /= 10;
        } while (x > 9);
    sum += x % 10 * 2;

    return sum;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", hash(n));

    return 0;
}