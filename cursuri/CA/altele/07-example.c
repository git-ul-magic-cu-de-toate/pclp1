// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	printf("sizeof(int *)        = %lu\n", sizeof(int *));
	printf("sizeof(char *)       = %lu\n", sizeof(char *));
	printf("sizeof(short int *)  = %lu\n", sizeof(short int *));
	printf("sizeof(void *)       = %lu\n", sizeof(void *));
	printf("Dimensiuniea unui pointer e aceeasi!!! (pe acelasi sistem)"
		   " Pentru ca el contine o adresa din memorie,"
		   "care in esenta e un NUMAR (in hexa), pe 32 de biti.\n");

	return 0;
}
