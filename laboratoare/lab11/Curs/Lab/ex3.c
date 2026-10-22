#include <stdio.h>

void print_bits(int n)
{
	int found = 0;

	for (int i = 31; i >= 0; --i) {
		if (((n >> i) & 1) == 1) {
			found = 1;
		}

		if (found) {
			printf("%d", (n >> i) & 1);
		}
	}

	printf("\n");
}

int main(void)
{
	print_bits(12);

	return 0;
}
