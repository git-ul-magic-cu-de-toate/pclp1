#include "./utils.h"

// urmatoarea functie este folosita pentru a schimba 2 string-uri
void swap(char** s1, char** s2) {
    char* aux = *s1;
    *s1 = *s2;
    *s2 = aux;
}

// functia urmatoare inversa string-ul pe dos (ii face oglinditul)
void reverse(char s[1001]) {
    int length = lungime_sir(s), begin = 0, end = length - 1;
    for (int i = begin; i < end ; i++) {
        char temp = s[i];
        s[i] = s[end];
        s[end] = temp;
        end--;
    }
}

// aceasta functie ne ajuta sa scapam zero-urile de la inceputul string-ului
void trimleadingzeros(char s[1001]) {
    int i = 0, j = 0;
    for (i = 0; s[i] == '0'; i++) {}
    for (j = 0; s[i]; i++) {
        s[j++] = s[i];
    }
    s[j] = '\0';
}

void caesar(char* s, int cheie) {
    // dim 31, resp 79 ca sa putem salva de 3 ori la rand cifrele
    // de la 0 la 9 si alfabetul
    char cifre[31], LitereMari[79], LitereMici[79];
    // in urmatoarele for-uri punem de 3 ori cifrele
    // de la 0 la 9 si literele de la a la z
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (char j = '0'; j <= '9'; j++) {
            cifre[index++] = j;
        }
    }
    index = 0;
    // spre ex avem in sirul s la poz curenta litera z si cheia -3
    // at ar trebui schimbata cu c de aceea am salvat
    // de 3 ori alfabetul si cifrele, pt astfel de cazuri
    for (int i = 0; i < 3; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            LitereMici[index++] = j;
        }
    }
    index = 0;
    for (int i = 0; i < 3; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            LitereMari[index++] = j;
        }
    }
    // constantele urmatoare reprezinta prima cifra, respectiv prima litera
    // din cele 3 repetari de cifre si litere din sirurile cifre litere...
    const int centru_cifre = 10, centru_litere = 26;
    int lungime = lungime_sir(s);
    for (int i = 0; i < lungime; i++) {
        // cheia poate fi oricat
        // prin % scapam de periodicitate, chiar daca cheia e negativa
        // % 26 pt ca sunt 26 de litere si % 10 pt ca sunt 10 cifre
        if (s[i] >= 'a' && s[i] <= 'z') {
            // acum spre ex avem litera x si cheia -5, s[26]='a'
            // adunam s[i]-'a'('x'-'a'), adica diferenta dintre pozitia literei
            // pe care o evaluam si litera a, si pur si simplu aplicam cheia
            // practic trebuie sa ajungem la indexul literei schimbate
            s[i] = LitereMici[centru_litere + s[i] - 'a' - cheie % 26];
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = LitereMari[centru_litere + s[i] - 'A' - cheie % 26];
        } else if (s[i] >= '0' && s[i] <= '9') {
            // similar ca la litere
            s[i] = cifre[centru_cifre + s[i] - '0' - cheie % 10];
        }
    }
}

void vigenere(char* s, char cheie[11]) {
    char cifre[31], LitereMari[79], LitereMici[79];
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (char j = '0'; j <= '9'; j++) {
            cifre[index++] = j;
        }
    }
    index = 0;
    for (int i = 0; i < 3; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            LitereMici[index++] = j;
        }
    }
    index = 0;
    for (int i = 0; i < 3; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            LitereMari[index++] = j;
        }
    }
    const int centru_cifre = 10, centru_litere = 26;
    int lungime = lungime_sir(s), nr = 0;
    for (int i = 0; i < lungime; i++) {
        // similar cifrului caesar, doar ca aici difera tipul de cheie
        // nr practic primeste instructiunea de rotire pe baza pozitiei in
        // alfabet a literei corespunzatoare din cheie
        nr = cheie[i % lungime_sir(cheie)] - 'A';
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = LitereMici[centru_litere + s[i] - 'a' - nr % 26];
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = LitereMari[centru_litere + s[i] - 'A' - nr % 26];
        } else if (s[i] >= '0' && s[i] <= '9') {
            s[i] = cifre[centru_cifre + s[i] - '0' - nr % 10];
        }
    }
    printf("%s\n", s);
}

int addition(char* n1, char* n2) {
    // ne asiguram ca lungimea celui de-al doilea numar e mai mare
    if (lungime_sir(n1) > lungime_sir(n2)) {
        swap(&n1, &n2);
    }
    // ne luam un string gol pentru a stoca rezultatul in el
    char add[1001] = "";
    int l1 = lungime_sir(n1), l2 = lungime_sir(n2);
    // inversam ambele numere
    reverse(n1);
    reverse(n2);
    // luam o variabila ajutatoare pentru urmatorii pasi
    int sacrifice = 0;
    // calculam suma a primelor l1 cifre
    for (int i = 0; i < l1; i++) {
        int suma = (n1[i] - '0') + (n2[i] - '0') + sacrifice;
        // adaugam la rezultat cifrele sumei
        char dummy = suma % 10 + '0';
        strncat(add, &(dummy), 1);
        sacrifice = suma / 10;
    }
    // calculam suma cifrelor ramase din numarul mai mare
    for (int i = l1; i < l2; i++) {
        int suma = (n2[i] - '0') + sacrifice;
        // adaugam la rezultat cifrele sumei
        char dummy = suma % 10 + '0';
        strncat(add, &(dummy), 1);
        sacrifice = suma / 10;
    }
    // se adauga restul ramas la rezultat
    if (sacrifice) {
        char dummy1 = sacrifice + '0';
        strncat(add, &(dummy1), 1);
    }
    // inversam inapoi rezultatul
    reverse(add);
    // stergem zero-urile de la inceputul rezultatului
    trimleadingzeros(add);
    printf("%s\n", add);
}

void SolveTask2() {
    char tip[9];
    scanf("%s", tip);
    char K[11];
    scanf("%s", K);
    char S[1001];
    // apelam functiile si le afisam
    if (strcmp(tip, "caesar") == 0) {
        scanf("%s", S);
        caesar(S, atoi(K));
        printf("%s\n", S);
    }
    if (strcmp(tip, "vigenere") == 0) {
        scanf("%s", S);
        vigenere(S, K);
    }
    if (strcmp(tip, "addition") == 0) {
        char N1[1001], N2[1001];
        scanf("%s", N1);
        scanf("%s", N2);
        caesar(N1, atoi(K));
        caesar(N2, atoi(K));
        addition(N1, N2);
    }
}
