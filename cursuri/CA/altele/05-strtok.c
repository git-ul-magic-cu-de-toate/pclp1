// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

// la fel ca 04-strtok, insa stocarea se va face intr-un vector
// vectorul este alocat static (maxim 100 cuvinte)
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
	char *words[WMAX];

	char *delim = " .:,?\n\t;";
	char *token = strtok(p, delim);
	while (token) {
		words[n] = (char *)strdup(token);
		if (!words[n]) {
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

	return 0;
}

// Compile:
// $ make
//
// Run:
// $ valgrind ./05-strtok
// ==53674== Memcheck, a memory error detector
// ==53674== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==53674== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==53674== Command: ./05-strtok
// ==53674==
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
// ==53674==
// ==53674== HEAP SUMMARY:
// ==53674==     in use at exit: 0 bytes in 0 blocks
// ==53674==   total heap usage: 18 allocs, 18 frees, 2,124 bytes allocated
// ==53674==
// ==53674== All heap blocks were freed -- no leaks are possible
// ==53674==
// ==53674== For lists of detected and suppressed errors, rerun with: -s
// ==53674== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
//
