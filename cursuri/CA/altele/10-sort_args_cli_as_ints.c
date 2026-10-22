// Copyright 2024 Darius Neatu (neatudarius@gmail.com)
// TODO: Să se scrie un program C care să primească în linie de comandă un șir de
// numere întregi. Programul va sorta șirul crescător, apoi îl va afișa la STDOUT.
// * Programul trebuie să primească un șir cu minim 3 argumente. În caz contrar se va
// opri cu codul -1 și mesajul "Wrong number of arguments. Expected at least 3, got %d.".
// * Programul trebuie să primească o listă de numere întregi. În caz contrar se va opri
// cu codul -2 și va afișa un mesaj corespunzător pentru poziția i din lista de argumente
// unde s-a încălcat regula.
#include <stdio.h>

// Funcție care verifică dacă un șir de caractere reprezintă un număr întreg.
// Returnează 1 dacă șirul reprezintă un număr întreg și 0 altfel.
// Cazurile posibile:
// - Număr pozitiv: "10" -> 1
// - Număr negativ: "-10" -> 1
// - Număr pozitiv cu +: "+10" -> 1
// - Număr pozitiv cu + în față: "+01" -> 1
// - Număr negativ cu 0 în față: "-01" -> 0
// - Orice altceva: "are" -> 0
int is_integer(char *s)
{
    // Dacă șirul este gol, nu este un număr întreg.
    if (!s) {
        return 0;
    }

    // Primul caracter poate fi + sau -.
    if (*s == '-' || *s == '+') {
        ++s;
    }

    // Orice caracter din șirul rămas trebuie să fie cifră.
    while (*s) {
        if (*s < '0' || *s > '9') {
            return 0;
        }
        ++s;
    }

    // Dacă am ajuns aici, șirul este un număr întreg.
    return 1;
}

// TODO: Varianta scurtă de a scrie funcția is_integer, cu ajutorul funcției standard strtol.

int main(int argc, char **argv)
{
    // Pas 1: Validăm CLI arguments.
    if (argc < 4) {
        fprintf(stderr, "Wrong number of arguments. Expected at least 3, got %d.\n", argc - 1);
        return -1;
    }
    for (int i = 1; i < argc; ++i) {
        if (!is_integer(argv[i])) {
            fprintf(stderr, "argv[%d] = %s expected to be an integer value!\n", i, argv[i]);
            return -2;
        }
    }
    // Alocăm un array de numere întregi.
    int n = argc - 1;
    int *v = (int *) malloc(n * sizeof(int));
    if (!v) {
        fprintf(stderr, "malloc failed.\n");
        return -3;
    }
    for (int i = 0; i < n; ++i) {
        v[i] = atoi(argv[i + 1]);
    }

    // Pas 2: Sortare manuală:
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (v[i] > v[j]) {
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
    // TODO: Acest cod des sortare este complet nemodularizat și nu este generic.
    // Consultați arhiva demo_func_ptr.zip pentru a vedea cum se poate face sortarea generică!

    // Pas 3: Afișare:
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }

    // Eliberăm memoria alocată.
    free(v);

    return 0;
}
