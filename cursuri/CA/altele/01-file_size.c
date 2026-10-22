// Copyright 2020 Sabina Horincar (sabina.horincar@gmail.com)

// Determinarea dimensiunii unui fisier.

#include <stdio.h>
#define NMAX 100

// man stdio
//
// int ftell(FILE* file);
//   returneaza pozitia cursorului (indexarea incepe de la zero)
//
// int fseek(FILE* file, int offset, int whence)
//   repozitioneaza cursorul din file la pozitia whence +/- offset
// * whence are doar 3 valori posibile:
//          SEEK_SET (inceputul fisierului)
//          SEEK_CUR (pozitia curenta in fisier)
//          SEEK_END (sfarsitul fisierului)
// * offset: numar de pozitii cu care se deplaseaza cursorul
//
//      ex.
//      fseek(file, 0, SEEK_SET); // muta cursorul la inceput
//          cursor = SEEK_SET + 0
//          (pasi: pozitioneaza cursorul la inceputul fisierului,
//              apoi inca 0 pozitii)
//
//      fseek(file, 0, SEEK_END); // muta cursorul la final
//          cursor = SEEK_END - 0
//          (pasi: pozitioneaza cursorul la sfarsitul fisierului,
//              apoi inca 0 pozitii)
//
//      fseek(file, n, SEEK_END); // muta cursorul la n pozitii inainte de final
//          cursor = SEEK_END - n
//          (pasi: pozitioneaza cursorul la sfarsitul fisierului,
//              apoi inca n pozitii inapoi)

//      fseek(file, n, SEEK_CUR); // muta cursorul la n pozitii inainte
//          cursor = SEEK_CUR + n
//          (pasi: pozitioneaza cursorul la pozitia curenta in fisierului,
//              apoi inca n pozitii inainte - spre final)
//
//      fseek(file, -n, SEEK_CUR); // muta cursorul la n pozitii inapoi
//          cursor = SEEK_CUR - n
//          (pasi: pozitioneaza cursorul la pozitia curenta in fisierului,
//              apoi inca n pozitii inapoi - spre inceput)
//

size_t sizeof_file(char *filename)
{
	// deschidere fisier de intrare
	// observatie: nu conteaza modul!
	FILE *file = fopen(filename, "rt");

	// verific daca fisierul a fost deschis cu succes
	if (!file) {
		fprintf(stderr, "ERROR: Can't open file %s", filename);
		return -1;
	}
	// ma pozitionez la sfarsit
	fseek(file, 0, SEEK_END);

	// acum cursorul este dupa ultimul caracter
	// ftell returneaza spune pozitia, care este echivalenta cu numarul de bytes
	size_t bytes_count = ftell(file);

	// inchid fisierul
	fclose(file);

	return bytes_count;
}

int main(void)
{
    // numele fisierului de intrare este citit de la STDIN
	char filename[NMAX];
	scanf("%s", filename);

	size_t sz = sizeof_file(filename);
	printf("File '%s' has %zu bytes\n", filename, sz);

	return 0;
}

// Compile:
// $ make
//
// Run & check:
// $ ./01-file_size
// 01-file_size.c
// File '01-file_size.c' has 997 bytes
// $ ls -l 01-file_size.c
// -rw-rw-r-- 1 xxx 997 Dec 10 00:33 01-file_size.c
//
// $ ./01-file_size
// ./01-file_size
// File './01-file_size' has 17184 bytes
// $ ls -l ./01-file_size
// -rwxrwxr-x 1 xxx 17184 Dec 10 00:33 ./01-file_size
//
// Homework:
// - Make a bash command:
//      * change the main prototype to: int main(int argc, char **argv)
//      * change filename to: char *filename = argv[1]
//      * run the program as: ./08-file_size <filename>
//          examples:
//              $ ./08-file_size 08-file_size.c
//              File '08-file_size.c' has 2888 bytes
//
//              $ ./08-file_size 08-file_size
//              File '08-file_size' has 17088 bytes
//
//              $ ./08-file_size ../../../lab/lab01/demo/hello/hello.c
//              File '../../../lab/lab01/demo/hello/hello.c' has 2109 bytes
//
// - Change the function in order to receive a FILE *in (an already open file).
//
