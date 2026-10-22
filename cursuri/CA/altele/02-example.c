// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 100

void f(int x, int v[NMAX])
{
	printf("   f:   &x  = %p\n",  &x);
	printf("          v = %p\n", v);
	printf("   f: &v[0] = %p\n", &v[0]);

	v[0] = -1;
}

int main(void)
{
	int x = 10;
	int v[NMAX];

	printf("main:   &x  = %p\n",  &x);
	printf("          v = %p\n", v);
	printf("main: &v[0] = %p\n", &v[0]);
	v[0] = 0;
	f(x, v);
	printf("%d\n", v[0]);

	return 0;
}
