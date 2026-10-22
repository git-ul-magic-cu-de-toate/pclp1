//  Scrieti un program C care primeste argumente in linia de comanda.
// Acesta trebuie sa respecte urmatoarele reguli.
// * Numele executabilului va fi gigel.
// * Primeste cel putin doua argumente in linia de comanda.
//   In caz contrar, se va afisa la stderr mesajul "Gigele, cel putin doua!"",
//  iar programul se va termina cu codul de iesire -2.
//
// * Lista de argumente reprezinta un sir de numere naturale (unsigned int).
// Se cere sortarea listei folosind functia qsort .
// Daca lista de argumente contine stringuri care nu reprezinta numere intregi fara semn,
// se va afisa la stderr mesajul "Gigele, da-mi numere naturale!".
// In acest caz, programul va iesi cu valoarea INT_MIN.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *a_ptr, const void *b_ptr)
{
	int a = * (const int *)a_ptr;
	int b = * (const int *)b_ptr;

    // aici comparam a cu b
    //
    // a - b == 0 <=> a == b
    // a - b < 0  <=> a < b
    // a - b > 0  <=> a > b
	return a - b;
}

int is_positive_integer(char *s)
{
	int len = strlen(s);
	if (s[0] == '+') {
		++s;
		--len;
	}

	for (int i = 0; i < len; ++i) {
		if (s[i] < '0' || s[i] > '9') {
			return 0;
		}
	}

	return 1;
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		fprintf(stderr, "Gigele, cel putin doua!\n");
		return -2;
	}

	int n = argc - 1;
	int *v = (int *)malloc(n * sizeof(int));
	if (!v) {
		fprintf(stderr, "pony\n");
		return -1;
	}

	for (int i = 1; i < argc; ++i) {
		// argv[i] e numar natural -> v[i - 1]
		if (!is_positive_integer(argv[i])) {
			fprintf(stderr, "Gigele, da-mi numere naturale!\n");
			free(v);
			return -13;
		}

		v[i - 1] = atoi(argv[i]);
	}

	qsort(v, n, sizeof(int), cmp_int);

	for (int i = 0; i < n; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");

	free(v);

	return 0;
}
