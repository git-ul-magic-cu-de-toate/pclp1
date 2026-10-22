#include <stdio.h>
int main() {
    int i = 0;
    unsigned int cod = 0 , N = 1 , op[8] , Dim = 0;
    unsigned int mask = 1 << 31;
    scanf("%u" , &cod);
    for (i = 0 ; i <= 2 ; i++) {
        N += (cod & mask);
        mask >>= 1;
    }
    N >>= 29;
    N++;
    for (i = 0 ; i <= N - 1 ; i++) {
        op[i] = 0;
        op[i] += (cod & mask);
        op[i] += (cod & (mask >> 1));
        mask >>= 2;
        op[i] >>= (29 - 2 * (i + 1));
    }
    for (i = 0 ; i <= 3 ; i++) {
        Dim += (cod & mask);
        mask >>= 1;
    }
    Dim >>= (25 - 2 * N);
    Dim++;
    // calculul a cate numere trebuie citite de la tastatura
    unsigned short numberstoscan = 0;
    numberstoscan = ((N + 1) * Dim) / 16;
    if (((N + 1) * Dim) % 16 != 0) {
        // daca rezultatul impartirii la 16 este cu rest, atunci adunam un 1
        numberstoscan++;
    }
    // citirea de la tastatura a numerelor si descompunerea lor in operanzi
    unsigned short nr[9] = {0};
    int k = 0;
    for (i = 0 ; i < numberstoscan ; i++) {
        unsigned short sacrifice = 0;
        // citirea de la tastatura a numerelor
        scanf("%hu", &sacrifice);
        // reinitializarea mastii (acum lucram pe 16 biti)
        mask = 1 << 15;
        // parcurgem cei 16 biti, si ii grupam cate Dim
        for (int j = 0 ; j < 16 ; j++) {
            nr[k] += (sacrifice & mask);
            mask >>= 1;
            /*
            daca (j+1) este multiplu de Dim, 
            atunci shiftam la dreapta cu 16-(j+1)
            */
            if ((j + 1) % Dim == 0) {
                nr[k] >>= 16 - (j + 1);
                // dupa verificarea a Dim biti, trecem la urmatorul operand
                k++;
            }
        }
    }
    // executarea instructiunii
    // rezultatul este initializat cu primul operand
    int rez = nr[0];
    for (i = 0 ; i < N ; i++) {
        /*
        in functie valoarea lui op[i] 
        (respectiv operatia pe care o reprezinta), 
        se calculeaza rezultatul dintre primii i operanzi
        */
        if (op[i] == 0) {
            rez += nr[i + 1];
        } else
            if (op[i] == 1) {
                rez -= nr[i + 1];
        } else
            if (op[i] == 2) {
                rez *= nr[i + 1];
        } else
            if (op[i] == 3) {
                rez /= nr[i + 1];
        }
    }
    printf("%d", rez);
    printf("\n");
    }