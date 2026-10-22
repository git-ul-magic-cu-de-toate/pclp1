#include <stdio.h>

int main(void)
{
	float a, b;
	scanf("%f%f", &a, &b);
	printf("%.5f %.5f %.5f\n", a + b, a - b, (a + b) / 2);
	return 0;
}
