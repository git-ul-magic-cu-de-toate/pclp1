// SAVA Victor 311CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "march_squares_functions.h"
#include "change_pixel.h"
#include "init_contour.h"

// Define byte_t as a cleaner alias for unsigned char
typedef unsigned char byte_t;

int main(void)
{
	char command[15], format[5]; // declare command and format string
	byte_t **grid = NULL; // allocate grid matrix
	byte_t ***pixel = NULL; // allocate 3d array pixel
	int height, width, max_color; // declare height, width, max_color of pixel

	while (scanf("%s", command) == 1) {
		// READ section
		if (strstr(command, "READ")) {
			if (pixel) {
				free_pixel(pixel, height, width);
				pixel = NULL;
			}

			if (grid) {
				free_grid(grid, height / 4 + 1);
				grid = NULL;
			}

			if (!read(format, &height, &width, &max_color, &pixel)) {
				break;
			}
		}

		// WRITE section
		if (strstr(command, "WRITE")) {
			write(format, height, width, max_color, &pixel);
		}

		// RESIZE section
		if (strstr(command, "RESIZE")) {
			pixel = resize(&height, &width, &pixel);
		}

		// GRID section
		if (strstr(command, "GRID")) {
			if (grid) {
				free_grid(grid, height / 4 + 1);
			}

			grid = generate_grid(&pixel, height, width);

			print_grid(&grid, height, width);
		}

		// MARCH section
		if (strstr(command, "MARCH")) {
			march(&pixel, &grid, height, width);
		}

		// INIT_CONTUR section
		if (strstr(command, "INIT_CONTUR")) {
			init_contour(format);
		}

		// EXIT section
		if (strstr(command, "EXIT")) {
			printf("Gigel a terminat\n");

			free_pixel(pixel, height, width);

			if (grid) {
				free_grid(grid, height / 4 + 1);
				grid = NULL;
			}

			return 0;
		}
	}

	return 0;
}
