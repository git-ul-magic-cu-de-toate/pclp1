#include <stdio.h>
#include <string.h>

typedef struct {
	char nume[30], grupa[5];
	double medie;
} student_t;

int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();

	student_t student[30];

	for (int i = 0; i < n; ++i) {
		fgets(student[i].nume, 30, stdin);
		student[i].nume[strlen(student[i].nume) - 1] = '\0';

		scanf("%s", student[i].grupa);
		getchar();

		scanf("%lf", &student[i].medie);
		getchar();
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (strcmp(student[i].nume, student[j].nume) > 0) {
				student_t tmp;
				tmp = student[i];
				student[i] = student[j];
				student[j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%s\t%s\t%lf\n", student[i].nume, student[i].grupa, student[i].medie);
	}

	return 0;
}