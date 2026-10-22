#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#



#
typedef struct {
    int ssize;
    char *seq;
    int freq;
} sequence;

sequence get_sequence(FILE *in, int start, int size, char code);

int count_apparitions(char elem, char code);

void output_bin(FILE *out, sequence s);

void print_from_file(FILE *in);





















int main()
{
    FILE *in, *bin, *out;
    in = fopen("analysis.txt", "rt");
    if (!in) {
        printf("Eroare de deschidere a fisierului\n");
        return 1;
    }
    bin = fopen("space.bin", "rb");
    out = fopen("seqs.bin", "wb");
    char code;
    fscanf(in, "%c", &code);
    int start, size;
    while (fscanf(in, "%d%d", &start, &size) != EOF) {
        sequence s;
        s = get_sequence (bin, start, size, code);
        output_bin(out, s);
        free(s.seq);
    }
    fclose(in);
    fclose(bin);
    fclose(out);
    in = fopen("seqs.bin", "rb");
    print_from_file(in);
    fclose(in);
    return 0;
}

int count_apparitions(char elem, char code)
{
    int cnt = 0;
    char mask = 7; /// 111
    int i = 1;
    while (i <= 6) {
        i++;
        if ((mask & elem) == code)
            cnt++;
        mask <<= 1;
        code <<= 1;
    }
    return cnt;
}

sequence get_sequence(FILE *in, int start, int size, char code)
{
    sequence s;
    int sz;
    if (size < 0)
        sz = -size;
    else 
        sz = size;
    s.seq = (char *)malloc(sz * sizeof(char));
    if (!s.seq) {
        printf("Eroare...\n");
        s.ssize = -1;
        return s;
    }
    fseek(in, 0, SEEK_SET);
    char elem;
    int pos = 0;
    while (pos <= start) {
        fread(&elem, sizeof(char), 1, in);
        pos++;
    }
    int cnt = 0;
    s.freq = 0;
    if (size > 0) {
        while (size > 0) {
            size--;
            cnt++;
            s.freq += count_apparitions(elem, code);
            s.seq[cnt - 1] = elem;
            fread(&elem, sizeof(char), 1, in);
        }
        s.ssize = cnt;
    } else {
        size = -size;
        fseek(in, -size + 1, SEEK_CUR);
        fread(&elem, sizeof(char), 1, in);
        while (size > 0) {
            size--;
            cnt++;
            s.freq += count_apparitions(elem, code);
            s.seq[cnt - 1] = elem;
            fread(&elem, sizeof(char), 1, in);
        }
        s.ssize = cnt;
    }
    return s;
}

void output_bin(FILE *out, sequence s)
{
    fwrite(&s.ssize, sizeof(int), 1, out);
    for (int i = 0; i < s.ssize; i++)
        fwrite(&s.seq[i], sizeof(char), 1, out);
    fwrite(&s.freq, sizeof(int), 1, out);
}

void print_from_file(FILE *in)
{
    sequence s;
    int maxim_ap = 0;
    while (1) {
        if (fread(&s.ssize, sizeof(int), 1, in) <= 0) {
            break;
        }
        s.seq = (char *)malloc(s.ssize * sizeof(char));
        for (int i = 0; i < s.ssize; i++)
            fread(&s.seq[i], sizeof(char), 1, in);
        fread(&s.freq, sizeof(int), 1, in);
        if (s.freq > maxim_ap)
            maxim_ap = s.freq;
        free(s.seq);
    }
    fseek(in, 0, SEEK_SET);
    while (1) {
        if (fread(&s.ssize, sizeof(int), 1, in) <= 0) {
            break;
        }
        s.seq = (char *)malloc(s.ssize * sizeof(char));
        for (int i = 0; i < s.ssize; i++)
            fread(&s.seq[i], sizeof(char), 1, in);
        fread(&s.freq, sizeof(int), 1, in);
        if (s.freq == maxim_ap) {
            for (int i = 0; i < s.ssize; i++)
                printf("%X", s.seq[i]);
            printf("\n");
        }
        free(s.seq);
    }
}