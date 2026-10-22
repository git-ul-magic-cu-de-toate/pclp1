// Copyright 2024 Darius Neatu (darius.neatu@upb.ro)
// Solutie problema 2. ATENTIE! Aceasta redactare este completa si din puncte de vedere al codului
// si al comentariilor. De asemenea, are unele explicatii/printari in plus fata de o redactare normala,
// pentru a va ajuta sa intelegeti mai bine rezolvarea.
// NU este nevoie sa scrieti atat de detaliat la examen!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipul de date pentru lucrul cu fisiere GPEG
typedef struct {
    char *filename; // Numele fisierului in care se va scrie imaginea.
    double quality; // Calitatea imaginii.
    unsigned short int width; // Latimea imaginii.
    unsigned short int height; // Inaltimea imaginii.
    unsigned char *bytes; // Vector de bytes care reprezinta imaginea (4 bytes per pixel - RGBA).
    unsigned char sum_r, sum_g, sum_b, sum_a; // Sumele de control pentru R, G, B, A.
} gpeg_t;

// Functie care verifica daca un fisier este de tip GPEG.
int is_valid_gpeg(const gpeg_t* gpeg);

// Functie care citeste o imagine GPEG dintr-un fisier binar de la pozitia curenta a cursorului.
// Returneaza 1 in caz de succes, sau 0 in caz de eroare.
int read_gpeg(FILE *in, int ssd_size, gpeg_t *gpeg);

// Functie care scrie o imagine GPEG intr-un fisier binar cu numele contine in structura gpeg_t.
// Returneaza 1 in caz de succes, sau 0 in caz de eroare.
int write_gpeg(const gpeg_t *gpeg);

// Functie care citeste toate imaginile GPEG dintr-un fisier binar si le scrie in fisiere separate.
void read_all_gpegs(FILE *in, int size);

// Functie care determina dimensiunea unui fisier.
// Returneaza dimensiunea fisierului in bytes, sau -1 in caz de eroare.
int file_size(const char* filename); // Poate sa fie dat si un fisiere deschis.

// Functia main contine deschiderea fisierului binar,
// rezolvarea cerintelor se face in functii separate.
int main(void)
{
    // Numele fisierului de intrare.
    const char *filename = "ssd.bin";

    // Dimensiunea fisierului de intrare.
    long size = file_size(filename);

    // Deschidem fisierul de intrare - "ssd.bin".
    FILE *in = fopen(filename, "rb");
    if (in == NULL) {
        fprintf(stderr, "Eroare la deschiderea fisierului de intrare!\n");
        return -1;
    }

    // Cerinta 2: Citim toate imaginile GPEG din fisierul binar si le scriem in fisiere separate.
    read_all_gpegs(in, size);

    // Inchidem fisierul de intrare.
    fclose(in);
    return 0;
}

// Cerinta 1: Functie care verifica daca un fisier este de tip GPEG.
int is_valid_gpeg(const gpeg_t* gpeg)
{
    if (!gpeg || gpeg->width <= 0 || gpeg->height <= 0 || !gpeg->bytes) {
        return 0;
    }

    // Calculam sumele de control.
    int sum_r = 0, sum_g = 0, sum_b = 0, sum_a = 0;
    
    const int num_bytes = 4 * gpeg->width * gpeg->height; // 4 bytes per pixel
    for (int i = 0; i < num_bytes; i += 4) {
        sum_r ^= gpeg->bytes[i];
        sum_g ^= gpeg->bytes[i + 1];
        sum_b ^= gpeg->bytes[i + 2];
        sum_a ^= gpeg->bytes[i + 3];
    }

    // Verificam sumele de control calculate ca sunt egale cu cele din fisier.
    int is_valid = (sum_r == gpeg->sum_r) && (sum_g == gpeg->sum_g) && (sum_b == gpeg->sum_b) && (sum_a == gpeg->sum_a);
    if (!is_valid) {
        fprintf(stderr, "Imaginea %s are sume de control invalide!\n", gpeg->filename);
        return 0;
    }

    fprintf(stdout, "Imaginea %s este valida!\n", gpeg->filename);
    return 1;
}

