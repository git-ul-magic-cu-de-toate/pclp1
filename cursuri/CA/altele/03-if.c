#include <stdio.h>

int main(void)
{
	// instructiunea if: aplicare - determinare minim si maxim
	int a, b;
	scanf("%d%d", &a, &b);

	int min, max;
	if (a > b) {
		min = b;
		max = a;
	} else {
		min = a;
		max = b;
	}
	printf("min = %d max = %d\n", min, max);
	
	// instructiunea if: aplicare
	// determinare daca un numar e de forma 3k, 3k+1 sau 3k + 2
	int n;
	scanf("%d", &n);

	if (n % 3 == 0) {
		printf("%d este de forma 3k\n", n);
	} else if (n % 3 == 1) {
		printf("%d este de forma 3k+1\n", n);
	} else { // se poate pune sau omite else if  (n % 3 == 2)
		printf("%d este de forma 3k+2\n", n);
	}

	return 0;
}
