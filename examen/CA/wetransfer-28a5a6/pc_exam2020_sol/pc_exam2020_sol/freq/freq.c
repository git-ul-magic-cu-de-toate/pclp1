// Copyright 2020 Echipa de Programarea Calculatoarelor, Seria CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ssize; /* numar pozitiv care ne specifica lungimea secventei */
    char *seq; /* sir de octeti de dimensiune ssize */
    int freq; /* frecventa de aparitie a codului de analiza in secventa */
} sequence_t;

sequence_t seq_read_from_pos(FILE* in_space, int pos, int size);
void count_freq(sequence_t *s, char magic_byte);
void seq_write(FILE *out, sequence_t s);
void print_seq(int max_freq);

int main() {
    FILE* in_space = fopen("space.bin", "rb");
    if (!in_space) {
        fprintf(stderr, "Cannot open space.bin\n");
        return -1;
    }

    FILE *in_analysis = fopen("analysis.txt", "rt");
    if (!in_analysis) {
        fprintf(stderr, "Cannot open analysis.txt\n");
        return -1;
    }

    FILE *out = fopen("seqs.bin", "wb");
    if (!out) {
        fprintf(stderr, "Cannot open seqs.bin\n");
        return -1;
    }

    int magic_byte;
    fscanf(in_analysis, "%d", &magic_byte);
    
    int max_freq = -1;
    int pos, size;
    while (fscanf(in_analysis, "%d%d", &pos, &size) == 2) {
        if (pos < 0 || size == 0) {
            continue;
        }

        if (size < 0) {
            size = -size; // size = |size|
            pos = pos - size + 1 ; // pos este defapt finalul secventei, il mut la inceput
            if (pos < 0) {
                continue;
            }
        }

        sequence_t s = seq_read_from_pos(in_space, pos, size);
        if (s.seq == NULL) {
            // citirea a esuat
            continue;
        }

        count_freq(&s, magic_byte);
        if (s.freq > max_freq) {
            max_freq = s.freq;
        }

        seq_write(out, s);

        free(s.seq);
    }    

    // inchid toate fisiere
    fclose(in_space);
    fclose(in_analysis);
    fclose(out);

    print_seq(max_freq);

    return 0;
}

sequence_t seq_read_from_pos(FILE* in, int pos, int size) {
    sequence_t s;
    s.ssize = 0;
    s.seq = NULL; // necesar pentru a sti ca citirea a esuat

    // ne deplasam la final pentru a determina dimensiunea fisierului
    fseek(in, 0, SEEK_END);
    int file_size = ftell(in);
    if (pos + size >= file_size) {
        // cerere invalida
        return s;
    }

    // mergem mereu la inceputul fisierului, intrucat operatiilor pot
    // fi in orice ordine
    // apoi mergem la pozitia pos din fisier
    fseek(in, pos, SEEK_SET);

    s.ssize = size;
    s.seq = (char *) malloc(s.ssize * sizeof(char));
    if (!s.seq) {
        // eroare la alocare
        return s;
    }
    fread(s.seq, sizeof(char), s.ssize, in);

    return s;
}

void count_freq(sequence_t *s, char magic_byte) {
    s->freq = 0;

    for (int i = 0; i < s->ssize; ++i) {
        char byte = s->seq[i];

        for (int p = 0; p < 6; ++p) {
            char to_check = (byte >> p) & 7;
            if (to_check == magic_byte) {
                ++s->freq;
            }
        }
    }
}

void seq_write(FILE *out, sequence_t s) {
    fwrite(&s.ssize, sizeof(int), 1, out);
    fwrite(s.seq, sizeof(char), s.ssize, out);
    fwrite(&s.freq, sizeof(int), 1, out);
}

sequence_t seq_read(FILE *in) {
    sequence_t s;
    s.seq = NULL;

    if (feof(in)) {
        return s;
    }

    fread(&s.ssize, sizeof(int), 1, in);
    s.seq = (char *) malloc(s.ssize * sizeof(char));
    if (!s.seq) {
        // eroare la alocare
        return s;
    }
    fread(s.seq, sizeof(char), s.ssize, in);
    fread(&s.freq, sizeof(int), 1, in);

    return s;
}

void print_seq(int max_freq) {
    // deschidem seqs.bin pentru citire
    FILE *in = fopen("seqs.bin", "rb");
    if (!in) {
        fprintf(stderr, "Cannot open seqs.bin\n");
        return;
    }

    while (1) {
        sequence_t s = seq_read(in);
        if (s.seq == NULL) {
            break;
        }

        // daca secventa curenta are frecventa maxima
        if (s.freq == max_freq) {
            // se printeaza
            for (int i = 0; i < s.ssize; ++i) {
                printf("%X", (int)s.seq[i]);
            }
            printf("\n");
        }

        free(s.seq);
    }

    fclose(in);
}