// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 100

// man stdio
//
// int ftell(FILE* file);
//   returneaza pozitia cursorului (indexarea incepe de la zero)
//
// int fseek(FILE* file, int offset, int whence)
//   repozitioneaza cursorul din file la pozitia whence + offset
// * whence:
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
//          cursor = SEEK_END + 0
//          (pasi: pozitioneaza cursorul la sfarsitul fisierului,
//              apoi inca 0 pozitii)
//
//      fseek(file, n, SEEK_CUR); // muta cursorul la n pozitii inainte
//          cursor = SEEK_CUR + n
//          (pasi: pozitioneaza cursorul la pozitia curenta in fisierului,
//              apoi inca n pozitii inainte - spre final)
//
//      fseek(file, -n, SEEK_CUR); // muta cursorul la n pozitii inainte
//          cursor = SEEK_CUR - n
//          (pasi: pozitioneaza cursorul la pozitia curenta in fisierului,
//              apoi inca n pozitii inapoi - spre inceput)
//

int sizeof_file(char *filename)
{
	// deschidere fisier de intrare
	// observatie: nu conteaza modul!
	FILE *file = fopen(filename, "rt");

	// verific daca fisierul a fost deschis cu succes
	if (!file) {
		return -1;
	}

	fseek(file, 0, SEEK_END); // ma pozitionez la sfarsit
	// acum cursorul este dupa ultimul caracter
	// deci ftell imi va spune pozitia, care este echivalenta
	// cu numarul de bytes
	int bytes_count = ftell(file);

	// inchid fisierul
	fclose(file);

	return bytes_count;
}

int main(int argc, char **argv)
{
	// numele fisierului de intrare este citit de la STDIN
	char *filename = argv[1];

	int sz = sizeof_file(filename);
	if (sz < 0) {
		fprintf(stderr, "ERROR: Can't open file %s", filename);
		return -1;
	}

	printf("File '%s' has %d bytes\n", filename, sz);

	return 0;
}

// Compile:
// $ make
//
// Run & check:
// $./08-file_size
// 08-file_size.c
// File '08-file_size.c' has 997 bytes
// $ ls -l 08-file_size.c
// -rw-rw-r-- 1 darius 997 Dec 10 00:33 08-file_size.c
//
// $./08-file_size
// ./08-file_size
// File './08-file_size' has 17184 bytes
// $ ls -l ./08-file_size
// -rwxrwxr-x 1 darius 17184 Dec 10 00:33 ./08-file_size
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
