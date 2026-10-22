#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//functie de comparare generala
typedef int (*PCMP)(void *first, void *second);

//functie de swap generala
typedef void (*PSWAP)(void *x, void *y);

//functie polimorfica de cautare binara
void *my_cb(void *key, void *array, int n, int dim, PCMP cmp) {
	char *min, *max, *med, res_cmp;
	min = (char *)array;
	max = (char *)array + (n - 1) * dim;
	while (min <= max) {
		med = min +(max - min) / dim / 2 * dim;
		res_cmp = cmp(key, med);
		if (!res_cmp) {
			return med;
		} else {
			if (res_cmp < 0) {
				max = med - dim;
			} else {
				min = med + dim;
			}
		}
	}
	return NULL;
}

void swapint(void *X, void *Y) {
	int aux, *x, *y;
	x = (int *)X;
	y = (int *)Y;
	aux = *x;
	*x = *y;
	*y = aux;
}

void sort(void *array, int n, int dim, PCMP cmp, PSWAP swap){
	char *p;
	int sorted = 0;
	while (!sorted) {
		sorted = 1;
		for (p = (char *) array; p < (char *)array + (n - 1) * dim; p += dim) {
			if (cmp(p, p + dim) > 0) {
				swap(p, p + dim);
				sorted = 0;
			}
		}
	}
}

int cmpint(void *first, void *second) {
	return *(int *)first - *(int*)second;
}

int cmpdouble(void *first, void *second) {
	return *(double *)first - *(double*)second;
}


// char *key, char **element
int cmpstring(void *first, void *second) {
	return strcmp((char *)first, (char *) *(int *)second );
}

void test_string(int argc, char **argv) {
	char *key = strdup("key");
	int *found;
	found = (int *)my_cb(key, argv, argc, sizeof(char *), cmpstring);

	if (found  != NULL) {
		char *s = strdup((char *)*found);
		printf("rez = %s\n", s);
	} else {
		printf("NU\n");
	}
}

void test_int(int argc, char **argv) {
	int key = 10;
	int i , n;
	n = argc - 1;
	int *v = malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		v[i] = atoi(argv[i]);
	}
	sort(v, n, sizeof(int), cmpint, swapint);
	for (i = 0; i < n; i++) {
		printf("%d%c", v[i] , i < n - 1 ? ' ' :'\n');
	}
	int *x = my_cb(&key, v, n, sizeof(int), cmpint);
	printf("%d\n", (*x));
}

void test_double(int argc, char **argv) {
	double key = 10.41;
	int i , n;
	n = argc - 1;
	double *v = malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		v[i] = atof(argv[i]);
	}
	double *x = my_cb(&key, v, n, sizeof(double), cmpint);
	printf("%lf\n", (*x));
}
int main(int argc, char *argv[]) {
	int gigel = atoi(argv[1]);

	switch(argc) {
		case 1: // strings
			test_string(argc-2, &argv[2]);
			break;
		case 2: // strings
			test_int(argc-2, &argv[2]);
			break;
		case 3: // strings
			test_double(argc-2, &argv[2]);
			break;
		default:
			break;
	}
	return 0;
}
