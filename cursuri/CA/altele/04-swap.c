#include <stdio.h>

void swap_int(int a, int b)
{
    printf("+++: a = %d b = %d\n", a, b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("---: a = %d b = %d\n", a, b);
}

int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("before swap: a = %d b = %d\n", a, b);

    swap_int(a, b);

    printf(" after swap: a = %d b = %d\n", a, b);

    return 0;
}

// Ce face codul?
// Sa mutam codul intr-o functie.
// Desen la tabla.