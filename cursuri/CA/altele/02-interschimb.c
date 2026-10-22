#include <stdio.h>

int main(void)
{
    // interschimbare cu aux
    int a, b;
    scanf("%d%d", &a, &b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("a = %d b = %d\n", a, b);
}