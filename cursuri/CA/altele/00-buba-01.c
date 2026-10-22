// Să se scrie un program care citește un număr natural n.
// Apoi citește un șir cu n numere întregi numit v.
// 1. Calculează și afișează suma numerelor.
// 2. Se mai face o alta operatie cu alt sir - nu conteaza ce.
// 3. Calculează și afișează produsul numerelor din sirul initial.
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    // 1. calculam suma
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);

        sum += x;
    }
    printf("sum = %d\n", sum);

    // 2. aici se face ceva - de exemplu, desenam ponei pe ecran

    // 3. calculam produsul
    int product = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);

        product *= x;
    }
    printf("product = %d\n", product);

    return 0;
}
