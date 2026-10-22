// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <string.h>
#define NMAX 100

unsigned int mystrlen(const char * s)
{
	unsigned int cnt = 0;
	// while (*s != '\0') {
	while (*s) {
		++cnt;
		++s;
	}
	
	return cnt;
}

unsigned int count_alpha(const char * s)
{
	unsigned int cnt = 0;
	while (*s) {
		if ('a' <= *s && *s <= 'z') {
			++cnt;
		}

		++s;
	}

	// int len = strlen(s);
	// for (int i = 0; i < len; ++i) {
	// 	if ('a' <= s[i] && s[i] <= 'z') {
	// 		++cnt;
	// 	}
	// }
	
	return cnt;
}

void sample_str(void)
{
    // doua modalitati de initializare a unui vector cu sirul "ana"
	char a[16] = {'a', 'n', 'a'}; // NU este un C-string
	// char b[NMAX] = {'a', 'n', 'a', '\0'}; // este un C-string
	char b[NMAX] = "ana";  // char *b

	printf("a = %s\n", a);
	printf("b = %s\n", b);

    // citire de la tastatura
	char c[NMAX];
	// scanf("%s", c);
	fgets(c, NMAX, stdin); // gets
	// puts(c);
	printf("c = $%s$\n", c);
	int len = strlen(c);
	printf("len = %d\n", len);

	c[ len - 1 ] = '\0';
	printf("c = $%s$\n", c);
	len = strlen(c);
	printf("len = %d\n", len);
}

void crash_example(void)
{
    // alocam si sa initializam un string
	char x[NMAX] = "ana_x";

    // y va pointa catre un string constant
	char *y = "hai steaua";
	y[0] = 'x';

	printf("%s %s\n", x, y);
	x[0] = 'i'; // permis
	y[0] = 'i'; // nu este permis, intrucat y pointeaza
				// catre o zona constanta
	printf("%s %s\n", x, y);
}

int main(void)
{
	printf("%d\n", mystrlen(""));
	printf("%d\n", strlen(""));

	printf("%d\n", mystrlen("ana"));
	printf("%d\n", strlen("ana"));

	// sample_str();
    // crash_example();
	return 0;
}

// TODO: man string.h

// Compile:
// $ make
//
// Run:
// $ ./01-intro
// a = ana
// b = ana
// gigel
// c = gigel
//
// Homework: Run crash_example()
//
