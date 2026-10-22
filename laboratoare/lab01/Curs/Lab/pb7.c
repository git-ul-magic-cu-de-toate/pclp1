#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2;

    // Citim cele două numere reale de la tastatură
    printf("Introdu doua numere reale: ");
    scanf("%lf %lf", &num1, &num2);

    // Verificăm dacă sunt egale cu o precizie de 4 zecimale
    if (fabs(num1 - num2) < 0.0001) {
        printf("EQ\n");
    } else {
        printf("NOT EQ\n");
    }

    return 0;
}