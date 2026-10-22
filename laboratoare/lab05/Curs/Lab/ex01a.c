#include <stdio.h>

int main(void)
{
	int *a = 0x00;
	int *b = a;
	++a;

	printf("%p %p %ld\n", a, b, sizeof(void *));

	return 0;
}