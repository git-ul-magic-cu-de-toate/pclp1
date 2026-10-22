// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	int x = 10;
	int *p = &x;
	printf("&x = %p\n", &x);
	printf(" p = %p\n", p);

	// printf(" x = %d\n", x);
	// printf("*p = %d\n", *p);

	// x = -1;
	// printf("*p = %d\n", *p);
	// *p = 2;
	// printf(" x = %d\n", x);

	return 0;
}
