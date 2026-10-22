#include <stdio.h>

int main(void)
{
    int n, f = 1;

    scanf("%d", &n);

    for(int i = 2; i <= n; i++)
    {
        f = f * i;
    }

    printf("%d\n", f);

	return 0;
}
