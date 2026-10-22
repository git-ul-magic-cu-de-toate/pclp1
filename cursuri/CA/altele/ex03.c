#include <stdio.h>

int main(void) 
{
    int a, b, c, max;

    scanf("%d%d%d", &a, &b, &c);

    a < b ? (max = b) : (max = a);

    max = max < c ? c : max;

    printf("%d\n", max);
    
    return 0;
}