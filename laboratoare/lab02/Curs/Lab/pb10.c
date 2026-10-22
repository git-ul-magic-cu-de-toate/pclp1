#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);

    if (x == 1)
    {
        printf("1\n");
        return 0;
    }

    while (x != 1)
    {
        printf("%d ", x);

        if (x % 2 == 0)
        {
            x -= 1;    
        }
        else
        {
            x = (x + 1) /2;
        }

    }

    printf("1\n");

    return 0;
}