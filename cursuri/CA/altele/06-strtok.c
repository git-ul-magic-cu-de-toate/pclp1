// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

// la fel ca 04-strtok, insa stocarea se va face intr-un vector
// vectorul este alocat dinamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000
#define WMAX 100

int main(void)
{
    // citim fraza
	char p[NMAX];
	fgets(p, NMAX, stdin);

    // in words salvam cuvintele, cu n le numaram
	int n = 0;
	char **words = NULL;

	char *delim = " .:,?\n\t;";
	char *token = strtok(p, delim);
	while (token) {
		// dorim sa folosim words[n]
		// reallocam vectorul a.i. sa existe elementul respectiv
		words = (char **)realloc(words, (n + 1) * sizeof(char *));
		if (!words) {
			// malloc failed
			return -1;
		}

		words[n] = (char *)strdup(token);
		if (!words[n]) {
			// strdup -> malloc -> return NULL
			return -1;
		}

		++n;
		token = strtok(NULL, delim);
	}

	printf("n = %d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%s\n", words[i]);
		free(words[i]);
	}
	free(words);

	return 0;
}

// Compile:
// $ make
//
// Run:
// valgrind ./06-strtok
// ==53759== Memcheck, a memory error detector
// ==53759== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==53759== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==53759== Command: ./06-strtok
// ==53759==
// Gigel is Gigel all the time except when isn't Gigel, but he is still a gigel...
// n = 16
// Gigel
// is
// Gigel
// all
// the
// time
// except
// when
// isn't
// Gigel
// but
// he
// is
// still
// a
// gigel
// ==53759==
// ==53759== HEAP SUMMARY:
// ==53759==     in use at exit: 0 bytes in 0 blocks
// ==53759==   total heap usage: 34 allocs, 34 frees, 3,212 bytes allocated
// ==53759==
// ==53759== All heap blocks were freed -- no leaks are possible
// ==53759==
// ==53759== For lists of detected and suppressed errors, rerun with: -s
// ==53759== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
//
