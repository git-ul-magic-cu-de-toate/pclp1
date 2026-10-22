// SAVA Victor 311CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "march_squares_functions.h"
#include "change_pixel.h"
#include "init_contour.h"

typedef unsigned char byte_t;

// function that allocates memory to a 2d array
// function used for grid and march_grid arrays
byte_t **alloc_grid(int height, int width)
{
	byte_t **grid;
	grid = (byte_t **)malloc(height * sizeof(byte_t *));

	for (int i = 0; i < height; i++) {
		grid[i] = malloc(width * sizeof(byte_t));
	}

	return grid;
}

// function that frees a 2d array (grid and march_grid)
void free_grid(byte_t **grid, int height)
{
	for (int i = 0; i < height; ++i) {
		free(grid[i]);
	}

	free(grid);
}

// function that allocates memory to a 3d array
// function used for a 3d array with the name pixel
byte_t ***alloc_pixel(int height, int width)
{
	byte_t ***pixel;

	// allocate 3-dimensional array named pixel
	pixel = (byte_t ***)malloc(height * sizeof(byte_t **));
	if (!pixel) {
		// error
		exit(1);
	}

	for (int i = 0; i < height; i++) {
		pixel[i] = (byte_t **)malloc(width * sizeof(byte_t *));
		if (!pixel[i]) {
			// error
			// free everything used up to this point
			free_pixel(pixel, i, width);
			exit(1);
		}

		for (int j = 0; j < width; j++) {
			pixel[i][j] = (byte_t *)malloc(3 * sizeof(byte_t));
			if (!pixel[i][j]) {
				// error
				// free everything used up to this point
				free_pixel(pixel, i, j);
				exit(1);
			}
		}
	}

	return pixel;
}

// function that frees a 3d array (for pixel)
void free_pixel(byte_t ***pixel, int height, int width)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			free(pixel[i][j]);
		}
		free(pixel[i]);
	}
	free(pixel);
}

// function that reads the header and RGB values of the ppm image
// and returns by reference the values for height, width, max color
// and the values read in the 3d array by reference
int read(char format[5], int *height, int *width, int *max_color,
		 byte_t ****pixel)
{
	scanf("%s", format);

	if (strcmp(format, "P3")) {
		printf("Eroare: trebuie sa fie P3\n");
		return 0;
	}

	scanf("%d%d%d", height, width, max_color);

	*pixel = alloc_pixel(*height, *width);

	// read pixel
	for (int i = 0; i < *height; i++) {
		for (int j = 0; j < *width; j++) {
			for (int k = 0; k < 3; k++) {
				int tmp;

				// error reading pixels
				if (scanf("%d", &tmp) != 1) {
					printf("Eroare: eroare citire pixeli\n");
					free_pixel(*pixel, *height, *width);
					*pixel = NULL;
					return 0;
				}

				// error invalid value for pixel
				if (tmp < 0 || tmp > *max_color) {
					printf("Eroare: valoare pixel necorespunzatoare\n");
					free_pixel(*pixel, *height, *width);
					*pixel = NULL;
					return 0;
				}

				(*pixel)[i][j][k] = (byte_t)tmp;
			}
		}
	}

	printf("Imagine citita cu succes [%d-%d]\n", *height, *width);
	return 1;
}

// function that writes the header and RGB values of the ppm image
void write(char format[5], int height, int width, int max_color,
		   byte_t ****pixel)
{
	printf("%s\n%d %d\n%d\n", format, height, width, max_color);

	// print pixel
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			for (int k = 0; k < 3; k++) {
				printf("%d ", (int)(*pixel)[i][j][k]);
			}

			if (j != width - 1) {
				printf("\n");
			}
		}

		printf("\n");
	}
}

// function that resizes the pixel array by a factor of 4
byte_t ***resize(int *height, int *width, byte_t ****pixel)
{
	int prev_height = *height;
	int prev_width = *width;

	// update dimensions
	*height *= 4;
	*width *= 4;

	// allocate a resized pixel array
	byte_t ***pixel_resize = alloc_pixel(*height, *width);

	// copy the pixel data
	for (int i = 0; i < *height; ++i) {
		for (int j = 0; j < *width; ++j) {
			// calculate the original pixel position
			int orig_i = i / 4;
			int orig_j = j / 4;

			for (int k = 0; k < 3; ++k) {
				pixel_resize[i][j][k] = (*pixel)[orig_i][orig_j][k];
			}
		}
	}

	// free the previous pixel array
	free_pixel(*pixel, prev_height, prev_width);

	printf("Imagine redimensionata cu succes [%d-%d]\n", *height, *width);
	return pixel_resize;
}

