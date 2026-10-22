#include <stdio.h>

int pow2(int n)
{
	return (2 << (n - 1));
}

int main(void)
{
	printf("%d\n", pow2(5));

	printf("%d\n", pow2(2));

	return 0;
}
