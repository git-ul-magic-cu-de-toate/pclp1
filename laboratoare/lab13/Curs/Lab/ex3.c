#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[50];
	int grades[100];
} student_t;

#define SWAP(x, y) {\
	char tmp[sizeof(x)];\
	memcpy(tmp, &x, sizeof(x));\
	memcpy(&x, &y, sizeof(x));\
	memcpy(&y, tmp, sizeof(x));\
}

void test_int()
{
	// interschimbare variabile de tip int
	int xi = 2, yi = 3;
	printf("%d %d\n", xi, yi);
	SWAP(xi, yi);
	printf("%d %d\n", xi, yi);
}

void test_char()
{
	// interschimbare variabile de tip char
	char xc = 'A', yc = 'B';
	printf("%c %c\n", xc, yc);
	SWAP(xc, yc);
	printf("%c %c\n", xc, yc);
}

void test_ptr()
{
	// interschimbare variabile de tip char*
	char *xs = "GIGEL", *ys = "NOT GIGEL";
	printf("%s %s\n", xs, ys);
	SWAP(xs, ys);
	printf("%s %s\n", xs, ys);
}

void test_struct()
{
	// interschimbare variabile de tip struct
	student_t xstud, ystud;
	// citire xstud, ystud
	// afisare xstud, ystud
	SWAP(xstud, ystud);
	// afisare xstud, ystud
}

int main()
{
	test_int();
	test_char();
	test_ptr();
	test_struct();

	return 0;
}
