// Copyright 2024 Darius Neatu (darius.neatu@upb.ro)
// Solutie problema 1. ATENTIE! Aceasta redactare este completa si din puncte de vedere al codului
// si al comentariilor. De asemenea, are unele explicatii in plus fata de o redactare normala,
// pentru a va ajuta sa intelegeti mai bine anumite concepte.
// NU este nevoie sa scrieti comentarii atat de detaliat la examen.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 24
#define FILENAME_NOKEYS "data.txt"
#define FILENAME_FILTER "filtered_data.txt"

// Simbolurile urmatoare sunt mentionate in enunt, dar fara a li se da o valoare. Orice valoare este deci arbitrar aleasa.
// Important este sa definim ceva cu sens.
#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 100
#define MAX_TEXT_SIZE 20

// Structura care retine frecvanta cuvintelor cheie.
typedef struct {
    int count;
    char key[MAX_WORD_SIZE];
} key_freq_y;

// Structura care retine datele filtrate.
typedef struct {
    char *aggregated_text; // Textul agregat. Initial este NULL.

    key_freq_y key_freq[NMAX]; // Vector de frecventa cuvinte cheie gasite. Initial este NULL.
} filtered_data_t;

// Functie care calculeaza lungimea textului agregat, care este 0 daca textul este NULL.
int get_aggregated_len(const filtered_data_t *filtered_data);

// Functie care cauta cuvintele cheie in linia data.
// Returneaza 1 daca gaseste cel putin un cuvant cheie, altfel 0.
int find_keys(filtered_data_t *filtered_data, const char *line, const int num_all_keys, const char **all_keys);

// Functie care scrie o linie la finalul fisierului FILENAME_NOKEYS.
// Se redeschide fisierul la fiecare apel, deci nu este nevoie sa fie deschis inainte de apelul functiei.
// Se puncteaza cu maxim si o solutie care nu deschide fisierul la fiecare apel, dar care se asigura
// ca fisierul este creat abia cand se scrie prima data in el (nu la inceput de main).
void dump_line(const char *line);

// Functie care scrie datele filtrate la finalul fisierului FILENAME_FILTER.
// Ulterior, resetaza datele filtrate din filtered_data.
// Se redeschide fisierul la fiecare apel, deci nu este nevoie sa fie deschis inainte de apelul functiei.
// Se puncteaza cu maxim si o solutie care nu deschide fisierul la fiecare apel, dar care se asigura
// ca fisierul este creat abia cand se scrie prima data in el (nu la inceput de main).
void dump_filtered_data(filtered_data_t* filtered_data);

// Functie care adauga o linie la textul agregat.
// Returneaza 0 in caz de eroare, altfel 1.
int append_line(const char* line, filtered_data_t* filtered_data);

int main(int argc, const char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Utilizare: %s key1 key2 ...\n", argv[0]);
        return 1;
    }
    const int num_all_keys = argc - 1;
    if (num_all_keys > NMAX) {
        fprintf(stderr, "Prea multe cuvinte cheie! Maxim %d cuvinte cheie permise.\n", NMAX);
        return 1;
    }
    fprintf(stdout, "Numarul de cuvinte cheie: %d\n", num_all_keys);
    const char **all_keys = argv + 1;
    for (int i = 0; i < num_all_keys; i++) {
        if (strlen(all_keys[i]) >= MAX_WORD_SIZE) {
            fprintf(stderr, "Cuvantul cheie %s este prea lung!\n", all_keys[i]);
            return 1;
        }
        fprintf(stdout, "Cuvant cheie %d: %s\n", i + 1, all_keys[i]);
    }
    fprintf(stdout, "\n");

    filtered_data_t filtered_data = {0}; // sau memset(&filtered_data, 0, sizeof(filtered_data_t));
    char line[MAX_LINE_SIZE + 1];
    while (fgets(line, MAX_LINE_SIZE, stdin)) {
        if (!strcmp(line, ".\n")) { // Atentie! fgets() citeste si terminatorul de linie '\n'.
            fprintf(stdout, "Am citit caracterul '.'. STOP.\n");
            break; // Am citit caracterul '.', STOP.
        }
        fprintf(stdout, "Am citit linia urmatoare:\n%s", line);

        // Facem o copie a datelor filtrate. Ne intereseaza doar frecventa cuvintelor cheie.
        // Textul agregat nu ne intereseaza sa il copiem.
        filtered_data_t copy_filtered_data = filtered_data;

        if (!find_keys(&filtered_data, line, num_all_keys, all_keys)) {
            fprintf(stderr, "Nu s-a gasit niciun cuvant cheie in linia data. Se copiaza linia in fisierul %s.\n", FILENAME_NOKEYS);
            dump_line(line);
        } else {
            if (get_aggregated_len(&filtered_data) + strlen(line) <= MAX_TEXT_SIZE) { // Textul NOU agregat e sub limita.
                fprintf(stdout, "Se adauga linia la textul agregat.\n");
                append_line(line, &filtered_data); // Adaugam linia la textul agregat.
                continue;
            }
        
            fprintf(stdout, "Noul text agregat ar fi prea mare. Se copiaza datele filtrate preexistente in fisierul %s. Resetam agregarea.\n", FILENAME_FILTER);
            dump_filtered_data(&copy_filtered_data); // Scriem datele filtrate si eliberam memoria alocata.
            memset(&filtered_data, 0, sizeof(filtered_data_t)); // Resetam datele filtrate.

            find_keys(&filtered_data, line, num_all_keys, all_keys); // Adaugam contorii cuvintelor cheie din nou, am resetat datele filtrate.
            append_line(line, &filtered_data); // Adaugam linia la textul agregat.

            if (get_aggregated_len(&filtered_data) > MAX_TEXT_SIZE) { // Textul agregat deja este prea mare.
                fprintf(stdout, "Linia citita este prea mare pentru a fi salvata intr-un text agregat. Se copiaza datele filtrate in fisierul %s. Resetam agregarea.\n", FILENAME_FILTER);
                dump_filtered_data(&filtered_data); // Scriem datele filtrate si eliberam memoria alocata.
            }
        }
        fprintf(stdout, "\n");
    }

    if (filtered_data.aggregated_text) {
        dump_filtered_data(&filtered_data);
    }

    return 0;
}

