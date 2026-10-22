#include <stdio.h>
#include <math.h> // sqrt(x)

int main(void)
{
	// instructiunea for: ciclu repetitiv cu numar determinat de pasi
    // aplicatie 1 - afișare de șiruri
    int n = 50;

    // afiseaza: 1, 2, 3, ..., n
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // afiseaza 1, 3, 5, ... (pana la n)
    for (int i = 1; i <= n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    // afiseaza 2, 4, 6, ... (pana la n)
    for (int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    // afiseaza 2, 6, 10, 14, ... (pana la n)
    for (int i = 2; i <= n; i += 4) {
        printf("%d ", i);
    }
    printf("\n");

    // afiseaza n, n - 6, n - 12, ... (pana la 2)
    for (int i = n; i >= 2; i -= 6) {
        printf("%d ", i);
    }
    printf("\n");

    // calculeaza suma tuturor numerelor
    // de la 1 la n care indeplinesc urmatoarele conditii:
    // 1. sunt divizibile cu 5
    // 2. NU sunt divizibile cu 7
    // 3. numarul 20 nu se adauga la suma
    n = 50;
    int sum = 0; // x % 5 == 0, x % 7 != 0, x != 20
    for (int i = 0; i <= n; i++) {
        if (i % 5 == 0 && i % 7 != 0 && i != 20) {
            sum += i;
        }
    }
    printf("sum = %d\n", sum);

    // aplicatie 2 - afișare triunghi
    // Sa se afiseze n linii, unde pe fiecare linie i
    // se vor afisa i stelute.
    // Exemplu: n = 7
    // *
    // **
    // ***
    // ****
    // *****
    // ******
    // *******
    //
    n = 7;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // Acelasi lucru, dar liniile sa fie inversate:
    // n = 7
    // *******
    // ******
    // *****
    // ****
    // ***
    // **
    // *
    //
    n = 7;
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");


    // aplicatie 3 - calcul suma primelor n numere patrate perfecte
    // 1. Solutie 1: parcurgem toate numerele de la 1 la n
    // Pastram doar pe cele care sunt bune
    // 2. Solutie 2:
    for (int i = 0; i * i <= n; i++) {
        sum += i * i;
    }
    printf("sum = %d\n", sum);
	return 0;
}
