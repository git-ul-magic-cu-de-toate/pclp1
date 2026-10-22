#include <stdio.h>
#include "functions.h"

int main(void)
{
    int x, contor_prim = 0;
    scanf("%d", &x);

    while (x >= 0)
    {   
        printf("OUT: ");
        if (suma_divizori(x) == 0)
        {
            printf("PRIM\n");
            contor_prim++;
        }
        else
        {
            list_divizori(x);
        }
        scanf("%d", &x);
    }
    printf("OUT: S-au gasit %d numere prime.\n", contor_prim);
    return 0;
}