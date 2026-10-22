#include <stdio.h>

int main(void)
{
    int N, a[1000], b[1000];

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", a[i]);
    }
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", b[i]);
    }
    return 0;
}