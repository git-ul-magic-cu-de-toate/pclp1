// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

// Cele 3 variante de main din C:
// int main(void)                               // varianta 1: fără argumente
int main(int argc, char **argv)              // varianta 2: cu argumente CLI
// int main(int argc, char **argv, char **envp)    // varianta 3: cu argumente CLI și cu variabile de mediu (environ)
{
    printf("Merry Christmas!\n");
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    // while (*envp != NULL) { // envp[0] != NULL
        // printf("*envp = %s\n", *envp);
        // ++envp;
    // }
    return 0;
}

// TODO 0: Programul curent se poate compila și rula astfel:
// $ gcc ... 00-C_print_args_cli.c -o 00-C_print_args_cli
// $ ./00-C_print_args_cli
//
// TODO 1: Dorim să transmitem parametri în linie de comandă acestui program C:
// $ gcc ... 00-C_print_args_cli.c -o 00-C_print_args_cli
// $ ./00-C_print_args_cli Merry Christmas! Ho Ho Ho!
// Received 5 arguments!


// ./00-C_print_args_cli ana are "mere si pere"
// Merry Christmas!
// argc = 4
// argv[0] = ./00-C_print_args_cli
// argv[1] = ana
// argv[2] = are
// argv[3] = mere si pere

// Concluzie 1: argv[0] este numele programului, iar argv[1], argv[2], ... sunt argumentele CLI.
// Concluzie 2: Mereu preferăm varianta cea mai simplă de a scrie codul, adică în ordine alegem
// varianta 1, apoi varianta 2, apoi varianta 3.
//
// varianta 1:
// Functia void nu primeste argumente de la linia de comanda.
// int main(void)
// {
//     // cod uzual ...
//     return 0;
// }
//
// varianta 2:
// Functia main primeste argumentele de la linia de comanda: argc si argv.
// - argc: numarul de argumente CLI
// - argv: un array de stringuri, unde argv[0] este numele programului, iar argv[1], argv[2], ... sunt argumentele CLI.
// int main(int argc, char **argv)
// {
//     // cod care prelucreaza argumentele CLI (argc, argv)
//     // de exemplu
//              - afișează argumentele CLI
//              - validează argumentele CLI (aici se poate face return de cod de eroare - non-zero)
//              - prelucrează argumentele CLI (string to int, ...)
//
//     // cod uzual ...
//     return 0;
// }
//
// varianta 3:
// Functia main primeste argumentele de la linia de comanda: argc, argv și environ.
// - argc: numarul de argumente CLI
// - argv: un array de stringuri, unde argv[0] este numele programului, iar argv[1], argv[2], ... sunt argumentele CLI.
// - environ: un array de stringuri, unde environ[0], environ[1], ... sunt variabilele de mediu. Se termină cu NULL.
// int main(int argc, char **argv, char **environ)
// {
//     // cod care prelucreaza argumentele CLI (argc, argv)
//     // de exemplu
//              - afișează argumentele CLI
//              - validează argumentele CLI (aici se poate face return de cod de eroare - non-zero)
//              - prelucrează argumentele CLI (string to int, ...)
//
//    // cod care prelucreaza variabilele de mediu (environ)
//    // de exemplu
//              - afișează variabilele de mediu
//              - validează variabilele de mediu
//              - prelucrează variabilele de mediu
//
//     // cod uzual ...
//     return 0;
// }
