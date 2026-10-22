// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	int x = 10;
	int *p = &x; // p este legat ACUM la x

	printf("%p\n", &x);
	printf("%p\n", p);

	printf("%d\n", x);
	printf("%d\n", *p);

	x = -1;
	printf("%d\n", *p);
	*p = 2;
	printf("%d\n", x);

	int y = 11;
	p = &y; // p este legat ACUM la y
	printf("%p\n", &y);
	printf("%p\n", &p);

	printf("%d\n", x);
	printf("%d\n", y);
	*p = 123;
	printf("%d\n", x);
	printf("%d\n", y);

	return 0;
}
