#include <stdio.h>
#include "functions.h"

int main(void)
{
    int nr_2, nr_10;

    scanf("%d", &nr_2);

    nr_10 = baza2_baza10(nr_2);
    
    printf("%d\n", nr_10);

    nr_10 = 35;

    nr_2 = baza10_baza2(nr_10);

    printf("%d\n", nr_2);

    return 0;
}