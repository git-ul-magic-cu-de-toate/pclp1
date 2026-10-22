// Copyright 2024 Darius Neatu (neatudarius@gmail.com)
#include <stdio.h>

// Definim un macro log() care sa afiseze numele fisierului, numele functiei si numarul liniei,
// inainte de a afisa mesajul de debug.
#define log(fmt, ...) printf("[%s][%s:%s():%d] - " fmt "\n", __DATE__ "-" __TIME__,  __FILE__, __func__, __LINE__, ##__VA_ARGS__)
// Explicatii:
// - fmt este un string care contine formatul mesajului de afisat.
//      Acesta se concateneaza cu prefixul "[__DATE__-__TIME__][__FILE__:__func__():__LINE__] - ".
//      Rezulta un format de afisare de forma: "[__DATE__-__TIME__][__FILE__:__func__():__LINE__] - fmt".
// Incepe lista de argumente variabile ale functiei printf:
// - __DATE__ si __TIME__ sunt macro-uri predefinite care contin data si ora compilarii.
//      Sunt concatenate folosind la preprocesare cu __DATE__ "-" __TIME__.
// - __FILE__ este un macro predefinit care contine numele fisierului.
// - __func__ este un macro predefinit care contine numele functiei.
// - __LINE__ este un macro predefinit care contine numarul liniei.
// - ##__VA_ARGS__ -> daca nu sunt argumente, atunci se elimina virgula de dupa fmt.

void my_func(void)
{
    log("Hello from my_func");
}

int main(void)
{
    log("Hello from main. x = %d", 2);
    my_func();


    log("Hello from main. x = %d y = %c", 2, 'z');

    return 0;
}

// TODO 1: Compilati codul si observati ce se intampla!
// $ gcc -E 11-debug_macro.c | tail -15
//
// # 13 "11-debug_macro.c"
// void my_func(void)
// {
//     printf("%s:%s():%d - " "Hello from my_func\n", "11-debug_macro.c", __func__, 15);
// }
//
// int main(void)
// {
//     printf("%s:%s():%d - " "Hello from main. date = %s", "11-debug_macro.c", __func__, 20, "Dec 19 2024");
//
//     my_func();
//
//     return 0;
// }
// Unde a disparut log()?
// Unde a disparut __DATE__?
//      __DATE__ este un macro predefinit care contine data compilarii. https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html
//
//
// TODO 2: Compilati si rulati codul. Ce observati?
// $ gcc 11-debug_macro.c -o 11-debug_macro
// $ ./11-debug_macro
// $ ./11-debug_macro
// [Dec 19 2024-19:34:46][11-debug_macro.c:main():27] - Hello from main. x = 2
// [Dec 19 2024-19:34:46][11-debug_macro.c:my_func():22] - Hello from my_func
// [Dec 19 2024-19:34:46][11-debug_macro.c:main():31] - Hello from main. x = 2 y = z
//
// TODO 3: Asteptati cateva minute si rulati din nou codul. Ce observati?
// TODO 4: Recompilati codul fara a modifica nimic si rulati din nou codul. Ce observati?

