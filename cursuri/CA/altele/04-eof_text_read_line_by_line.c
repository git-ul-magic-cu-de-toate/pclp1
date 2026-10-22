// Copyright 2020 Sabina Horincar (sabina.horincar@gmail.com)

#include <stdio.h>
#include <string.h>

#define LINEMAX 1000

// citim fiecare linie din fisier
int main(void)
{
	FILE *file = fopen("04-eof_text_read_line_by_line.txt", "rt");
	if (!file) {
		return -1;
	}

	int n = 0;
	char line[LINEMAX + 1];

    // atata timp cat fgets a reusit sa citeasca linia continui.
	// Daca s-a teminat fisierul, fgets returneaza NULL
	while (fgets(line, LINEMAX, file)) {
		// cum scoatem enterul de la final? suprascriem cu \0
		line[strlen(line) - 1] = '\0';

		// fgets citeste cu tot cu enter
		printf("$%s$\n", line);
		++n;
	}
	printf("\n");
	printf("n = %d\n", n);

	fclose(file);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ cat 04-eof_text_read_line_by_line.txt
// Gigel are multe mere si pere.
// Si Sabina vrea si ea un              mar.
// Dar nu are voie     pentru ca toate i-au fost promise lui Darius.
//
// Darius este generos si ii da Sabinei un mar.
// Ieeei.
// haha.
// (note: may have empty/blank lines)
//
// $ ./04-eof_text_read_line_by_line
// $Gigel are multe mere si pere.$
// $Si Sabina vrea si ea un              mar.$
// $Dar nu are voie     pentru ca toate i-au fost promise lui Darius.$
// $$
// $Darius este generos si ii da Sabinei un mar.$
// $Ieeei.$
// $haha.$
//
// n = 7
//
// (note: $ was used to quote a line)
//
