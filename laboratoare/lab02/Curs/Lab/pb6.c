#include <stdio.h>

int main(void)
{
    int n, cn, inv = 0;

    scanf("%d", &n);

    cn = n;

    while(cn){
        inv = inv * 10 + cn % 10;
        cn /= 10;
    }
    
    printf("%d\n", inv);

    if(n == inv)
        printf("palindrom\n");
    else
        printf("nu e palindrom\n");

	return 0;
}