// Functie care citeste numele unui fisier de pe SSD.
// Returneaza un pointer la un string cu numele fisierului, sau NULL in caz de eroare.
char *read_filename(FILE *in, int ssd_size)
{
    // Citim dimensiunea numelui fisierului.
    unsigned char filename_size;
    if (fread(&filename_size, sizeof(unsigned char), 1, in) != 1) {
        return NULL;
    }

    // Verificam daca dimensiunea numelui fisierului este valida.
    if (!filename_size || filename_size > ssd_size) {
        return NULL;
    }

    // Citim numele fisierului.
    char *filename = (char *)malloc((filename_size + 1) * sizeof(char));
    if (filename == NULL) {
        return NULL;
    }
    if (fread(filename, sizeof(char), filename_size, in) != filename_size) {
        free(filename);
        return NULL;
    }
    filename[filename_size] = '\0'; // Adaugam terminatorul de string.

    return filename;
}

// Functie care citeste bytes dintr-un fisier de pe SSD.
// Returneaza un pointer la un vector de bytes, sau NULL in caz de eroare.
unsigned char *read_bytes(FILE *in, int ssd_size, int num_bytes)
{
    // Verificam daca numarul de bytes este valid.
    if (num_bytes <= 0 || num_bytes > ssd_size) {
        return NULL;
    }

    unsigned char *bytes = (unsigned char *)malloc(num_bytes * sizeof(unsigned char));
    if (!bytes) {
        return NULL;
    }
    if ((int) fread(bytes, sizeof(unsigned char), num_bytes, in) != num_bytes) {
        free(bytes);
        return NULL;
    }

    return bytes;
}

// Functie care citeste sumele de control dintr-un fisier de pe SSD.
// Returneaza 1 in caz de succes, sau 0 in caz de eroare.
int read_sums(FILE *in, unsigned char *sum_r, unsigned char *sum_g, unsigned char *sum_b, unsigned char *sum_a)
{
    if (fread(sum_r, sizeof(unsigned char), 1, in) != 1) {
        return 0;
    }
    if (fread(sum_g, sizeof(unsigned char), 1, in) != 1) {
        return 0;
    }
    if (fread(sum_b, sizeof(unsigned char), 1, in) != 1) {
        return 0;
    }
    if (fread(sum_a, sizeof(unsigned char), 1, in) != 1) {
        return 0;
    }

    return 1;
}

// Functie care citeste o imagine GPEG dintr-un fisier binar de la pozitia curenta a cursorului.
// Returneaza 1 in caz de succes, sau 0 in caz de eroare.
int read_gpeg(FILE *in, int ssd_size, gpeg_t *gpeg)
{
    if (!in || !ssd_size || !gpeg) { // Verificam parametrii.
        return 0;
    }

    if (!(gpeg->filename = read_filename(in, ssd_size))) { // Citim numele fisierului.
        return 0;
    }

    if (fread(&gpeg->quality, sizeof(double), 1, in) != 1) { // Citim calitatea imaginii.
        free(gpeg->filename);
        return 0;
    }

    if (fread(&gpeg->width, sizeof(unsigned short int), 1, in) != 1) { // Citim latimea imaginii.
        free(gpeg->filename);
        return 0;
    }
    if (fread(&gpeg->height, sizeof(unsigned short int), 1, in) != 1) { // Citim inaltimea imaginii.
        free(gpeg->filename);
        return 0;
    }

    if (!(gpeg->bytes = read_bytes(in, ssd_size, 4 * gpeg->width * gpeg->height))) { // Citim bytes.
        free(gpeg->filename);
        return 0;
    }

    if (!read_sums(in, &gpeg->sum_r, &gpeg->sum_g, &gpeg->sum_b, &gpeg->sum_a)) { // Citim sumele de control.
        free(gpeg->filename);
        free(gpeg->bytes);
        return 0;
    }

    return 1;
}


// Functie care elibereaza memoria alocata datele interne ale unei imagini GPEG.
void unload_jpeg(gpeg_t *gpeg)
{
    free(gpeg->filename);
    free(gpeg->bytes);
}

