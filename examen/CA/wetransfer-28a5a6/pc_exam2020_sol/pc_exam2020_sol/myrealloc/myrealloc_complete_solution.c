// Copyright 2020 Echipa de Programarea Calculatoarelor, Seria CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

// functia primeste ca parametru un buffer alocat cu mymalloc
int get_size(void *p) {
    // p unde incepe bufferul

    int *pint = (int *) p;
    --pint;
    // p - sizeof(int): contine lungimea sirului de octeti


    return *pint; // returneaza size
}

// functia returneaza un bloc de date de dimensiune size
// ea va aloca p cu dimensiune size + 4
// si va returna p + 4 (adica cat ii trebuie userului)
// primul int va fi folosit pentru a stoca dimensiunea blocului
//
// exemplu size = 3, se vor aloca 7 bytes
//  03 00 00 00 xx yy zz
//      03 00 00 00 = size
//      xx yy zz sirul de octeti cerut
void* mymalloc(int size) {
    // vom aloca cu sizeof(int) bytes mai multi
    // intrucat vom stoca un int suplimentar ("ascuns")

    int *p = (int *) malloc((size + sizeof(int)) * sizeof(char));
    if (!p) {
        return NULL;
    }

    *p = size; // stocam la inceputul secventei dimensiunea
    
    ++p; // mutam pointerul catre zona efectiva ceruta de user

    return p; // userului ii returnam un bloc de dimensiune size
}

// elibereaza un bloc de date
// p este pointer catre datele userului, insa blocul contine un int inainte

void myfree(void *p) {
    free(p - sizeof(int));
}

// aceasta functie realoca un buffer alocat in prealabil cu mymalloc
void* myrealloc(void *ptr, int new_size) {
    // alocam un alt buffer de dimensiune ceruta
    int *new_ptr = (int *) mymalloc(new_size);
    if (!new_ptr) {
        return NULL;
    }

    // copiam octetii din ptr in new_ptr
    int *p = (int *) ptr;
    int old_size = *p;
    memcpy(new_ptr, ptr, MIN(old_size, new_size));

    // eliberam vechiul bloc de memorie
    myfree(ptr); 

    return  new_ptr;
}

int main() {
    // alocam un vector
    int n = 3;
    int *v = (int *) mymalloc(n * sizeof(int));
    if (!v) {
        fprintf(stderr, "mymalloc failed\n");
        return -1;
    }
    printf("v indica catre o zona cu %d bytes\n", get_size(v));

    // populam vectorul
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }

    // dublam dimensiunea vectorului
    n *= 2;
    v = (int *) myrealloc(v, n * sizeof(int));
    if (!v) {
        fprintf(stderr, "myrealloc failed");
        return -1;
    }
    printf("v indica catre o zona cu %d bytes\n", get_size(v));

    // injumatatim dimensiunea vectorului
    n /= 2;
    v = (int *) myrealloc(v, n * sizeof(int));
    if (!v) {
        fprintf(stderr, "myrealloc failed");
        return -1;
    }
    printf("v indica catre o zona cu %d bytes\n", get_size(v));

    // afisam elementele sa vedem ca primele 3 valori s-au pastrat
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }

    myfree(v);

    return 0;
}