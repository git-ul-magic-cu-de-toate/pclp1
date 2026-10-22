// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

int main(void)
{
    // citire propozitie de la tastatura
	char p[NMAX];
	fgets(p, NMAX, stdin);
	p[strlen(p) - 1] = '\0';

    // vom folosi strtok sa spargem propozitia in cuvinte
    // numaram cate cuvinte am gasit
	int n = 0;

	const char *delim = " .:,?\n\t;!";
	char *token = strtok(p, delim);
	while (token) {
		printf("token = \"%s\"\n", token);

		++n;
		token = strtok(NULL, delim);
	}

	printf("%d cuvinte gasite\n", n);

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./04-strtok
// Gigel is Gigel all the time except when isn't Gigel, but he is still a gigel...
// token = "Gigel"
// token = "is"
// token = "Gigel"
// token = "all"
// token = "the"
// token = "time"
// token = "except"
// token = "when"
// token = "isn't"
// token = "Gigel"
// token = "but"
// token = "he"
// token = "is"
// token = "still"
// token = "a"
// token = "gigel"
// 16 cuvinte gasite
//
