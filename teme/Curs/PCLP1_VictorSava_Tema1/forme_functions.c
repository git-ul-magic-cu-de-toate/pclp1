// 311CA Sava Victor
#include <stdio.h>

// function for absolute value
int absolute(int n)
{
	if (n < 0) {
		return -n;
	}

	return n;
}

// function that displays a square turned to an angle that is multiple of 90
// which is a square
void print_square_multiple_of_90(int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			printf("*");
		}
		printf("\n");
	}
}

// function that displays a square turned to an angle that is multiple of 45
// which is a rhombus
void print_square_multiple_of_45(int size)
{
	int length = 2 * size - 1;

	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if ((i + j > size - 2) &&
				(i + j < 3 * size - 2) &&
				(absolute(i - j) < size)) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// function that displays a square
// normalizes the rotation angle to be between 0 and 360
// if the angle is 90, display a square
// if the angle is 45, display a rhombus
void print_square(void)
{
	// declare size and rotation angle of the square
	int size, angle;

	// read size and angle
	scanf("%d%d", &size, &angle);

	// Check if size is not between [1, 100]
	if (size < 1 || size > 100) {
		printf("Unsupported size to display shape\n");
		return;
	}

	// Check if rotation angle is not multiple of 45
	if (angle % 45 != 0) {
		printf("Unsupported angle to display shape\n");
		return;
	}

	// normalize the rotation angle to be between 0 and 360
	angle = (angle % 360 + 360) % 360;

	// print square first then return because multiples of 90
	// are also multiples of 45
	if (angle % 90 == 0) {
		print_square_multiple_of_90(size);

		return;
	}

	// print rhombus
	if (angle % 45 == 0) {
		print_square_multiple_of_45(size);

		return;
	}
}

// function that displays a rectangle
void print_rectangle(void)
{
	// declare length and width of a rectangle
	int length, width;

	// read length and width
	scanf("%d%d", &length, &width);

	// check if length or width is < 1
	if (length < 1 || width < 1) {
		printf("Unsupported size to display shape\n");
		return;
	}

	// print the rectangle
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < length; ++j) {
			printf("*");
		}
		printf("\n");
	}
}

// function that displays a right triangle rotated by 0 degrees
void print_right_triangle_angle_0(int length)
{
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			printf("*");
		}
		printf("\n");
	}
}

// function that displays a right triangle rotated by 90 degrees
void print_right_triangle_angle_90(int length)
{
	for (int i = length - 1; i >= 0; --i) {
		for (int j = 0; j < i + 1; ++j) {
			printf("*");
		}
		printf("\n");
	}
}

// function that displays a right triangle rotated by 180 degrees
void print_right_triangle_angle_180(int length)
{
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (i <= j) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// function that displays a right triangle rotated by 270 degrees
void print_right_triangle_angle_270(int length)
{
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (i + j >= length - 1) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// function that displays a right triangle
// normalizes the rotation angle to be between 0 and 360
// displays the triangle based on the rotation angle
// angle 0: left and bottom sides
// angle 90: left and top sides
// angle 180: right and top sides
// angle 270: right and bottom sides
void print_right_triangle(void)
{
	// declare length and rotation angle of a right triangle
	int length, angle;

	// read the length and rotation angle of a right triangle
	scanf("%d%d", &length, &angle);

	// Check if the size is not between [1, 100]
	if (length < 1 || length > 100) {
		printf("Unsupported size to display shape\n");
		return;
	}

	// Check if the rotation angle is not a multiple of 90
	if (angle % 90 != 0) {
		printf("Unsupported angle to display shape\n");
		return;
	}

	// normalize the rotation angle to be between 0 and 360
	angle = (angle % 360 + 360) % 360;

	if (angle == 0) {
		print_right_triangle_angle_0(length);

		return;
	}

	if (angle == 90) {
		print_right_triangle_angle_90(length);

		return;
	}

	if (angle == 180) {
		print_right_triangle_angle_180(length);

		return;
	}

	if (angle == 270) {
		print_right_triangle_angle_270(length);

		return;
	}
}

// function that displays a cross rotated by 45 degrees
// which is a cross
void print_cross_multiple_of_90(int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (j == size / 2 || i == size / 2) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// function that displays a cross rotated by 45 degrees
// which is a plus
void print_cross_multiple_of_45(int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == j || (i + j == size - 1)) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// function that displays a cross
// normalizes the angle to be between 0 and 360
// if the angle is 90, display a +
// if the angle is 45, display an x
void print_cross(void)
{
	// declare the size and rotation angle of a cross
	int size, angle;

	// read the size and rotation angle of a cross
	scanf("%d%d", &size, &angle);

	// Check if the size is not between [1, 100] and is even
	if ((size < 1 || size > 100) || size % 2 == 0) {
		printf("Unsupported size to display shape\n");
		return;
	}

	// check if the rotation angle is not a multiple of 45
	if (angle % 45 != 0) {
		printf("Unsupported angle to display shape\n");
	}

	// normalize the angle to be between 0 and 360
	angle = (angle % 360 + 360) % 360;

	// print cross first then return because multiples of 90
	// are also multiples of 45
	if (angle % 90 == 0) {
		print_cross_multiple_of_90(size);

		return;
	}

	// print cross multiple of 45, meaning a +
	if (angle % 45 == 0) {
		print_cross_multiple_of_45(size);

		return;
	}
}

// function that displays a window
void print_window(void)
{
	// declare the size of a window
	int size;

	// read the size of a window
	scanf("%d", &size);

	// Check if the size is not between [5, 100] and is even
	if ((size < 5 || size > 100) || size % 2 == 0) {
		printf("Unsupported size to display shape\n");
		return;
	}

	// print window
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == 0 || j == 0 ||
				i == size - 1 || j == size - 1 ||
				i == size / 2 || j == size / 2) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
