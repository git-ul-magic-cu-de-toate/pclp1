// Copyright 2024 Darius Neatu (neatudarius@gmail.com)
#include <stdio.h>

// Exista un macro predefinit __FILE__ care contine numele fisierului.
// Exista un macro predefinit __func__ care contine numele functiei.
// Exista un macro predefinit __LINE__ care contine numarul liniei.
// Exista un macro predefinit __DATE__ care contine data compilarii.
// Exista un macro predefinit __TIME__ care contine ora compilarii.
//      Se pot concatena folosind ##, de exemplu __DATE__ ## __TIME__.
// https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html

void my_func(void)
{
    printf("%s:%s():%d - Hello from my_func\n", __FILE__, __func__, __LINE__);
}

int main(void)
{
    printf("%s:%s():%d - Hello from main\n", __FILE__, __func__, __LINE__);

    my_func();

    return 0;
}

// TODO 1: Compilati codul si observati ce se intampla!
// $ gcc -E 10-default_macros.c | tail -15
//
// # 9 "10-default_macros.c"
// void my_func(void)
// {
//     printf("%s:%s():%d - Hello from my_func\n", "10-default_macros.c", __func__, 11);
// }
//
// int main(void)
// {
//     printf("%s:%s():%d - Hello from main\n", "10-default_macros.c", __func__, 16);
//
//     my_func();
//
//     return 0;
// }
//
// TODO 2: Compilati si rulati codul.
// $ gcc 10-default_macros.c -o 10-default_macros
// $ ./10-default_macros
// 10-default_macros.c:main():16 - Hello from main
// 10-default_macros.c:my_func():11 - Hello from my_func
//