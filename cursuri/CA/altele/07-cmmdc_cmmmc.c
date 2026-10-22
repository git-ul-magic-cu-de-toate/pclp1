#include <stdio.h>

int main(void)
{
	// cititi 2 numere naturale x si y. 
    // calculati si afisati cmmdc(x, y) si cmmmc(x, y)
    int x, y;
    scanf("%d%d", &x, &y);
    // x = 10, y = 5
    // cmmdc(x, y) = 5
    // cmmmc(x, y) = 10
    
    int a = x, b = y;
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    int cmmdc = a;
    int cmmmc = x * y / cmmdc;

    printf("cmmdc = %d\n", cmmdc);
    printf("cmmmc = %d\n", cmmmc);

	return 0;
}
