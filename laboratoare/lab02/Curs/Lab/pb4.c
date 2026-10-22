#include <stdio.h>

int main() {
    int x1, x2, x3, x4, x5;
    int cube[101];

    // Calculăm cuburile pentru fiecare valoare din [-50, 50]
    for (int i = -50; i <= 50; i++) {
        cube[i + 50] = i * i * i; // Stocăm cubul valorii i în intervalul [0, 100]
    }

    // Iterăm prin toate combinațiile posibile de x1, x2, x3, x4, x5
    for (x1 = -50; x1 <= 50; x1++) {
        for (x2 = -50; x2 <= 50; x2++) {
            for (x3 = -50; x3 <= 50; x3++) {
                for (x4 = -50; x4 <= 50; x4++) {
                    for (x5 = -50; x5 <= 50; x5++) {
                        if (cube[x1 + 50] + cube[x2 + 50] + cube[x3 + 50] + cube[x4 + 50] + cube[x5 + 50] == 0) {
                            printf("Soluție: x1 = %d, x2 = %d, x3 = %d, x4 = %d, x5 = %d\n", x1, x2, x3, x4, x5);
                        }
                    }
                }
            }
        }
    }

    return 0;
}   