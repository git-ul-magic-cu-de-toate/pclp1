#include <stdio.h>
#include <string.h>
#define NMAX 100

int main(void)
{
	char filename[NMAX] = "intro.txt";

	// 1. DESCHIDERE (poate include si operatia de CREARE) + VERIFICARE
	FILE *out = fopen(filename, "wt");
	if (!out) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	// 2. UTILIZARE (citire/scriere/mutare in fisier):
	char name[NMAX];
	int age;

	fgets(name, NMAX, stdin);
	name[strlen(name) - 1] = '\0';

	scanf("%d", &age);

	fprintf(out, "%s %d\n", name, age);

	fclose(out);
	// 3. INCHIDERE (love your ponies)

	FILE *in = fopen(filename, "rt");

	fclose(in);

	return 0;
}
