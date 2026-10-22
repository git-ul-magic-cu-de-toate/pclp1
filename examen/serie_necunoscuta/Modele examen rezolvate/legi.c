// examen 08.02.2017 CB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Art {
    char *continut;
    unsigned int id;
    int abrogat;
    unsigned int nrArtAbrog;
    struct Art *articoleAbrogate[10];
} TArticol;

typedef struct {
    char id[11];
    TArticol *articole;
    int nrMaxArt, nrCrtArt;
} TLege;

typedef struct {
    int nrMaxLegi, nrCrtLegi;
    TLege *legi;
} TColectieLegi;

TColectieLegi* alocaColectieLegi(int nrMaxLegi) {
    TColectieLegi *c = (TColectieLegi *)calloc(1, sizeof(TColectieLegi));
    if (c == NULL)
        return NULL;

    c->legi = (TLege *)calloc(nrMaxLegi, sizeof(TLege));
    if (c->legi == NULL) {
        free(c);
        return NULL;
    }

    c->nrCrtLegi = 0;
    c->nrMaxLegi = nrMaxLegi;

    return c;
}

int cmp_art(const void *a, const void *b) {
    TArticol *art1 = (TArticol *)a;
    TArticol *art2 = (TArticol *)b;

    return (int)(art1->id - art2->id);
}

int cmp_legi(const void *a, const void *b) {
    TLege *l1 = (TLege *)a;
    TLege *l2 = (TLege *)b;

    return strcmp(l1->id, l2->id);
}

TColectieLegi* sortare(TColectieLegi* c) {
    qsort(c->legi, c->nrCrtLegi, sizeof(TLege), cmp_legi);

    for (int i = 0; i < c->nrCrtLegi; i++) {
        qsort(c->legi[i].articole, c->legi[i].nrCrtArt, sizeof(TArticol), cmp_art);
    }

    return c;
}

TArticol* cautaArt (TColectieLegi *c, char *idLege, unsigned int idArt) {
    for (int i = 0; i < c->nrCrtLegi; i++) {
        if (strcmp(idLege, c->legi[i].id) == 0) {
            for (int j = 0; j < c->legi[i].nrCrtArt; j++) {
                if (idArt == c->legi[i].articole[j].id) {
                    return &c->legi[i].articole[j];
                }
            }
        }
    }

    return NULL;  // articolul nu exista
}

TLege* adaugaLege(TColectieLegi*  c, FILE *f) {
    if (c->nrCrtLegi == c->nrMaxLegi)
        return NULL;  // sau se realoca, cerinta nu specifica

    fscanf(f, "%d", &c->legi[c->nrCrtLegi].nrCrtArt);

    // nu mi s-a dat numarul de articole maxime
    // aloc vectorul de articole cu nrCrtArt
    // cand se adauga un articol nou, se realoca

    c->legi[c->nrCrtLegi].articole = (TArticol *)calloc(c->legi[c->nrCrtLegi].nrCrtArt, sizeof(TArticol));
    if (c->legi[c->nrCrtLegi].articole == NULL)
        return NULL;

    fscanf(f, "%s", c->legi[c->nrCrtLegi].id);

    for (int i = 0; i < c->legi[c->nrCrtLegi].nrCrtArt; i++) {
        fscanf(f, "%u", &c->legi[c->nrCrtLegi].articole[i].id);

        c->legi[c->nrCrtLegi].articole[i].continut = (char *)calloc(500, sizeof(char));
        if (c->legi[c->nrCrtLegi].articole[i].continut == NULL) {
            free(c->legi[c->nrCrtLegi].articole);
            return NULL;
        }

        fgets(c->legi[c->nrCrtLegi].articole[i].continut, 500, f);
        fscanf(f, "%u", &c->legi[c->nrCrtLegi].articole[i].nrArtAbrog);
        c->legi[c->nrCrtLegi].articole[i].abrogat = 0;

        for (int j = 0; j < c->legi[c->nrCrtLegi].articole[i].nrArtAbrog; j++) {
            unsigned int idA;
            char idL[11];
            
            fscanf(f, "%u %s", &idA, idL);

            c->legi[c->nrCrtLegi].articole[i].articoleAbrogate[j] = cautaArt(c, idL, idA);
            c->legi[c->nrCrtLegi].articole[i].articoleAbrogate[j]->abrogat = 1;
        }
    }

    c->nrCrtLegi++;
    return &c->legi[c->nrCrtLegi - 1];
}

void seteazaAbrogat(TLege *l) {
    for (int i = 0; i < l->nrCrtArt; i++) {
        for (int j = 0; j < l->articole[i].nrArtAbrog; j++) {
            l->articole[i].articoleAbrogate[j]->abrogat = 1;
        }
    }
}

int main() {
    return 0;
}