// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 100

void draw_vector_layout(int n, int v[NMAX])
{
	printf("addr:   ");
	for (int i = 0; i < n; ++i) {
		printf("%10p ", &v[i]);
	}
	printf("\n");

	printf("index: ");
	for (int i = 0; i < n; ++i) {
		printf("%10d ", i);
	}
	printf("\n");

	printf("v:     ");
	for (int i = 0; i < n; ++i) {
		printf("%10d ", v[i]);
	}
	printf("\n");

	printf("\n");
}

int main(void)
{
	int x;
	int y;
	char a;
	char b;

	printf("print address for some varibles\n");
	printf("&x = %p\n", &x);
	printf("&y = %p\n", &y);
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("\n");

	int n  = 5;
	int v[100] = {10, 20, 30, 40, 50};
	draw_vector_layout(n, v);

	return 0;
}

// make run src=01-example.c
// rm -f *.o *.exe
// gcc -m32 -Wall -Wextra -std=c99   -c -o 01-example.o 01-example.c
// gcc -m32 -Wall -Wextra -std=c99 01-example.o -o 01-example.exe -lm
// ./01-example.exe
// print address for some varibles
// &x = 0xffb3bd10
// &y = 0xffb3bd14
// &a = 0xffb3bd0e
// &b = 0xffb3bd0f
//
// addr:   0xffb3bd1c 0xffb3bd20 0xffb3bd24 0xffb3bd28 0xffb3bd2c
// index:          0          1          2          3          4
// v:             10         20         30         40         50
