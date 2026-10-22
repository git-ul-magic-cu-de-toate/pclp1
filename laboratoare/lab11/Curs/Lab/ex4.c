#include <stdio.h>

int is_power2(int n)
{
	if ((n & (n - 1)) == 0) {
		return 1;
	}

	return 0;
}

int main(void)
{
	printf("%d\n", is_power2(5));

	printf("%d\n", is_power2(16));

	return 0;
}
