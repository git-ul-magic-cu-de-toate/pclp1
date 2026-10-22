// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

// functie de interschimbare pentru 2 variabile de tipul int
// => pointer la int <=> int *
void swap_int(int *a, int *b)
{
	int tmp = *a; // are tipul int pt ca *a/*b sunt 2 numere int!!!
	*a = *b;
	*b = tmp;
}

void test_swap_int(void)
{
	int a = 3, b = 5;
	printf("before: a = %d b = %d\n", a, b);

	// pasez pointeri catre VARIABILE ca sa poata fi modificate in functie
	// iar la revenirea in main sa se pastreze modificarile
	swap_int(&a, &b);

	printf("after : a = %d b = %d\n", a, b);
	printf("\n");
}

// functie de interschimbare pentru 2 variabile de tipul int * (pointer la int)
// => pointer la pointer la int <=> int **
void swap_ptr_int(int **pa, int **pb)
{
	int *tmp = *pa; // are tipul int* pt ca *a/*b sunt 2 pointeri
	*pa = *pb;
	*pb = tmp;
}

void test_swap_ptr_int(void)
{
	int a = 3, b = 5;
	int *pa = &a, *pb = &b;
	printf("before: pa = %p pb = %p\n", pa, pb);

	// pasez pointeri catre VARIABILE  (da, pa si pb sunt 2 variabile si ele!!!)
	// ca sa poata fi modificate in functie
	// iar la revenirea in main sa se pastreze modificarile
	swap_ptr_int(&pa, &pb);

	printf("after : pa = %p pb = %p\n", pa, pb);
	printf("\n");
}

int main(void)
{
	test_swap_int();
	test_swap_ptr_int();
	return 0;
}
