#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);

    int min, max;
    if (a > b){ 
        min = b;
        max = a;
    } else {
        min = a;
        max = b;
    }
    printf("min = %d max = %d\n", min, max);

    int n;
    scanf("%d", &n);
    if (n % 3 == 0) {
        printf("%d este de forma 3k\n", n);
    } else if (n % 3 == 1) {
        printf("%d este de forma 3k+1\n", n);
    } else {
        printf("%d este de forma 3k+2\n", n);
    }
}