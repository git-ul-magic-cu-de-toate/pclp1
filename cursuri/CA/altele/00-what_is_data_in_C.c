// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

// Ce este un pointer la funcție? Ca să ajungem acolo, ar trebui să ne reamintim că
// folosim pointeri pentru a manipula date. În C, funcțiile sunt date. Deci, putem
// folosi pointeri pentru a manipula funcții. Un pointer la funcție este un pointer
// care arată către o funcție. De exemplu, putem avea un pointer la funcție care
// arată către o funcție care primește un întreg și întoarce un întreg. În general,
// un pointer la funcție arată către o funcție care are un anumit tip de argumente
// și întoarce un anumit tip de rezultat.

#include <stdio.h>

// ptr_type este un pointer la o functie CARE
// primeste un int si returneaza void
typedef void (*ptr_type)(int x);

void my_func(int x)
{
    printf("x = %d\n", x);
}

int main(void)
{
    my_func(3); // x = 3

    printf("my_func = %p\n", my_func); // my_func = 0x4005b6
    printf("&my_func = %p\n", &my_func); // &my_func = 0x4005b6

    // Syntaxa recomandata de declarare a unui pointer la functie.
    ptr_type ptr = my_func;
    printf("ptr = %p\n", ptr); // ptr = 0x4005b6

    // Se poate si syntaxa directa, dar ptr_type este mai clar.
    // void (*ptr2)(int x) = my_func;
    // printf("ptr2 = %p\n", ptr2); // ptr2 = 0x4005b6

    return 0;
}

// $ ./00-what_is_data_in_C
// x = 3
// my_func = 0xbcfb7fe80758
// &my_func = 0xbcfb7fe80758
// ptr = 0xbcfb7fe80758
