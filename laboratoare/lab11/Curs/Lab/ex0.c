#include <stdio.h>

int is_even(int n)
{
	if ((n & 1) == 0) {
		return 1;
	}

	return 0;
}

int main(void)
{
	printf("%d\n", is_even(5));

	printf("%d\n", is_even(10));

	return 0;
}
