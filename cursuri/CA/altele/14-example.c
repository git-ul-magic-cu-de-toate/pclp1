// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 100

void f(int v[NMAX])
{
	v[0] = 1;
}

void g(int v[])
{
	v[0] = 2;
}

void h(int *v)
{
	v[0] = 3;

	// v[i] =...
}

int main(void)
{
	int v[NMAX];
	v[0] = -2018;
	printf("%d\n", v[0]);

	f(v);
	printf("%d\n", v[0]);

	g(v);
	printf("%d\n", v[0]);

	h(v);
	printf("%d\n", v[0]);

	return 0;
}
