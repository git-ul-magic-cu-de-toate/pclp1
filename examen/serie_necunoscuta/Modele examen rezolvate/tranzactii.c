// examen 2023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nume, cnp[14], conturi[50][25];
    int nrCrtConturi;
} TPers;

typedef struct {
    char src[25], dest[25];
    int timestamp;
    int day_in_year;
    double suma;
} TTranzactie;

typedef struct {
    int nrCrtTranzactii, nrMaxTranzactii, nrMaxPers, nrCrtPers;
    TPers *pers;
    TTranzactie *tranz;
    TTranzactie **tranzIdx;
    TTranzactie **idxData[366];
} TColectie;

TColectie* alocaColectie(int nrMaxTranzactii, int nrMaxPers) {
    TColectie *c = (TColectie *)calloc(1, sizeof(TColectie));
    if (c == NULL) 
        return NULL;
    
    c->pers = (TPers *)calloc(nrMaxPers, sizeof(TPers));
    if (c->pers == NULL) {
        free(c);
        return NULL;
    }

    c->tranz = (TTranzactie *)calloc(nrMaxTranzactii, sizeof(TTranzactie));
    if (c->tranz == NULL) {
        free(c->pers);
        free(c);
        return NULL;
    }

    c->tranzIdx = (TTranzactie **)calloc(nrMaxTranzactii, sizeof(TTranzactie *));
    if (c->tranzIdx == NULL) {
        free(c->pers);
        free(c->tranz);
        free(c);
        return NULL;
    }

    for(int i = 0; i < 365; i++) {
        c->idxData[i] = (TTranzactie **)calloc(nrMaxTranzactii, sizeof(TTranzactie *));
        if (c->idxData[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(c->idxData[j]);
            free(c->pers);
            free(c->tranz);
            free(c);
            return NULL;
        } 
    }

    return c;
}

int cmp(const void *a, const void *b) {
    TTranzactie *t1 = *(TTranzactie **)a;
    TTranzactie *t2 = *(TTranzactie **)b;

    return (int)t1->timestamp - (int)t2->timestamp;
}

TTranzactie** tranzactiiSortate(TColectie *c) {
    for (int i = 0; i < c->nrCrtTranzactii; i++) {
        c->tranzIdx[i] = &c->tranz[i];
    }

    qsort(c->tranzIdx, c->nrCrtTranzactii, sizeof(TTranzactie *), cmp);

    return c->tranzIdx;
}

TTranzactie*** primaTranzactieDinZi(TColectie *c) {
    for (int i = 0; i < 366; i++) {
        c->idxData[i] = NULL;
    }

    for (int i = 0; i < c->nrCrtTranzactii - 1; i++) {
        c->idxData[c->tranzIdx[i]->day_in_year] = &c->tranzIdx[i];

        while (c->tranzIdx[i]->day_in_year == c->tranzIdx[i + 1]->day_in_year)
            i++;
    }

    return c->idxData;
}

int conturiLaMaiMulteBanci(TColectie *c) {
    int nr = 0;

    for (int i = 0; i < c->nrCrtPers; i++) {
        for (int j = 0; j < c->pers[i].nrCrtConturi - 1; j++) {
            if (strncmp(c->pers[i].conturi[j] + 4, c->pers[i].conturi[j + 1] + 4, 4) != 0) {
                nr++;
                break;
            }
        }
    }

    return nr;
}

int apartineCont(TPers *p, char *iban) {
    for (int i = 0; i < p->nrCrtConturi; i++) {
        if (strcmp(iban, p->conturi[i]) == 0)
            return 0;
    }

    return 1;
}

double calcSuma(TColectie *c, char *cnp, int zi) {
    if (c->idxData[zi] == NULL)
        return 0;
    
    int i, j;
    for (i = 0; i < c->nrCrtTranzactii; i++) {
        if (c->tranzIdx[i] == *c->idxData[zi])
            break;
    }

    for (j = 0; j < c->nrCrtPers; j++) {
        if (strcmp(c->pers[j].cnp, cnp) == 0)
            break;
    }

    double sum = 0;

    while (c->tranzIdx[i]->day_in_year == zi) {
        if (apartineCont(&c->pers[j], c->tranzIdx[i]->dest) == 1)
            sum += c->tranzIdx[i]->suma;
        
        i++;
    }

    return sum;
}

int main(){
    return 0;
}