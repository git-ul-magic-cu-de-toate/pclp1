// Copyright 2017 PC Team

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 13        // numarul de jocuri considerate
#define NAME_MAX 1000  // lungimea maxima a unui nume

// task a
typedef struct {
    char *player_name;
    char predictions[NMAX];
} pronosport_t;


// task b
// a, b vectori
// n = numar de elemente (au acelasi numar de elemente)
// un element dintr-un vector are size bytes
int cmp_simple(void *a, void *b, int n, int size) {
    int cnt = 0;

    unsigned char *p = a;
    unsigned char *q = b;

    for (int i = 0; i < n; ++i) {
        // construim a[i] si b[i]
        unsigned char *ai = p + i * size;  // ai == &a[i]
        unsigned char *bi = q + i * size;  // bi == &b[i]

        // daca stim unde incep cele 2 elemente
        // ramane sa comparam cei size bytes incepand de acolo
        int match = 1;
        for (int k = 0; k < size; ++k) {
            if (ai[k] != bi[k]) {
                match = 0;
                break;
            }
        }

        // daca match == 1, atunci inseamna ca toti octetii au
        // fost egali
        if (match) {
            cnt++;
        }
    }

    return cnt;
}

// desigur ca puteam folosi functia memcmp
int cmp(void *a, void *b, int n, int size) {
    unsigned char *ai = a;
    unsigned char *bi = b;
    int cnt = 0;

    for (int i = 0; i < n; ++i, ai += size, bi += size) {
        if (!memcmp(ai, bi, size)) {
            cnt++;
        }
    }

    return cnt;
}


// task 3+4
typedef struct {
    char *player_name;
    int correct_predictions;
} player_t;

void read_tickets(int n, pronosport_t *tickets);
player_t *get_players(int n, pronosport_t *tickets, char *results);
void print(int n, player_t *players);
void sort(int n, player_t *players);

int main() {
    int n;  // numar de jucatori (bilete)
    scanf("%d", &n);

    // biletele sunt stocate intr-un vector
    pronosport_t *tickets = malloc(n * sizeof(pronosport_t));
    read_tickets(n, tickets);

    // citesc si rezultatul
    char results[NMAX + 1];
    scanf("%s", results);

    // obtine un vector de tipul player_t
    player_t *players = get_players(n, tickets, results);

    sort(n, players);
    print(n, players);

    for (int i = 0; i < n; ++i) {
        free(tickets[i].player_name);
        free(players[i].player_name);
    }
    free(tickets);
    free(players);

    return 0;
}

// functia citeste n elemente de tip pronosport_t
// si le salveaza in vectorul tickets
void read_tickets(int n, pronosport_t *tickets) {
    char name[NAME_MAX];
    char predictions[NMAX + 1];

    for (int i = 0; i < n; ++i) {
        // citeste o linie de forma: nume preziceri
        scanf("%s%s", name, predictions);

        tickets[i].player_name = strdup(name);

        // atentie! tickets[i].predictions este un vector,
        // nu un sir de caractere (adica nu se termina cu '\0')
        for (int k = 0; k < NMAX; ++k) {
            tickets[i].predictions[k] = predictions[k];
        }
    }
}

// construieste vectorul de jucatori
player_t *get_players(int n, pronosport_t *tickets, char *results) {
    // presupun ca am n jucatori (fiecare bilet are nume de jucator unic)
    player_t *players = malloc(n * sizeof(player_t));
    for (int i = 0; i < n; ++i) {
        players[i].player_name = strdup(tickets[i].player_name);

        int cnt = cmp(tickets[i].predictions, results, NMAX, sizeof(char));
        players[i].correct_predictions = cnt;
    }

    return players;
}

// sorteaza jucatorii descrescatori dupa numarul de preziceri
// corecte al respectivului jucator
void sort(int n, player_t *players) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int match_i = players[i].correct_predictions;
            int match_j = players[j].correct_predictions;

            if (match_i < match_j) {
                player_t tmp = players[i];
                players[i]   = players[j];
                players[j]   = tmp;
            }
        }
    }
}

void print(int n, player_t *players) {
    for (int i = 0; i < n; ++i) {
        printf("%s made %d good predictions\n",
              players[i].player_name, players[i].correct_predictions);
    }
}
