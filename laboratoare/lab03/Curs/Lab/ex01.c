#include <stdio.h>
#include "functions.h"

int main(void)
{
    int b, e;
    b = 3;
    e = 0;

    // printf("%d\n", power_iterativ(b, e));

    printf("%d\n", power_recursiv(b, e));
    return 0;
}