// Functie care scrie o imagine GPEG intr-un fisier binar cu numele contine in structura gpeg_t.
// Returneaza 1 in caz de succes, sau 0 in caz de eroare.
int write_gpeg(const gpeg_t *gpeg)
{
    // Deschidem fisierul de iesire.
    FILE *out = fopen(gpeg->filename, "wb");
    if (out == NULL) {
        fprintf(stderr, "Eroare la deschiderea fisierului de iesire %s!\n", gpeg->filename);
        return 0;
    }

    // Scriem stringul "GPEG" in fisier fara '\0'.
    if (fwrite("GPEG", sizeof(char), 4, out) != 4) {
        fclose(out);
        return 0;
    }

    // Scriem calitatea imaginii.
    if (fwrite(&gpeg->quality, sizeof(double), 1, out) != 1) {
        fclose(out);
        return 0;
    }

    // Scriem latimea imaginii.
    if (fwrite(&gpeg->width, sizeof(unsigned short int), 1, out) != 1) {
        fclose(out);
        return 0;
    }

    // Scriem inaltimea imaginii.
    if (fwrite(&gpeg->height, sizeof(unsigned short int), 1, out) != 1) {
        fclose(out);
        return 0;
    }

    // Scriem bytes.
    unsigned int size = 4 * gpeg->width * gpeg->height;
    if (fwrite(gpeg->bytes, sizeof(unsigned char), size, out) != size) {
        fclose(out);
        return 0;
    }

    // Scriem sumele de control (simultan, daca le punem intr-un vector).
    unsigned char sum[4] = {gpeg->sum_r, gpeg->sum_g, gpeg->sum_b, gpeg->sum_a};
    if (fwrite(sum, sizeof(unsigned char), 4, out) != 4) {
        fclose(out);
        return 0;
    }

    fclose(out);
    return 1;
}

// Functie care citeste toate imaginile GPEG dintr-un fisier binar si le scrie in fisiere separate.
void read_all_gpegs(FILE *in, int size)
{
    // Citim un GPEG la fiecare pas de cursor 0, 1, 2, 3, ... (imagini posibil suprapuse).
    
    int cursor = ftell(in); // Initial cursorul este la inceputul fisierului.
    while (cursor < size) {
        // Incercam sa citim un GPEG.
        gpeg_t gpeg; ;
        if (!read_gpeg(in, size, &gpeg) || !is_valid_gpeg(&gpeg)) {
            // Nu am putut citi un GPEG sau este invalid, trecem la urmatorul, raportat la vechiu cursor,
            // dar cu un byte in fata.
            fseek(in, ++cursor, SEEK_SET);
        } else {
            // Am citit un GPEG valid, trecem la urmatorul, raportat la noul cursor.
            if (write_gpeg(&gpeg)) {
                fprintf(stdout, "Imaginea %s a fost scrisa cu succes!\n", gpeg.filename);
            } else {
                fprintf(stderr, "Eroare la scrierea imaginii %s!\n", gpeg.filename);
            }

            // NU este nevoie sa actualizam cursorul, pentru ca read_gpeg() a facut asta deja.
            // Eliberam memoria alocata pentru GPEG.
            unload_jpeg(&gpeg);
        }
    }
}

// Functie care determina dimensiunea unui fisier.
// Returneaza dimensiunea fisierului in bytes, sau -1 in caz de eroare.
int file_size(const char* filename)
{
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        return -1;
    }

    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fclose(f);

    return size;
}

//  $ hexdump -C ssd.bin 
// 00000000  00 c8 03 0a 67 69 67 65  6c 2e 67 70 65 67 cd cc  |....gigel.gpeg..|
// 00000010  cc cc cc cc ec 3f 03 00  02 00 00 00 00 ff ff ff  |.....?..........|
// 00000020  ff ff ff 00 00 00 ff ff  ff ff ff 00 00 00 ff ff  |................|
// 00000030  ff 01 ff ff ff fe 00 c8  03 36 15 00 09 05        |.........6....|
// 0000003e
// $ make && ./02-data_recovery
// Imaginea gigel.gpeg este valida!
// Imaginea gigel.gpeg a fost scrisa cu succes!
//  $ ls -l gigel.gpeg 
// -rw-r--r--  1 dariusn  staff  44 Jan 25 01:57 gigel.gpeg
//  $ hexdump -C gigel.gpeg 
// 00000000  47 50 45 47 cd cc cc cc  cc cc ec 3f 03 00 02 00  |GPEG.......?....|
// 00000010  00 00 00 ff ff ff ff ff  ff 00 00 00 ff ff ff ff  |................|
// 00000020  ff 00 00 00 ff ff ff 01  ff ff ff fe              |............|
// 0000002c

