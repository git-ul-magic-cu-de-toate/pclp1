// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

int main(void)
{
    // se citeste dimensiune unui sir de caractere
    // pentru a se prealoca dinamic memoria
	// int n;
	// scanf("%d", &n);
	char buffer[NMAX];
	scanf("%s", buffer);
	int n = strlen(buffer);
	printf("%s\n", buffer);

    // se va aloca loc si pentru '\0'
	char *s = (char *)malloc((n + 1) * sizeof(char));
	if (!s) {
		return -1;
	}
	strcpy(s, buffer);
	printf("%s (strlen => %lu)\n", s, strlen(s));

	free(s);
	return 0;
}

// Compile:
// $ make
//
// Run and check:
// $./02-alloc
// 5
// gigel
// gigel (strlen => 5)
//
// $ valgrind ./02-alloc
// ==53042== Memcheck, a memory error detector
// ==53042== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==53042== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==53042== Command: ./02-alloc
// ==53042==
// 9
// not_gigel
// not_gigel (strlen => 9)
// ==53042==
// ==53042== HEAP SUMMARY:
// ==53042==     in use at exit: 0 bytes in 0 blocks
// ==53042==   total heap usage: 3 allocs, 3 frees, 2,058 bytes allocated
// ==53042==
// ==53042== All heap blocks were freed -- no leaks are possible
// ==53042==
// ==53042== For lists of detected and suppressed errors, rerun with: -s
// ==53042== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
//
