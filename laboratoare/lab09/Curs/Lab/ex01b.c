#include <stdio.h>
#include <string.h>
#define NMAX 100

int main(void)
{
	char filename[NMAX] = "intro.bin";

	// 1. DESCHIDERE (poate include si operatia de CREARE) + VERIFICARE
	FILE *out = fopen(filename, "wb");
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

	fwrite(name, sizeof(char), strlen(name) + 1, out);

	fwrite(&age, sizeof(int), 1, out);

	// 3. INCHIDERE (love your ponies)
	fclose(out);

	// 4. DESCHIDERE Read Binary
	FILE *in = fopen(filename, "rb");
	if (!in) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	fread(name, sizeof(char), strlen(name) + 1, in);

	fread(&age, sizeof(int), 1, in);

	printf("%s %d\n", name, age);

	fclose(in);

	return 0;
}
