#include <stdio.h>

int main(void)
{
        int k;
        scanf("%d", &k);
        printf("%d %d\n", k * (k + 1) / 2, k * (k + 1) * (2 * k + 1) / 6);
	return 0;
}
