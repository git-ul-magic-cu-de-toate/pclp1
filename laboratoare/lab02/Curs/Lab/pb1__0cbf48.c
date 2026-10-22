#include <stdio.h>

int main(void)
{
	int n, g = 0;

	scanf("%d", &n);

	if(n % 2 == 0)
		printf("par\n");
	else 
		printf("impar\n");
	
	if(n / 2 * 2 == n)
		printf("par\n");
	else
		printf("impar\n");
	
	return 0;
}
