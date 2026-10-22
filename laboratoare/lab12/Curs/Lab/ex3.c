#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*cmp_t)(const void *, const void *);

void sort(void *v, size_t num, size_t size, cmp_t cmp);
void swap_polymorphic(void *a, void *b, int n_bytes);
int cmp_int(const void *first, const void *second);
int cmp_double(const void *first, const void *second);
int cmp_char(const void *first, const void *second);
int cmp_char_string(const void *first, const void *second);

void sort(void *v, size_t num, size_t size, cmp_t cmp)
{
	unsigned char *bytes = (unsigned char *)v;
	// La ce este util? accesăm byte-ul cu numărul i cu bytes[i],
	// iar adresa acelui bytes este expresia: bytes + i

	// Schițăm algoritmul general de sortare.
	for (size_t i = 0; i < num; ++i) {
		for (size_t j = i + 1; j < num; ++j) {
			unsigned char *array_i = bytes + i * size;     // fixăm "array[i]"
			unsigned char *array_j = bytes + j * size;     // fixăm "array[j]"

			if ((*cmp)(array_i, array_j) > 0) {                       // simulam "array[i] > array[j]"
				swap_polymorphic(array_i, array_j, size);  // facem interschimbarea elementelor
				// care incep la adresele indicare si
				// care au acelasi numar de bytes!
			}
		}
	}
}

void swap_polymorphic(void *a, void *b, int n_bytes)
{
	unsigned char *tmp = (unsigned char *)malloc(n_bytes * sizeof(unsigned char *));
	if (!tmp) {
		fprintf(stderr, "malloc failed - swap_polymorphic failed.\n");
		return;
	}

	// actual swap
	memcpy(tmp, a, n_bytes); // tmp = a;
	memcpy(a, b, n_bytes);   // a = b;
	memcpy(b, tmp, n_bytes); // b = tmp;

	free(tmp);
}

int cmp_int(const void *first, const void *second)
{
	int f = *(int *)first;
	int s = *(int *)second;

	if (f < s) {
		return -1; // f < s
	}
	if (f > s) {
		return +1; // f > s
	}
	return 0;       // f == s
}

int cmp_double(const void *first, const void *second)
{
	double f = *(double *)first;
	double s = *(double *)second;

	if (f < s) {
		return -1; // f < s
	}
	if (f > s) {
		return +1; // f > s
	}
	return 0;       // f == s
}

int cmp_char(const void *first, const void *second)
{
	char f = *(char *)first;
	char s = *(char *)second;

	if (f < s) {
		return -1; // f < s
	}
	if (f > s) {
		return +1; // f > s
	}
	return 0;       // f == s
}

int cmp_char_string(const void *first, const void *second)
{
	char *f = *(char **)first;
	char *s = *(char **)second;

	if (strcmp(f, s) < 0) {
		return -1; // f < s
	}
	if (strcmp(f, s) > 0) {
		return +1; // f > s
	}
	return 0;       // f == s
}

int main(void)
{
	char abracadabra_char[] = "abracadabra";
	double abracadabra_double[] = { 19.4, 23.6, 0.4, 7.1, 9 };
	char **abracadabra_string = (char **)malloc(3 * sizeof(char *));
	for (int i = 0; i < 3; ++i) {
		abracadabra_string[i] = (char *)malloc(10);
	}
	strcpy(abracadabra_string[0], "abra");
	strcpy(abracadabra_string[1], "cad");
	strcpy(abracadabra_string[2], "abra");
	// char abracadabra_string[3][10] = { "abra", "cad", "abra" };

	sort(abracadabra_char, strlen(abracadabra_char), sizeof(char), cmp_char);
	printf("%s\n", abracadabra_char);

	sort(abracadabra_double, 5, sizeof(double), cmp_double);
	for (int i = 0; i < 5; ++i) {
		printf("%lf ", abracadabra_double[i]);
	}
	printf("\n");

	sort(abracadabra_string, 3, sizeof(char *), cmp_char_string);
	for (int i = 0; i < 3; ++i) {
		printf("%s\n", abracadabra_string[i]);
	}

	return 0;
}
