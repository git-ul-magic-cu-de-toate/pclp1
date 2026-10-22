#include <stdio.h>

int main(void)
{
	// instructiunea while: ciclu repetitiv cu numar nedeterminat de pasi
    // aplicatie 1 - calcul suma primelor n numere naturale/multipli de 7/patrate perfecte
    // int n;
    // scanf("%d", &n);
    // while (n >= 0) {
    //     printf("n = %d\n", n);
    //     scanf("%d", &n);
    // }
    // printf("Hai Steaua!\n");
    
    int n = 50;
    int i = 1; 
    while (i <= n) {
        printf("%d ", i);
        i += 2;
    }
    printf("\n");
	return 0;
}
