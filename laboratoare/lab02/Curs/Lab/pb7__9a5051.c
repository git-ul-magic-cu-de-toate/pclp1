#include <stdio.h>

int prim(int x) 
{
    if (x == 2) { 
        return 1;

    } else if (x < 2) { //Caz particular: n < 2 (nu va fi prim)
        return 0;

    } else if (x % 2 == 0) { //n este > 2. Dacă este par, atunci nu poate fi prim
        return 0;

    } else {
        for (int d = 3; d * d <= x; d += 2) { //Luăm divizori impari: 3, 5, 7, …
            if (x % d == 0) { //Am găsit un divizor diferit de 1 și de n, deci n nu este prim
                return 0;
            }
        }
    }

    return 1;
}

int main (void)
{
    int x, contor_prim = 0;

    scanf("%d", &x);

    while (x > 0) {
        
        if (prim(x) == 1) {
            printf("OUT: PRIM\n");
            contor_prim++;
        }
        else {
            printf("OUT: ");
            for (int d = 2; d < x; d++)
                if (x % d == 0)
                    printf("%d ", d);
            printf("\n");
        }

        scanf("%d", &x);
    }

    printf("OUT: S-au gasit %d numere prime\n", contor_prim);

	return 0;
}
