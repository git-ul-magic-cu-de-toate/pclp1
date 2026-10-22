// SAVA Victor 311CA
#pragma once

typedef unsigned char byte_t;

// function that allocates memory to a 2d array
// function used for grid and march_grid arrays
byte_t **alloc_grid(int height, int width);

// function that frees a 2d array (grid and march_grid)
void free_grid(byte_t **grid, int height);

// function that allocates memory to a 3d array
// function used for a 3d array with the name pixel
byte_t ***alloc_pixel(int height, int width);

// function that frees a 3d array (for pixel)
void free_pixel(byte_t ***pixel, int height, int width);

// function that reads the header and RGB values of the ppm image
// and returns by reference the values for height, width, max color
// and the values read in the 3d array by reference
int read(char format[5], int *height, int *width, int *max_color,
		 byte_t ****pixel);

// function that writes the header and RGB values of the ppm image
void write(char format[5], int height, int width, int max_color,
		   byte_t ****pixel);

// function that resizes the pixel array by a factor of 4
byte_t ***resize(int *height, int *width, byte_t ****pixel);

// function that generates the grid used in the marching algorithm
byte_t **generate_grid(byte_t ****pixel, int height, int width);

// function to print grid
void print_grid(byte_t ***grid, int height, int width);

// function that executes the marching squares algorithm
void march(byte_t ****pixel, byte_t ***grid, int height, int width);

// function to print INIT_CONTUR command
void init_contour(char format[5]);
