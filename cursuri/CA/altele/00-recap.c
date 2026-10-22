// Copyright 2020 Sabina Horincar (sabina.horincar@gmail.com)

// Deschidere și verificare
// FILE* fopen(const char* filepath, const char* flags);
//      filepath = cale catre fisier
//      flags = sir cu specificatori
//              r (read) sau w (write) sau a (append)
//              t (text) sau b (binary) - default: t
//
// Inchidere
// int fclose(FILE *file);
//  Obs. fopen aloca o structura FILE, fclose o dealoca.
// Daca nu apelam fclose, avem memory leaks.
//
// Citire/ Scriere in fisiere text
// int fscanf(FILE *in, const char* format, ...)
//      ex. int n;
//          fscanf(in, "%d", &n);
//
// int fprintf(FILE *out, const char* format, ...);
//      ex. int n = 2020;
//          fprintf(out, "%d\n", n);
//
//
// Citire/ Scriere in fisiere binare
// int fread(void *p, int size_elem, int num_elem, FILE *in);
//  - functia citeste din fisierul binar in, num_elem elemente,
// fiecare element avand exact size_elem bytes, si salveaza tot
// sirul citit la adresa p
//      ex.
//          * citire un int
//          int n;
//          int num_bytes = fread(&n, sizeof(int), 1, in);
//          * citire un T
//          T t;
//          int num_bytes = fread(&t, sizeof(T), 1, in);
//
// int fwrite(void *p, int size_elem, int num_elem, FILE *out);
// - la fel ca si fread, doar ca scrie elementele de la adresa p
// in fisierul out
//      ex.
//          * scrie un int
//          int n = 2020;
//          int num_bytes = fwrite(&n, sizeof(int), 1, out);
//          * scrie un T
//          T t;
//          int num_bytes = fwrite(&t, sizeof(T), 1, out);
//

int main(void)
{
	// programul acesta nu face ceva util :D
	return 0;
}