// function that generates the grid used in the marching algorithm
byte_t **generate_grid(byte_t ****pixel, int height, int width)
{
	byte_t **grid = alloc_grid(height / 4 + 1, width / 4 + 1);

	// declare the diff arrays used to calculate each neighbor in x shape
	short dif_i[5] = { -1, -1, 0,  1, 1 };
	short dif_j[5] = { -1,  1, 0, -1, 1 };

	// calculate the value of grid elements
	for (int i = 0; i < height / 4 + 1; ++i) {
		for (int j = 0; j < width / 4 + 1; ++j) {
			short value = 0;
			short cnt = 0;

			for (int k = 0; k < 5; ++k) {
				int use_i = 4 * i + dif_i[k];
				int use_j = 4 * j + dif_j[k];

				if (use_i >= 0 &&
					use_i < height &&
					use_j >= 0 &&
					use_j < width) {
					short tmp = 0;

					for (int l = 0; l < 3; ++l) {
						tmp += (short)(*pixel)[use_i][use_j][l];
					}

					cnt++;
					value += tmp / 3;
				}
			}

			grid[i][j] = value / cnt;
		}
	}

	// convert grid to 0 or 1
	for (int i = 0; i < height / 4 + 1; ++i) {
		for (int j = 0; j < width / 4 + 1; ++j) {
			if (grid[i][j] > 50) {
				grid[i][j] = 0;
			} else {
				grid[i][j] = 1;
			}
		}
	}

	return grid;
}

// function to print grid
void print_grid(byte_t ***grid, int height, int width)
{
	printf("Grid calculat cu succes [%d-%d]\n", height / 4, width / 4);

	for (int i = 0; i < height / 4; ++i) {
		for (int j = 0; j < width / 4; ++j) {
			printf("%d ", (int)(*grid)[i][j]);
		}

		printf("\n");
	}
}

// function that changes the pixel array based on the 16 cases
// of the marching squares algorithm
void change_pixel_contour(byte_t ****pixel, int i, int j, byte_t contour_case)
{
	switch (contour_case) {
	case 0:
		contour_case_0(pixel, i, j);
		break;
	case 1:
		contour_case_1(pixel, i, j);
		break;
	case 2:
		contour_case_2(pixel, i, j);
		break;
	case 3:
		contour_case_3(pixel, i, j);
		break;
	case 4:
		contour_case_4(pixel, i, j);
		break;
	case 5:
		contour_case_5(pixel, i, j);
		break;
	case 6:
		contour_case_6(pixel, i, j);
		break;
	case 7:
		contour_case_7(pixel, i, j);
		break;
	case 8:
		contour_case_8(pixel, i, j);
		break;
	case 9:
		contour_case_9(pixel, i, j);
		break;
	case 10:
		contour_case_10(pixel, i, j);
		break;
	case 11:
		contour_case_11(pixel, i, j);
		break;
	case 12:
		contour_case_12(pixel, i, j);
		break;
	case 13:
		contour_case_13(pixel, i, j);
		break;
	case 14:
		contour_case_14(pixel, i, j);
		break;
	case 15:
		contour_case_15(pixel, i, j);
		break;
	}
}

// function that executes the marching squares algorithm
void march(byte_t ****pixel, byte_t ***grid, int height, int width)
{
	if (*grid) {
		free_grid(*grid, height / 4 + 1);
	}
	*grid = generate_grid(pixel, height, width);

	byte_t **march_grid = alloc_grid(height / 4, width / 4);
	for (int i = 0; i < height / 4; i++) {
		for (int j = 0; j < width / 4; j++) {
			march_grid[i][j] = (*grid)[i][j] * 8 + (*grid)[i][j + 1] * 4
				+ (*grid)[i + 1][j + 1] * 2 + (*grid)[i + 1][j];
		}
	}

	printf("Marching Squares aplicat cu succes [%d", height);
	printf("-%d]\n", width);

	// change pixel to march values
	for (int i = 0; i < height / 4; ++i) {
		for (int j = 0; j < width / 4; ++j) {
			change_pixel_contour(pixel, 4 * i, 4 * j,
								 march_grid[i][j]);
		}
	}

	// free march grid
	free_grid(march_grid, height / 4);
}

// function to print INIT_CONTUR command
void init_contour(char format[5])
{
	print_contour_0(format);
	print_contour_1(format);
	print_contour_2(format);
	print_contour_3(format);
	print_contour_4(format);
	print_contour_5(format);
	print_contour_6(format);
	print_contour_7(format);
	print_contour_8(format);
	print_contour_9(format);
	print_contour_10(format);
	print_contour_11(format);
	print_contour_12(format);
	print_contour_13(format);
	print_contour_14(format);
	print_contour_15(format);
}
