// 311CA Sava Victor
#include <stdio.h>
#include "forme_functions.h"

int main(void)
{
	// declare n - no. of shapes
	int n;

	// read n - no. of shapes
	scanf("%d", &n);

	// read n shapes and print the required message
	for (int i = 0; i < n; ++i) {
		// declare shape
		char shape;

		// read the shape
		scanf(" %c", &shape);

		// if shape is square
		if (shape == 'p') {
			print_square();
		}

		// if shape is rectangle
		if (shape == 'd') {
			print_rectangle();
		}

		// if shape is right triangle
		if (shape == 't') {
			print_right_triangle();
		}

		// if shape is a cross
		if (shape == 'c') {
			print_cross();
		}

		// if shape is a window
		if (shape == 'f') {
			print_window();
		}

		// print an endline after each shape except the last one
		if (i != n - 1) {
			printf("\n");
		}
	}

	return 0;
}
