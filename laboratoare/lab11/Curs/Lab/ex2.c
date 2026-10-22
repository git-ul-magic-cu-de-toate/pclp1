#include <stdio.h>

int flip_bits(int n)
{
	n = ~n;

	return n;
}

int main(void)
{
	printf("%d\n", -flip_bits(5));

	printf("%d\n", -flip_bits(16));

	return 0;
}
