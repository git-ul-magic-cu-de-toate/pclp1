#include <stdio.h>

#define SQR(x) ((x) * (x))
#define CUBE(x) ((x) * SQR(x))

// int sqr(int x) { return x  * x; }

int main(void)
{
	int x = SQR(2);
	int y = SQR(x);
	int z  = SQR(100 + 13);
	int w = SQR(1 + 2) * SQR(3 + 4);

	return 0;
}
