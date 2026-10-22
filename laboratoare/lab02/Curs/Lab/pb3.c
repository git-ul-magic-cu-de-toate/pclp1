#include <stdio.h>

int main (void)
{
    int a, b, n;

    scanf("%d%d", &n, &a);

    for( int i = 0; i < n - 1; i++){
        scanf("%d", &b);

        while (a!=b)
        {
            if (a>b) 
                a=a-b;
            else
                b=b-a;
        }

        a=b;
    }
    printf("%d\n", a);

    return 0;
}