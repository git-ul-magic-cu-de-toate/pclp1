// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

void sprintf_example(void)
{
	char msg[NMAX];

	printf("%s-%d\n", "ana", 1);     // afiseaza la stdout "ana-1"
	sprintf(msg, "%s-%d", "ana", 1); // salveaza in msg    "ana-1"

	printf("msg: \"%s\"\n", msg);    // putem afisa msg pentru verificare
}

void snprintf_example(void)
{
	char msg[NMAX];

	printf("%s-%d\n", "ana", 1);             // afiseaza la stdout "ana-1"
	snprintf(msg, NMAX, "%s-%d", "ana", 1);  // salveaza in msg    "ana-1"

	printf("msg: \"%s\"\n", msg); // putem afisa msg pentru verificare
}

int main(void)
{
	sprintf_example();
	snprintf_example();
	return 0;
}

// Compile:
// $ make
//
// Run:
// $./07-format
// ana-1
// msg: "ana-1"
// ana-1
// msg: "ana-1"
//
