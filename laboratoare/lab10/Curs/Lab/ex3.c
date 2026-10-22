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
	char filename[NAME_LEN] = "3-gigel.bin";

	FILE *out = fopen(filename, "wb");
	if (!out) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	person_t student_t[10];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int len;
		scanf("%d ", &len);
		// getchar();

		student_t[i].name = (char *)malloc(len * sizeof(char) + 1);

		fgets(student_t[i].name, len + 1, stdin);

		student_t[i].name[len] = '\0';

		scanf("%d", &student_t[i].age);

		fwrite(student_t[i].name, sizeof(char), len + 1, out);
		fwrite(&student_t[i].age, sizeof(int), 1, out);
	}

	fclose(out);

	// citire din fisier
	FILE *in = fopen(filename, "rb");
	if (!in) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	fread(&n, sizeof(int), 1, in);

	for (int i = 0; i < n; ++i) {
		int len;
		fread(&len, sizeof(int), 1, in);
		fread(student_t[i].name, sizeof(char), len + 1, in);
		fread(&student_t[i].age, sizeof(int), 1, in);

		printf("%s %d\n", student_t[i].name, student_t[i].age);

		free(student_t[i].name);
	}

	fclose(in);

	return 0;
}
