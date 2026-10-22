#include <stdio.h>

void my_memcpy(void *dst, const void *src, int num)
{
	char *d = (char *)dst;
	const char *s = (const char *)src;

	for (int i = 0; i < num; ++i) {
		d[i] = s[i];
	}
}

int main(void)
{
	// // exemplu cu int
	// int a = 123; // initializat
	// int b; 	     // neinitializat
	// my_memcpy(&b, &a, sizeof(a));
	// // print b
	// printf("%d\n", b);

	// // exemplu cu vector de int
	// int src[100] = { 1, 2, 3 }; // initializat
	// int dst[100];               // neinitializat
	// my_memcpy(dst, src, sizeof(src));
	// // afisare elemente din vector destinatie
	// for (int i = 0; i < 3; ++i) {
	// 	printf("%d ", dst[i]);
	// }
	// printf("\n");

	// exemplu cu vector de double
	int n;
	double src[100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &src[i]);
	}
	// scanf n, src => initializare
	double dst[100]; // neinitializat
	my_memcpy(dst, src, n * sizeof(double));
	// afisare elemente din vector destinatie

	for (int i = 0; i < n; ++i) {
		printf("%lf ", src[i]);
	}
	printf("\n");

	return 0;
}