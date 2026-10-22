#include <stdio.h>
#include <string.h>
#define NAME_LEN 31

typedef struct __attribute__((__packed__)) {
	char name[NAME_LEN];
	int age;
} person_t;

int main(void)
{
	char filename[NAME_LEN] = "1-gigel.bin";

	FILE *out = fopen(filename, "wb");
	if (!out) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	person_t student_t = { 0 };

	fgets(student_t.name, NAME_LEN, stdin);

	student_t.name[NAME_LEN] = '\0';

	scanf("%d", &student_t.age);

	fwrite(&student_t, sizeof(person_t), 1, out);

	fclose(out);

	// citire din fisier
	FILE *in = fopen(filename, "rb");
	if (!in) {
		fprintf(stderr, "Cannot open %s\n", filename);
		return -1;
	}

	fread(&student_t, sizeof(student_t), 1, in);

	printf("%s%d\n", student_t.name, student_t.age);

	fclose(in);

	return 0;
}
