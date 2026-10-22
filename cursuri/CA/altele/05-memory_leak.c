// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *ptr = (char *)malloc(1);

    if (ptr == NULL) {
        // Verifică dacă alocarea a eșuat
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    free(ptr);

    return 0;
}

// TODO: Care este buba? :D
// Hint: $ valgrind ./05-memory_leak --leak-check=full
// https://ocw.cs.pub.ro/courses/programare/tutoriale/debugging
