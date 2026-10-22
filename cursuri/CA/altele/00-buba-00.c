// Să se scrie un program care citește un număr natural n.
// Apoi citește un șir cu n numere întregi numit v.
// 1. Calculează și afișează suma numerelor.
// 2. Calculează și afișează produsul numerelor.
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int sum = 0, product = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);

        // 1. calculam suma
        sum += x;
        // 2. calculam suma
        product *= x;
    }
    
    printf("sum = %d\n", sum);
    printf("product = %d\n", product);

    return 0;
}
