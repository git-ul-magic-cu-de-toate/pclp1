#include <stdio.h>
#include <math.h>

int is_square(int n)
{
    double s = sqrt(n);
    printf("%lf\n", s);
    printf("%d\n", (int)s);
    return (int)s == s;
}

int main(void)
{
    int n;

    scanf("%d", &n);

    printf("%d\n", is_square(n));

    return 0;
}