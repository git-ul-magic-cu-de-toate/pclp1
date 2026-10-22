// Copyright 2017 PC Team

#include <stdio.h>   // scanf/printf
#include <stdlib.h>  // malloc/realloc/free

typedef struct {
    // capacitate = numar de elemente alocate (in memorie)
    int capacity;

    // dimensiune = numar de elemente efectiv ocupate (folosite)
    // v[size] indica mereu catre prima pozitie libera (care trebuie folosita)
    int size;

    // vectorul de numere cu dimensiune initial aleasa
    int *v;
} resizablearray_t;

int main() {
    resizablearray_t ra;

    // capacitate = numar de elemente alocate (in memorie)
    ra.capacity = 2;

    // dimensiune = numar de elemente efectiv ocupate (folosite)
    // v[size] indica mereu catre prima pozitie libera (care trebuie folosita)
    ra.size = 0;

    // vectorul de numere cu dimensiune initial aleasa
    ra.v = malloc(ra.capacity * sizeof(int));

    int x;  // elementul curent
    scanf("%d", &x);

    while (x != -1) {
        // daca vectorul are toate elementele ocupate
        if (ra.size == ra.capacity) {
            // il realoc
            ra.capacity *= 2;  // sau capacity++;
            ra.v = realloc(ra.v, ra.capacity * sizeof(int));
        }

        // aici sigur v[size] exista
        ra.v[ra.size++] = x;

        scanf("%d", &x);
    }

    // optional putem sa consideram si cazul in care nu am folosit
    // toate elementele alocate la ultima realocare
    // capacity = size;  // size <= capacity
    // v = realloc(v, capacity * sizeof(int));

    printf("size = %d;  capacity = %d\n", ra.size, ra.capacity);
    printf("v : ");
    for (int i = 0; i < ra.size; ++i) {
        printf("%d ", ra.v[i]);
    }
    printf("\n");

    free(ra.v);

    return 0;
}
