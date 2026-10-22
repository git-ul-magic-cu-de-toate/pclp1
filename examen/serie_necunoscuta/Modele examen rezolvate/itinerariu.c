// examen CD 2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dest {
    char nume[101], tara[4];
    struct Dest* urmDest;
} TDestinatie;

typedef struct {
    unsigned int numTrasee; 
    unsigned int *lungimeTrasee;
    TDestinatie **primaDest;
} TItinerariu;

TDestinatie* alocaDestinatie(char* oras, char* tara) {
    TDestinatie* d = (TDestinatie *)calloc(1, sizeof(TDestinatie));
    if (d == NULL)
        return NULL;
    
    d->urmDest = NULL;
    strcpy(d->nume, oras);
    strcpy(d->tara, tara);

    return d;
}

TItinerariu* alocaItinerariu(unsigned int nrTrasee, unsigned int *lungimeTrasee, char **orase, char **tari) {
    TItinerariu *it = (TItinerariu *)calloc(1, sizeof(TItinerariu));
    if (it == NULL)
        return NULL;

    it->numTrasee = nrTrasee;
    
    it->lungimeTrasee = (unsigned int *)calloc(nrTrasee, sizeof(unsigned int));
    if (it->lungimeTrasee == NULL) {
        free(it);
        return NULL;
    }

    for (int i = 0; i < nrTrasee; i++) {
        it->lungimeTrasee[i] = lungimeTrasee[i];
    }

    for (int i = 0; i < nrTrasee; i++) {
        it->primaDest[i] = alocaDestinatie(orase[i], tari[i]);
        if (it->primaDest[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(it->primaDest[j]);
            free(it->primaDest);
            free(it->lungimeTrasee);
            free(it);
            return NULL;
        }
    }

    strcpy(it->primaDest->nume, orase[0]);
    strcpy(it->primaDest->tara, tari[0]);

    it->primaDest = (TDestinatie **)calloc(nrTrasee, sizeof(TDestinatie *));
    if (it->primaDest == NULL) {
        free(it->lungimeTrasee);
        free(it);
        return NULL;
    }

    return it;
}

TItinerariu* citesteDinFisier (FILE *fin) {
    unsigned int nrTrasee;
    fscanf(fin, "%u", &nrTrasee);

    unsigned int lungimeTrasee[nrTrasee];
    for(int i = 0; i < nrTrasee; i++) {
        fscanf(fin, "%u", &lungimeTrasee[i]);
    }

    char **orase = calloc(nrTrasee, sizeof(char *));
    char **tari = calloc(nrTrasee, sizeof(char *));

    // de alocat ca lumea orase si tari

    for(int i = 0; i < nrTrasee; i++) {
        fscanf(fin, "%s %s", orase[i], tari[i]);  // presupun ca orasele au un singur cuvant in nume
    }

    TItinerariu *it = alocaItinerariu(nrTrasee, lungimeTrasee, orase, tari);
    
    return it;
}

char* orasulCuCeleMaiMulteAparitii(TItinerariu *it) {
    char **orase;
    int *v;
    int nr = 0;

    for (int i = 0; i < it->numTrasee; i++) {
        TDestinatie *d = it->primaDest[i];

        while (d != NULL) {
            int j;
            for (j = 0; j < nr; j ++) {
                if (strcmp(orase[j], d->nume) == 0) {
                    v[j]++;
                    break;
                }
            }

            if (j == nr) {
                strcpy(orase[nr], d->nume);
                v[nr] = 1;
                nr++;
            }
        }
    }

    int MAX = 0, poz = -1;

    for (int i = 0; i < nr; i++) {
        if (v[i] > MAX) {
            MAX = v[i];
            poz = i;
        }
    }

    return orase[poz];
}

int cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

char** sorteazaOraseDinTara(TItinerariu *it, char *tara) {
    char **orase;

    //aloca orase 

    int nr = 0;

    for (int i = 0; i < it->numTrasee; i++) {
        TDestinatie* d = it->primaDest[i];

        while (d != NULL) {
            if (strcmp(d->tara, tara) == 0) {
                strcpy(orase[nr], d->nume);
            }

            d = d->urmDest;
        }
    }

    qsort(orase, nr, sizeof(char *), cmp);

    return orase;
}

void dezalocaDestinatie(TDestinatie* d) {
    if (d->urmDest != NULL) {
        dezalocaDestinatie(d->urmDest);
        free(d->urmDest);
    }
}

void dezalocaItinerariu(TItinerariu *it) {
    free(it->lungimeTrasee);

    for(int i = 0; i < it->numTrasee; i++) {
        dezalocaDestinatie(it->primaDest[i]);
    }

    free(it->primaDest);
    free(it);
}

int main() {
    return 0;
}