/*
 set.c
 Created by Florin Pop on 17.11.2012.
 Copyright (c) 2012 Florin Pop. All rights reserved.
 */

#include <stdio.h>

#define SET_SIZE 10

/* Definim tipul SET ca fiind un vector de SET_SIZE octeti. */
typedef unsigned char SET[SET_SIZE];

/* In multime vor putea fi memorate SET_SIZE * 8 numere */
const unsigned int SET_LENGTH = SET_SIZE * 8;

/* Verifica daca un numar n apartine multimii S */
int apartine(SET S, unsigned int n) {
    static unsigned int MASK = 0x80; //1000 0000
    /* Daca n poate fi marcat si daca bit-ul al n-lea este 1 */
    return (n < SET_LENGTH) && ( S[n/8] & (MASK >> (n%8)) );
}

/* Adauga un element n in multimea S */
void adauga(SET S, unsigned int n) {
    static unsigned int MASK = 0x80; //1000 0000
    S[n/8] |= (MASK >> (n%8));
}

/* Sterge un element n din multimea S */
void sterge(SET S, unsigned int n) {
    static unsigned int MASK = 0x80; //1000 0000
    S[n/8] &= ~(MASK >> (n%8));
}

/* Sterge toate elementele din multimea S */
void sterge_tot(SET S) {
    int i;
    for (i = 0; i < SET_SIZE; S[i++]=0);
}

/* Verifica daca multimea este vida */
int e_vida(SET S) {
    int i;
    for (i = 0; i < SET_SIZE; i++) {
        if(S[i] != 0) { return 0; }
    }
    return 1;
}

/* Determina cardinalul lui S */
int cardinal(SET S) {
    int cs = 0, i;
    for (i = 0; i <= SET_LENGTH; i++) {
        if(apartine(S, i)) { cs++; }
    }
    return cs;
}

void tipar(SET S, char msg[]) {
    int cs = cardinal(S), i;
    
    printf("\n%s {", msg);
    if (cs==0) { printf("}"); return; }
    
    for (i = 0; i <= SET_LENGTH; i++) {
        if(apartine(S, i)) {
            printf("%d%c", i, (--cs)==0 ? '}' : ',');
        }
    }
}

int main() {
    SET  A,  B,  C;
    int na, nb;
    int i, nr_crt;
    
    /* Citirea multimilor A si B */
    
    scanf("%d", &na);
    sterge_tot(A);
    for(i = 0; i < na; i++) {
        scanf("%d", &nr_crt); adauga(A, nr_crt);
    }
    
    scanf("%d", &nb);
    sterge_tot(B);
    for(i = 0; i < nb; i++) {
        scanf("%d", &nr_crt); adauga(B, nr_crt);
    }
    
    /* Reuniune */
    for (i = 0; i < SET_SIZE; i++) {
        C[i] = A[i]|B[i];
    }
    tipar(C, "A + B (reuniune): ");
    
    /* Intersectie */
    for (i = 0; i < SET_SIZE; i++) {
        C[i] = A[i]&B[i];
    }
    tipar(C, "A / B (intersectie): ");
    
    /* Diferenta A - B */
    for (i = 0; i < SET_SIZE; i++) {
        C[i] = (A[i]^B[i])&(~B[i]);
    }
    tipar(C, "A - B: ");
    
    /* Diferenta B - A */
    for (i = 0; i < SET_SIZE; i++) {
        C[i] = (A[i]^B[i])&(~A[i]);
    }
    tipar(C, "B - A: ");
    
    printf("\n");
    return 0;
}
