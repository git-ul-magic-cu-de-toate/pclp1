#include <stdio.h>   // scanf/printf
#include <stdlib.h>  // malloc/realloc/free

#define INC 10

int main() {
    // capacitate = numar de elemente alocate (in memorie)
    int capacity = 2;

    // dimensiune = numar de elemente efectiv ocupate (folosite)
    // v[size] indica mereu catre prima pozitie libera (care trebuie folosita)
    int size = 0;

    // vectorul de numere cu dimensiune initial aleasa
    int *v = malloc(capacity * sizeof(int));

    int x;  // elementul curent
    scanf("%d", &x);

    while (x != -1) {
        // daca vectorul are toate elementele ocupate
        if (size == capacity) {
            // il realoc
            capacity *= 2;  // sau capacity++; // sau capacity+=INC;
            int *tmp = realloc(v, capacity * sizeof(int));
            if(tmp==NULL){
                free(v);
                fprintf(stderr, "Can not reallocate memory.\n");
                return -1;
            }
            v = tmp;
        }

        // aici sigur v[size] exista
        v[size++] = x;

        scanf("%d", &x);
    }

    // optional putem sa consideram si cazul in care nu am folosit
    // toate elementele alocate la ultima realocare
    // capacity = size;  // size <= capacity
    // v = realloc(v, capacity * sizeof(int));

    printf("size = %d;  capacity = %d\n", size, capacity);
    printf("v : ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);

    return 0;
}
