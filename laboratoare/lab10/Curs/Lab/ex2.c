#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_LEN 31

typedef struct {
	char *name;
	int age;
} person_t;

int main(void)
{
	char filename[NAME_LEN] = "2-gigel.bin";

	FILE *out = fopen(filename, "wb");
	if (!out) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	person_t student_t;

	int n;
	scanf("%d ", &n);
	// getchar();

	student_t.name = (char *)malloc(n * sizeof(char) + 1);

	fgets(student_t.name, n + 1, stdin);

	student_t.name[n] = '\0';

	scanf("%d", &student_t.age);

	fwrite(student_t.name, sizeof(char), n + 1, out);
	fwrite(&student_t.age, sizeof(int), 1, out);

	fclose(out);

	// citire din fisier
	FILE *in = fopen(filename, "rb");
	if (!in) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	fread(student_t.name, sizeof(char), n + 1, in);
	fread(&student_t.age, sizeof(int), 1, in);

	printf("%s %d\n", student_t.name, student_t.age);

	free(student_t.name);
	fclose(in);

	return 0;
}
