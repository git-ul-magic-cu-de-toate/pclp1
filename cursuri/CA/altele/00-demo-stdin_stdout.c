// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 100

int main(void)
{
	int x;
	char s[NMAX];
	scanf("%d%s", &x, s);
	printf("%d %s\n", x, s);

	return 0;
}

// TODO: Demo recapitulare citire de la STDIN si afisare la STDOUT.
// man scanf
// man printf