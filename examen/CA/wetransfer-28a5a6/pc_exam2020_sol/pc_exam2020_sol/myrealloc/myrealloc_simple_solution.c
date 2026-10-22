#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

// presupunem ca exista o functie
// care returneaza lungimea unui zone de memorie alocata cu malloc
int get_size(void *p);

void* myrealloc(void *ptr, int new_size) {
    // aloc un alt buffer de dimensiune new_size
    void *new_ptr = malloc(new_size * sizeof(char));
    if (!new_ptr) {
        return NULL;
    }

    // determin lungimea vechiului buffer
    int old_size = get_size(ptr);

    // copiez bytes existenti
    memcpy(new_ptr, ptr, MIN(old_size, new_size));

    // acest buffer nu va mai fi folosit
    free(ptr);

    return new_ptr;
}

// apelare: ptr = realloc(ptr, new_size);