// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

// Notiuni introductive despre preprocesor in C:
// 1. Preprocesorul este un program care ruleaza inainte de compilare.
// Detalii despre etapele de compilare:
//      1. Preprocesare
//      2. Compilare
//      3. Asamblare
//      4. Linkare
// 2. Preprocesorul are ca scop sa modifice codul sursa inainte de compilare.
// 3. Preprocesorul este activat de catre compilator, prin intermediul unor comenzi scrise in codul sursa.
// 4. Preprocesorul are un set de comenzi predefinite, numite directive de preprocesare.

#include <stdio.h>

int main(void)
{
    return 2024; // 2024 este un an important!
}

// Ca să printăm cum arată codul nostru după preprocesare, putem folosi comanda:
// $ gcc -E 00-etape_compilare.c -o 00-etape_compilare.i
// $ cat 00-etape_compilare.i
// sau direct
// $ gcc -E 00-etape_compilare.c
//
// TODO 1: Rulati comando de mai sus pe acest fisier si observati ce se intampla!
// # 0 "00-etape_compilare.c"
// # 0 "<built-in>"
// # 0 "<command-line>"
// # 1 "/usr/include/stdc-predef.h" 1 3 4
// # 0 "<command-line>" 2
// # 1 "00-etape_compilare.c"
// # 14 "00-etape_compilare.c"
// int main(void)
// {
//     return 2024;
// }
// $ gcc -E 00-etape_compilare.c | wc -l
// 11
// TODO 2: Adaugati un comentariu in fisier si rulati din nou comanda de preprocesare. Ce observati?
// $ gcc -E 00-etape_compilare.c | wc -l
// ???
//
// TODO 3: Adaugati #include <stdio.h>, apelati printf si rulati din nou comanda de preprocesare. Ce observati?
// $ gcc -E 00-etape_compilare.c | wc -l
// ???
//
