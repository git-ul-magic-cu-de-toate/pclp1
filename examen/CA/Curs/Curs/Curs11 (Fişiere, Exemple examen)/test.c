/* Programarea Calculatoarelor CA, 2022-2023
 *
 *	Program care realizeaza copierea unui fisier text.
 *
 */

#include <stdio.h>

#define FILENAME_LENGTH 100

unsigned long file_size(char *const file_name) {
	FILE *my_file;
	unsigned long f_size;
	if ((my_file = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "%s nu exista.", file_name);
		return -1;
	}
	fseek(my_file, 0, SEEK_END); // SEEK_SET (+), SEEK_CUR (-/+)
	f_size = ftell(my_file);
	fclose(my_file);
	return f_size;
}

/*
unsigned long file_size_file(FILE * const my_file){
	fseek(my_file, SEEK_END, 0);
	return ftell(my_file);
}
*/

int file_copy(FILE *const source, FILE *const dest)
{
	int bytes = 0, read = 0;

	// Itereate the file character by character
	read = fgetc(source);
	while (read != EOF) {
		fputc(read, dest);
		bytes++;

		read = fgetc(source);
	}

	return bytes;
}

int main(void)
{
	FILE *copy_from, *copy_to;
	char filename_from[FILENAME_LENGTH + 1], filename_to[FILENAME_LENGTH + 1];
	int bytes_read = 0;

	printf("File to copy: ");
	scanf("%s", filename_from);

	copy_from = fopen(filename_from, "r");
	if (!copy_from) {
		fprintf(stderr, "%s", "No such file! Exiting...\n");
		return -1;
	}

	printf("Copy to: ");
	scanf("%s", filename_to);

	copy_to = fopen(filename_to, "w");
	if (!copy_to) {
		fprintf(stderr, "Cannot open/create %s file! Exiting...\n",
				filename_to);
		return -1;
	}

	bytes_read = file_copy(copy_from, copy_to);

	fclose(copy_from);
	fclose(copy_to);

	printf("Copied %d bytes.\n", bytes_read);
	printf("%ld\n", file_size(filename_to));

	return 0;
}

/*
 *
 *	compile: gcc 01-copy_text.c -o copy_text
 *	run: ./copy_text
 *
 *	Input:
 *		File to copy: 01-copy_text.c
 *		Copy to: test.c
 *
 *	Output:
 *		Copied N bytes.
 *
 */
