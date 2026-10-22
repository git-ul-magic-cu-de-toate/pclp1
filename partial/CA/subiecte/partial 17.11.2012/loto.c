/* 
loto.c
Created by Florin Pop on 17.11.2012.
Copyright (c) 2012 Florin Pop. All rights reserved.
*/

#include <stdio.h>

#define LOTO_SIZE 49
#define WINNER_SIZE 6

/* Functie pentru calcului combinarilor C(n,k). */
int C(int, int);

/* Functie de sortate descrescatoare in functie de frecvente,
 specifica jouclui LOTO 6 din 49 (sau generic: WINNER_SIZE din LOTO_SIZE) */
void loto_sort(int[2][LOTO_SIZE]);

int main(){
    int numere[2][LOTO_SIZE];	
    int f[WINNER_SIZE]={0}, f_crt;
    int extragere, n, i, j, S, nr_crt;
    
    /* Initalizam jocul de LOTO: o matrice de 2 linii si LOTO_SIZE coloane:
        - prima linie contine numere in ordine crescatoare de la 1 la LOTO_SIZE
        - a doua linie contine frecventa de aparitie a unui numar in setul de extrageri
     */
    for(i = 0; i < LOTO_SIZE; i++){
        numere[0][i]=(i+1);
        numere[1][i]=0;
    }
    
    scanf("%d", &n);
    
    /* se parcurg toate extragerile si se actualizeaza frecventa fiecarui numar extras */
    for (extragere = 0; extragere < n; extragere++){
        for(i = 0; i < WINNER_SIZE; i++){
            scanf("%d", &nr_crt);
            // actualizeaza frecventa numarului extras
            numere[1][nr_crt-1]++;
        }
    }
    
    /* Sortam descrescator in functie de frecvente si afisam primele WINNER_SIZE valori. */
    loto_sort(numere);
    
    for(i = 0; i < WINNER_SIZE; i++){
        printf("%d ", numere[0][i]);
    }
    
    /* Compactam vectorului de frecvente astfel incat f[i] sa retina cate numere din jocul de LOTO
        au frecventa de aparitie in extragerile introduse egala cu fmax - i (i=0..WINNER_SIZE-1), unde fmax
        este frecventa maxima de aparitie a unui numar (numere[1][0], dupa sortarea tabloului de numere). */
    for(i = 0, f_crt = 0, j = 0; i < LOTO_SIZE-1; i++){
        f_crt++;
        if(numere[1][i]!=numere[1][i+1]){
            f[j++] = f_crt;
            f_crt = 0;
            if(j == WINNER_SIZE){ break; }
        }
    }
    
    /* Determinam cate variante posibile pentru castig avem: se calculeaza o suma partiala S a elementelor
        f[i], incepand cu i=0. Cand S+f[i] depaseste WINNER_SIZE ne oprim. Toate numerele cu frecventele
        f[0], ..., f[i-1] vor fi jucate sigur, iar combinatiile posibile se pot face din numerele de frecventa
        f[i] considerand numai cate numere mai sunt necesare pentru a avea WINNER_SIZE numere. */
    for(i = 0, S = 0; i < WINNER_SIZE; i++){
        if(S+f[i] >= WINNER_SIZE){
            printf("\nVariante posibile de castig: %d\n", C(f[i], WINNER_SIZE-S));
            break;
        } else {
            S += f[i];
        }
    }
    
    return 0;
}

/***** Implementarea functiile definite pentru rezolvarea problemei *****/

int C(int n, int k){
    if (n==k || k==0){ return 1; }
    return C(n,k-1)*(n-k+1)/k;
}

void loto_sort(int numere[2][LOTO_SIZE]){
    int i, ok, tmp;
    do {
        ok = 0;
        for(i = 0; i < LOTO_SIZE-1; i++){
            if(numere[1][i] < numere[1][i+1]){
                
                tmp = numere[1][i];
                numere[1][i] = numere[1][i+1];
                numere[1][i+1] = tmp;
                
                tmp = numere[0][i];
                numere[0][i] = numere[0][i+1];
                numere[0][i+1] = tmp;
                
                ok = 1;
            }
        }
    } while(ok);
}
