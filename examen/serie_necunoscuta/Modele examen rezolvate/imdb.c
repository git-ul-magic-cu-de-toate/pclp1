// examen 2023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 99

typedef struct {
    char *nume;
    int nrCrtFilme;
    struct Film *filme[100];
} TActor;

typedef struct Film {
    char *nume;
    int an;
    TActor *distributie[100];
    int nrCrtD;
} TFilm;

typedef struct {
    int nrCrtFilme, nrMaxFilme, nrCrtActori, nrMaxActori;
    TActor *actori, **idxActori;
    TFilm *filme, **idxFilme;
} TIMDB;

TIMDB* alocaIMDB(int nrMaxFilme, int nrMaxActori) {
    TIMDB* imdb = (TIMDB *)calloc(1, sizeof(TIMDB));

    imdb->nrCrtActori = 0;
    imdb->nrCrtFilme = 0;
    imdb->nrMaxActori = nrMaxActori;
    imdb->nrMaxFilme = nrMaxFilme;

    imdb->actori = (TActor *)calloc(nrMaxActori, sizeof(TActor));
    if (imdb->actori == NULL) {
        free(imdb);
        return NULL;
    }

    imdb->filme = (TFilm *)calloc(nrMaxFilme, sizeof(TFilm));
    if (imdb->filme == NULL) {
        free(imdb->actori);
        free(imdb);
        return NULL;
    }

    imdb->idxActori = (TActor **)calloc(nrMaxActori, sizeof(TActor *));
    if (imdb->idxActori == NULL) {
        free(imdb->filme);
        free(imdb->actori);
        free(imdb);
        return NULL;
    }

    imdb->idxFilme = (TFilm **)calloc(nrMaxFilme, sizeof(TFilm *));
    if (imdb->idxFilme == NULL) {
        free(imdb->idxActori);
        free(imdb->filme);
        free(imdb->actori);
        free(imdb);
        return NULL;
    }

    return imdb;
}

TFilm* getFilm(TIMDB* imdb, char *nume) {
    int i = 0;
    for (i = 0; i < imdb->nrCrtFilme; i++) {
        if (strcmp(nume, imdb->filme[i].nume) == 0) {
            return &imdb->filme[i];
        }
    }

    return NULL;  // filmul cu acest nume nu exista
}

TActor* getActor(TIMDB* imdb, char *nume) {
    int i = 0;
    for (i = 0; i < imdb->nrCrtActori; i++) {
        if (strcmp(nume, imdb->actori[i].nume) == 0) {
            return &imdb->actori[i];
        }
    }

    return NULL;
}

TActor* adaugaActorFilm(TIMDB* imdb, char* numeActor, char* numeFilm) {
    TFilm *film = getFilm(imdb, numeFilm);
    TActor *actor = getActor(imdb, numeActor);
    
    if (film->nrCrtD > MAX)
        return NULL;
    film->distributie[film->nrCrtD] = actor;
    film->nrCrtD++;

    if(actor->nrCrtFilme > MAX)
        return NULL;
    actor->filme[actor->nrCrtFilme] = film;
    actor->nrCrtFilme++;

    return actor;
}

int cmp(const void *a, const void *b) {
    TFilm *film1 = *(TFilm **)a;
    TFilm *film2 = *(TFilm **)b;

    return strcmp(film1->nume, film2->nume);
}

TFilm* adaugaFilm(TIMDB* imdb, char *nume) {
    if (imdb->nrCrtFilme > imdb->nrMaxFilme)
        return NULL;
    
    imdb->filme[imdb->nrCrtFilme].nume = (char *)calloc(strlen(nume) + 1, sizeof(char));
    if (imdb->filme[imdb->nrCrtFilme].nume == NULL) 
        return NULL;

    // distributia este vector de pointeri, dar pointerii "pointeaza" catre elemente din imdb considerate deja alocate
    // asa ca nu trebuie sa o aloc separat
    
    imdb->filme[imdb->nrCrtFilme].an = 2024;  // fiind film nou presupun ca a aparut anul acesta
    imdb->filme[imdb->nrCrtFilme].nrCrtD = 0;
    imdb->idxFilme[imdb->nrCrtFilme] = imdb->filme[imdb->nrCrtFilme];
    imdb->nrCrtFilme++;

    qsort(imdb->idxFilme, imdb->nrCrtFilme, sizeof(TFilm *), cmp);

    return &imdb->filme[imdb->nrCrtFilme - 1];
}

void free_all(TIMDB *imdb) {
    for (int i = 0; i < imdb->nrCrtActori; i++)
        free(imdb->actori[i].nume);  // presupun ca, exact ca la filme, numele actorilor este alocat dinamic
    free(imdb->actori);

    for (int i = 0; i < imdb->nrCrtFilme; i++)
        free(imdb->filme[i].nume);
    free(imdb->filme);

    free(imdb);
}

int main() {
    return 0;
}