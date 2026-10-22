#include <stdio.h>

int main(void)
{
	printf("Size of short int: %ld\n", sizeof(short int));
	printf("Size of int: %ld\n", sizeof(int));
	printf("Size of long int: %ld\n", sizeof(long int));

    short int a;
    int b;
    long int c;

    printf("Size of short int: %ld\n", sizeof(a));
	printf("Size of int: %ld\n", sizeof(b));
	printf("Size of long int: %ld\n", sizeof(c));

	return 0;
}
