// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

void sscanf_example1(void)
{
	char msg[NMAX] = "ana 1";

	char name[NMAX];
	int age;

	sscanf(msg, "%s %d", name, &age); // citeste datele din msg
									  // in format <left> space <right>
									  // <left> este salvat sir in name
									  // <right> este salvat ca int in age
	printf("%s %d\n", name, age);
}

void sscanf_example2(void)
{
	char msg[NMAX] = "ana 123 A B";

	char name[NMAX];
	int age;
	char a, b;

	sscanf(msg, "%s %d%c%c", name, &age, &a, &b);
	printf("name = \"%s\" age = %d a = '%c' b = '%c'\n", name, age, a, b);
}

int main(void)
{
	sscanf_example1();
	sscanf_example2();
	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./08-format
// ana 1
// name = "ana" age = 123 a = ' ' b = 'A
//
