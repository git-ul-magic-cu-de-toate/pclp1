#include <stdio.h>

int is_prime(int n) {
    // orice numar negativ, sau 0 si 1 nu sunt prime
    if (n <= 1) {
        return 0;
    }
    
    // 2 e singurul numar par si prim
    if (n == 2) {
        return 1;
    }

    // daca nu e 2, dar e par, nu e prim
    if (n % 2 == 0) {
        return 0;
    } 

    // ramane de verificat numerele pare
    // pana la radical
    // int s = sqrt(n);
    // for (int i = 3; i <= s; i += 2) {
    //     if (n % i == 0) {
    //         return 0;
    //     }
    // }
    for (int i = 3; 1L * i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    // nu am gasit divizori
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", is_prime(n));
    return 0;
}