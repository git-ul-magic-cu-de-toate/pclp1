#include <stdio.h>

// variabile globale, statice globale, locale, locale statice
int gigel; // variabila globala - INTERZIS

int f(int x) { // x locala
    int gigel; // locala

    if (gigel) {
        int gigel;
        return gigel;
    }

    return 0;
}

int main(void)
{
    // Aplicatie, sa numaram de cate ori s-a apelat o functie!
    int gigel; // locala, neinitializata
    if (gigel > 0) {
        int gigel;

        gigel = f(gigel);
    }
    int gigel2 = 5; // locala
    return 0;
}
