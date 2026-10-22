// Copyright 2024 Darius Neatu (neatudarius@gmail.com)
#include <stdio.h>

// Definim un macro log() care sa afiseze numele fisierului, numele functiei si numarul liniei,
// inainte de a afisa mesajul de debug.
// Aplicam toate bunele practici de programare:
// - folosim un prefix pentru a evita coliziunile de nume;
// - folosim un format de afisare care sa contina toate informatiile necesare pentru a identifica locul unde s-a apelat log():
//      - data si ora compilarii;
//      - numele fisierului;
//      - numele functiei;
//      - numarul liniei;
// - folosim ##__VA_ARGS__ pentru a elimina virgula de dupa fmt, daca nu sunt argumente.
// - implementam log() pe mai multe linii pentru
//      - a fi mai usor de citit;
//      - a evita problemele legate de scopul variabilelor si de evaluarea expresiilor.
// - vom verifica DEBUG pentru a afisa sau nu mesajele de debug: daca DEBUG este definit, atunci afisam mesajele de debug,
//   altfel nu afisam nimic (adica eliminam apelurile log() din cod).
#ifdef DEBUG
#define log(fmt, ...)                                                                                          \
    do {                                                                                                             \
        printf("[%s][%s:%s():%d] - " fmt "\n", __DATE__ "-" __TIME__,  __FILE__, __func__, __LINE__, ##__VA_ARGS__); \
    } while (0)
#else
// pastreaza log() pentru a putea fi apelat in cod, dar ne asignam sa nu facem nimic daca DEBUG nu este definit.
#define log(fmt, ...) do {} while (0)
#endif

#define DEBUG

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

// TODO 1: Compilati si rulati codul!
// $ gcc 15-fancy_debug.c -o 15-fancy_debug && ./15-fancy_debug
// ...
// Ce observati?
// Hint: gcc -E 15-fancy_debug.c | tail -15
//
// TODO 2: Definiti macro-ul DEBUG (recompilati) si rulati codul!
// $ gcc -DDEBUG 15-fancy_debug.c -o 15-fancy_debug && ./15-fancy_debug
// [Dec 19 2024-19:41:19][15-fancy_debug.c:main():36] - Hello from main. x = 2
// [Dec 19 2024-19:41:19][15-fancy_debug.c:my_func():31] - Hello from my_func
// [Dec 19 2024-19:41:19][15-fancy_debug.c:main():40] - Hello from main. x = 2 y = z
// Ce observati?
// Hint: gcc -E -DDEBUG 15-fancy_debug.c | tail -15
//
// TODO 3: Liniile afisate anterior au antet variabil, cum putem sa-l facem constant?
// Hint: Presupunem o dimensiune maxima fixa pentru fiecare camp.
// Hint: Folosim snprintf() pentru a scrie intr-un buffer.
