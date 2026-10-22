#include "./utils.h"

int numere_a(char* sir) {
    char maxim = sir[1];
    int pozitie = 1;
    // pentru a determina directia de miscare
    // folosim un for care determina pe ce pozitie
    // se afla cifra maxima, dupa care returnam pozitia
    for (int i = 2; i <= 4; i++) {
        if (maxim < sir[i]) {
            maxim = sir[i];
            pozitie = i;
        }
    }
    return pozitie;
}

// pentru a determina lungimea unui sir, am creat urmatoarea
// functie care citeste fiecare caracter diferit de NULL
// pentru fiecare caracter citit, contor-ul lungime creste cu 1
int lungime_sir(char* sir) {
    int lungime = 0;
    while (*sir != '\0') {
        sir++;
        lungime++;
    }
    return lungime;
}

// urmatoarea functie determina daca sirul este sau nu palindrom
// prin simpla comparatie a sirului cu oglinditul acestuia
int palindrom(char s[]) {
    int i = 1, j = lungime_sir(s) - 1;
    for (i, j; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return 0;
    } }
    return 1;
}

// urmatoarea functie determina daca numarul este prim
// luam un d (divizor) care porneste de la 2
// in cazul in care numarul n se imparte fara rest la d
// atunci d este divizor al numarul n, deci nu e prim, in caz contrar e prim
int este_prim(int n) {
    int prim = 1, d = 2;
    while (prim == 1 && d*d <= n) {
        if (n % d == 0) {
            prim = 0;
        } else {
            d = d + 1;
        }
    }
    return prim;
}

int numere_b(char* sir) {
    // lungime este initializat cu lungimea sirului (sir)
    int lungime = lungime_sir(sir);
    // k ia valorile 0 (nu e palindrom) si 1 (e palindrom)
    int k = palindrom(sir);
    // se calc numarul format din cifrele de pe  ultimele 2 pozitii (xn-1xn)
    int x = (*(sir + lungime - 2) - '0') * 10 + *(sir + lungime - 1) - '0';
    // x_prim ia valorile 0 (nu e prim) si 1 (e prim)
    int x_prim = este_prim(x);
    // trecem prin toate cazurile pe care le avem
    if (k == 1 && x_prim == 1) {
        return 1;
    } else if (k == 1 && x_prim == 0) {
        return 2;
    } else if (k == 0 && x_prim == 1) {
        return 3;
    } else if (k == 0 && x_prim == 0) {
        return 4;
    }
}

int numere_c(char* sir) {
    // initializam lungime cu numarul de cifre dat
    // initializam k cu numarul primelor k cifre
    int S = 0, lungime = sir[1] - '0', k = sir[2] - '0';
    // declaram un sir (sir2) de dimensiune (lungime+1) in care vom retine
    // valorile sirului (sir)
    const int l = lungime + 1;
    char sir2[150];
    for (int i = 3; i < lungime + 3; i++) {
        sir2[i-3] = sir[i];
    }
    // calculam suma dorita
    for (int i = 0; i <= k - 1; i++) {
        S += (sir2[i * k % (l - 1)] - '0');
    }
    return S % 4;
}

void SolveTask1() {
    int N = 0, M = 0;
    // se citesc dimensiunile matricei
    scanf("%d %d", &N, &M);
    const int n1 = N, m1 = M;
    int matrice[n1][m1];
    // initializam matricea cu cu matricea nula
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            matrice[i][j] = 0;
    // cu sirul (var) vom gasi daca numerele incep cu a, b sau c
    char var[100];
    // o sa folosim x si y pentru a gasi urmatoarea directie de mers
    int x = 0, y = 0;
    // deoarece traseul porneste de la coordonatele 0 0
    // notam pozitia de start cu 1
    matrice[0][0] = 1;
    // prima miscare porneste de la 2, deoarece pozitia initiala este 1
    int nr = 2;
    while (scanf("%s", var) != EOF) {
        // in rezultat salvam valoarea iesita din functia tipului de numar
        int rezultat = 0;
        // se cauta urmatoarea directie de mers pentru numerele de tip a
        if (var[0] == 'a') {
            rezultat = numere_a(var);
            switch (rezultat) {
            case 1:
            matrice[x][y+1] = nr;
            y++;
                break;
            case 2:
            matrice[x-1][y] = nr;
            x--;
                break;
            case 3:
            matrice[x][y-1] = nr;
            y--;
                break;
            case 4:
            matrice[x+1][y] = nr;
            x++;
                break;
            }
        // se cauta urmatoarea directie de mers pentru numerele de tip b
        } else if (var[0] == 'b') {
            rezultat = numere_b(var);
            switch (rezultat) {
            case 1:
            matrice[x][y-1] = nr;
            y--;
                break;
            case 2:
            matrice[x][y+1] = nr;
            y++;
                break;
            case 3:
            matrice[x-1][y] = nr;
            x--;
                break;
            case 4:
            matrice[x+1][y] = nr;
            x++;
                break;
            }
        // se cauta urmatoarea directie de mers pentru numerele de tip c
        } else if (var[0] == 'c') {
            rezultat = numere_c(var);
            switch (rezultat) {
            case 0:
            matrice[x][y-1] = nr;
            y--;
                break;
            case 1:
            matrice[x-1][y] = nr;
            x--;
                break;
            case 2:
            matrice[x][y+1] = nr;
            y++;
                break;
            case 3:
            matrice[x+1][y] = nr;
            x++;
                break;
            }
        }
        nr++;
    }
    // afisam traseul
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1 ; j++)
            printf("%d ", matrice[i][j]);
        printf("\n");
    }
}