// Functie care calculeaza lungimea textului agregat, care este 0 daca textul este NULL.
int get_aggregated_len(const filtered_data_t *filtered_data)
{
    return filtered_data->aggregated_text ? strlen(filtered_data->aggregated_text) : 0;
}

// Functie care gaseste toate aparitiile cu suprapunere ale unui subsir in sir.
// Returneaza numarul de aparitii.
int find_all_overlapping(const char *str, const char *substr)
{
    int n = strlen(str);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(str + i, substr) == str + i) {
            count++;
        }
    }
    return count;
}

// Functie care returneaza indexul cheii in vectorul de frecventa.
// Daca nu gaseste cheia, returneaza -1.
int find_key_index(const filtered_data_t *filtered_data, const char *key)
{
    for (int i = 0; i < NMAX; i++) {
        if (!strcmp(filtered_data->key_freq[i].key, key)) {
            return i;
        }
    }
    return -1;
}

// Functie care cauta cuvintele cheie in linia data.
// Returneaza 1 daca gaseste cel putin un cuvant cheie, altfel 0.
int find_keys(filtered_data_t *filtered_data, const char *line, const int num_all_keys, const char **all_keys)
{
    int found_keys = 0;
    for (int i = 0; i < num_all_keys; i++) {
        int count = find_all_overlapping(line, all_keys[i]);
        if (!count) {
            continue;
        }

        found_keys = 1; // Am gasit cel putin un cuvant cheie.

        // Cautam cuvantul cheie in vectorul de frecventa.
        int index = find_key_index(filtered_data, all_keys[i]);
        if (index == -1) { // Cuvantul cheie nu a fost gasit.
            for (int j = 0; j < NMAX; j++) {
                if (!filtered_data->key_freq[j].count) { // Am gasit o pozitie libera.
                    index = j;
                    break;
                }
            }

            strcpy(filtered_data->key_freq[index].key, all_keys[i]); // Copiem cuvantul cheie.
        }

        filtered_data->key_freq[index].count += count; // Adaugam frecventa cuvantului cheie.
    }

    return found_keys;
}

// Functie care scrie o linie la finalul fisierului FILENAME_NOKEYS.
// Se redeschide fisierul la fiecare apel, deci nu este nevoie sa fie deschis inainte de apelul functiei.
// Se puncteaza cu maxim si o solutie care nu deschide fisierul la fiecare apel, dar care se asigura
// ca fisierul este creat abia cand se scrie prima data in el (nu la inceput de main).
void dump_line(const char *line)
{
    FILE *out = fopen(FILENAME_NOKEYS, "a");
    if (!out) {
        fprintf(stderr, "Eroare la deschiderea fisierului %s!\n", FILENAME_NOKEYS);
        return;
    }
    fprintf(out, "%s", line);
    fclose(out);
}

