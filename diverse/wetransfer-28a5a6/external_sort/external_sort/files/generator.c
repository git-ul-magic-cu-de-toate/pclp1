#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TYPE int

char random_letter() {
	return (char)('a' + rand() % 26);
}

int main(int argc, char *argv[]) {
	char  file_name[100], s[100];
	srand(time(NULL));

	fprintf(stderr, "sizeof(TYPE) = %d\n", (int) sizeof(TYPE));

	for (int t = 1; t <= 10; t++) {
		int len = rand() % 6  + 1;
		for (int j = 0; j < len; j++) {
			file_name[j] = random_letter();
		}
		file_name[len] = '\0';

		strcpy(s, file_name);
		strcat(file_name, ".bin");
		strcat(s, ".txt");
		printf("generate => %s\n",file_name);

		FILE *fbin, *ftext;
		fbin = fopen(file_name, "wb");
		ftext = fopen(s, "w");

		int n = rand() % 15;
		TYPE last = -1;
		for (int i = 1; i <= n; i++) {
			TYPE x = rand() % 19;
			while (x < last) {
				x =rand() % 19;
			}
			last = x;

			fwrite(&x, sizeof(TYPE), 1, fbin);
			fprintf(ftext, "%d ", (int) x);
		}
		fprintf(ftext, "\n");
		
		fclose(fbin);
		fclose(ftext);
	}

	return 0;
}