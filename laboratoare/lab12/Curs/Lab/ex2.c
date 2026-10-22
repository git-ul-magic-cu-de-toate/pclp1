#include <stdio.h>
#include <stdarg.h>

int gcd2(int x, int y)
{
	while (y) {
		int r = x % y;
		x = y;
		y = r;
	}

	return x;
}

int gcd(int first, ...)
{
	if (first < 0) {
		return -1;
	}

	// lista de parametri
	va_list args;

	/* initializam lista de parametri */
	va_start(args, first);

	int gcd0 = first;
	int current = va_arg(args, int);

	do {
		gcd0 = gcd2(gcd0, current);
		current = va_arg(args, int);
	} while (current >= 0);

	/* curatam lista de parametrii */
	va_end(args);

	return gcd0;
}

int main(void)
{
	printf("%d\n", gcd(5, 10, -1));
	// va printa 5 pentru ca gcd(5, 10) = 5
	// gcd(5, 10, 2, 100, -1);

	printf("%d\n", gcd(5, 10, 2, 100, -1));
	// va printa 1 pentru ca gcd(5, 10, 2, 100) = 1

	printf("%d\n", gcd(500, 10, 25, 75, -1));
	// va printa 5 pentru ca gcd(500, 10, 25, 75) = 5

	printf("%d\n", gcd(1024, 48, 64, 256, 2048, -1));
	// va printa 16 pentru ca gcd(1024, 48, 64, 256, 2048) = 16

	return 0;
}
