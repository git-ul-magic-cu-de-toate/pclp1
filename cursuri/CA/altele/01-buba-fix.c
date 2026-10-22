// Să se scrie un program care citește un număr natural n.
// Apoi citește un șir cu n numere întregi numit v.
// Vom calcula suma si produsul.
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int v[100];

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);

        sum += v[i];
        v[i] = -v[i];
    }

    printf("sum = %d\n", sum);


    return 0;
}


// TODO 1: Foloseste vector de 100 de elemente.
// TODO 2: Explicatie alocare și initializare elemente. Printam vectorul.
// TODO 3: Define ftw.
