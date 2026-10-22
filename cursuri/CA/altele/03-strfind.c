// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

int main(void)
{
    // se citeste o propozitie de la tastatura
	char p[NMAX];
	fgets(p, NMAX, stdin);
	p[strlen(p) - 1] = '\0'; // elmininam '\n' // "are are mere si are si pere"

    // se citeste un alt cuvant
	char word[NMAX];
	scanf("%s", word);

    // se va afisa toate aparitiile lui word in p
	char *str = strstr(p, word);
	while (str) {
		printf("pos = %d\n", (int)(str - p));
		str = strstr(str + 1, word);
	}

	return 0;
}

// Compile:
// $ make
//
// Run:
// ./03-strfind
// Gigel is Gigel all the time except when isn't Gigel, but he is still a gigel...
// Gigel
// pos = 0
// pos = 9
// pos = 46
//
