// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

void swap_int(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void)
{
	int a = 3, b = 5;
	printf("before: a = %d b = %d\n", a, b);

	swap_int(a, b); // swap wrong???

	printf("after : a = %d b = %d\n", a, b);
	return 0;
}
