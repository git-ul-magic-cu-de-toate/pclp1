#include <stdio.h>
int main() {
    // declararea variabilelor
    int i = 0;
    unsigned int cod = 0, N = 1, op[8], Dim = 0;
    // initializarea mastii
    unsigned int mask = 1 << 31;
    // citirea de la tastatura a codului
    scanf("%u" , &cod);
    // calculul numarului de instructiuni
    for (i = 0 ; i <= 2 ; i++) {
    // N are 3 biti, i-ul ia valori de la 0 la 2
        // N se obtine prin mascarea bitului curent
        N += (cod & mask);
        mask >>= 1;
    }
    // shiftam  pe cele mai nesemnificative 3 pozitii
    N >>= 29;
    // pentru ca N sa ia valori de la 1 la 8, se aduna cu 1
    N++;
    printf("%u ", N);
    // calculul operatorilor cu ajutorul unui vector
    for (i = 0 ; i <= N - 1 ; i++) {
    // deoarece sunt N operatii, i-ul ia valoari de la 0 la N-1
        op[i] = 0;
        /*
        operatorul se obtine prin mascarea
        bitului curent si a urmatorului bit
        */
        op[i] += (cod & mask);
        op[i] += (cod & (mask >> 1));
        mask >>= 2;
        /*
        trecand de cei 3 biti ai lui N vom shifta
        la dreapta cu 32-3-2*(i+1) bitii operatiilor 
        aferente, pe cele mai nesemnificative pozitii
        */
        op[i] >>= (29 - 2 * (i + 1));
        if (op[i] == 0) {
            printf("+ ");
        } else
            if (op[i] == 1) {
                printf("- ");
        } else
            if (op[i] == 2) {
                printf("* ");
        } else
            if (op[i] == 3) {
                printf("/ ");
        }
    }
    // calculul dimensiunii unui operand
    for (i = 0 ; i <= 3 ; i++) {
    // Dim fiind reprezentat pe 4 biti, i-ul ia valori de la 0 la 3
        Dim += (cod & mask);
        mask >>= 1 ;
    }
    /* 
    dupa ce am parcurs cei 3 biti ai lui N si cei 2*N biti ai operatorilor,
    raman de aflat cei 4 biti ai dimensiunii unui operand de pe cele mai
    nesemnificative pozitii, prin urmare vom shifta la dreapta cu 32-3-2*N-4
    */
    Dim >>= (25 - 2 * N);
    // asemanator lui N, pentru ca Dim sa ia valori de la 1 la 16, se adauga 1
    Dim++;
    printf("%u", Dim);
    printf("\n");
    }