// Functie care scrie datele filtrate la finalul fisierului FILENAME_FILTER.
// Ulterior, resetaza datele filtrate din filtered_data.
// Se redeschide fisierul la fiecare apel, deci nu este nevoie sa fie deschis inainte de apelul functiei.
// Se puncteaza cu maxim si o solutie care nu deschide fisierul la fiecare apel, dar care se asigura
// ca fisierul este creat abia cand se scrie prima data in el (nu la inceput de main).
void dump_filtered_data(filtered_data_t* filtered_data)
{
    FILE *out = fopen(FILENAME_FILTER, "a");
    if (!out) {
        fprintf(stderr, "Eroare la deschiderea fisierului %s!\n", FILENAME_FILTER);
        return;
    }
    
    // Scriem textul agregat.
    fprintf(out, "%s", filtered_data->aggregated_text);
    // Scriem numarul de cuvinte cheie gasite si frecventa lor.
    int num_found_keys = 0;
    for (int i = 0; i < NMAX; i++) {
        if (filtered_data->key_freq[i].count) {
            num_found_keys++;
        }
    }
    fprintf(out, "Numar chei = %d\n", num_found_keys);
    for (int i = 0; i < NMAX; i++) {
        if (filtered_data->key_freq[i].count) {
            fprintf(out, "%d x \"%s\"\n", filtered_data->key_freq[i].count, filtered_data->key_freq[i].key);
        }
    }
    fprintf(out, "\n");
    fclose(out);

    // Eliberam memoria alocata pentru textul agregat. Resetam datele filtrate.
    free(filtered_data->aggregated_text);
    memset(filtered_data, 0, sizeof(filtered_data_t));
}

// Functie care adauga o linie la textul agregat.
// Returneaza 0 in caz de eroare, altfel 1.
int append_line(const char* line, filtered_data_t* filtered_data)
{
    int new_aggregated_text_size = get_aggregated_len(filtered_data) + strlen(line); // Deja este inclus terminatorul de string.
    char *new_aggregated_text = (char *)realloc(filtered_data->aggregated_text, new_aggregated_text_size);
    if (!new_aggregated_text) {
        fprintf(stderr, "Eroare la realocarea memoriei pentru textul agregat!\n");
        free(filtered_data->aggregated_text); // Eliberam memoria alocata pana acum.
        return -1;
    }
    filtered_data->aggregated_text = new_aggregated_text;

    // Adaugam linia la finalul textului agregat.
    strcat(filtered_data->aggregated_text, line);

    return 1;
}

// $ make && ./01-data_filtering linie steaua "manchester united" < 01-stdin_input.txt 
// gcc -Wall -Wextra -g -o 01-data_filtering 01-data_filtering.c -lm
// Numarul de cuvinte cheie: 3
// Cuvant cheie 1: linie
// Cuvant cheie 2: steaua
// Cuvant cheie 3: manchester united
//
// Am citit linia urmatoare:
// asta e prima linie
// Se adauga linia la textul agregat.
// Am citit linia urmatoare:
// a doua
// Nu s-a gasit niciun cuvant cheie in linia data. Se copiaza linia in fisierul data.txt.
//
// Am citit linia urmatoare:
// a treia
// Nu s-a gasit niciun cuvant cheie in linia data. Se copiaza linia in fisierul data.txt.
//
// Am citit linia urmatoare:
// jucam si noi o linie pe bordura si ne uitam la steaua. bate steaua!
// Noul text agregat ar fi prea mare. Se copiaza datele filtrate preexistente in fisierul filtered_data.txt. Resetam agregarea.
// Linia citita este prea mare pentru a fi salvata intr-un text agregat. Se copiaza datele filtrate in fisierul filtered_data.txt. Resetam agregarea.
//
// Am citit linia urmatoare:
// linie steaua linie steaua linie steaua linie steauaaa manchester united
// Noul text agregat ar fi prea mare. Se copiaza datele filtrate preexistente in fisierul filtered_data.txt. Resetam agregarea.
// Linia citita este prea mare pentru a fi salvata intr-un text agregat. Se copiaza datele filtrate in fisierul filtered_data.txt. Resetam agregarea.
//
// Am citit caracterul '.'. STOP.
//
//  $ cat data.txt 
// a doua
// a treia
//  $ cat filtered_data.txt 
// asta e prima linie
// Numar chei = 1
// 1 x "linie"
//
// jucam si noi o linie pe bordura si ne uitam la steaua. bate steaua!
// Numar chei = 2
// 1 x "linie"
// 2 x "steaua"
//
// (null)Numar chei = 0
//
// linie steaua linie steaua linie steaua linie steauaaa manchester united
// Numar chei = 3
// 4 x "linie"
// 4 x "steaua"
// 1 x "manchester united"
