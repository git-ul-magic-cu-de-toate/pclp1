// SAVA Victor 311CA
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LEN_MAX 256

typedef unsigned char byte_t;

typedef struct {
	byte_t r, g, b;
} colors_t;

typedef struct {
	char format[5];
	int width, height;
	int is_loaded;
	byte_t max_color;
	byte_t **gray_image;
	colors_t **color_image;
} image_t;

typedef struct {
	int x1, y1, x2, y2;
} select_t;

// function that sets the gray_image and color_image pointers to NULL
void init(image_t *image);

void remove_trailing_spaces(char str[LEN_MAX]);

// functions to allocate gray_image or color_image matrix
byte_t **alloc_gray_image(int width, int height);
colors_t **alloc_color_image(int width, int height);

// functions that free memory from previously allocated matrices
void free_image(image_t *image);
void free_gray_image(byte_t **gray_image, int height);
void free_color_image(colors_t **color_image, int height);

// functions that implement the load command
void load_command(image_t *image, select_t *select_section,
				  char param[LEN_MAX]);
void load_p2(image_t *image, FILE *in);
void load_p3(image_t *image, FILE *in);
void load_p5(image_t *image, FILE *in);
void load_p6(image_t *image, FILE *in);

// functions that implement the select command
void select_command(image_t *image, select_t *select_section,
					char param[LEN_MAX]);
void select_all(image_t *image, select_t *select_section);

// functions that implement the rotate command
void rotate_command(image_t *image, select_t *select_section,
					char param[LEN_MAX]);
void rotate_color_selection(image_t *image, select_t *select_section,
							int angle);
void rotate_color_selection_90(image_t *image, select_t *select_section);
void rotate_gray_selection(image_t *image, select_t *select_section,
						   int angle);
void rotate_gray_selection_90(image_t *image, select_t *select_section);
void rotate_color_all(image_t *image, int angle);
void rotate_color_all_90(image_t *image);
void rotate_gray_all(image_t *image, int angle);
void rotate_gray_all_90(image_t *image);

// function that implements the crop command
void crop_command(image_t *image, select_t *select_section);

// function that implements the histogram command
void histogram_command(image_t *image, char param[LEN_MAX]);

// function that implements the equalize command
void equalize_command(image_t *image);

// functions that implement the apply command
void apply_command(image_t *image, select_t *select_section,
				   char param[LEN_MAX]);
void apply_edge(image_t *image, select_t *select_section);
void apply_sharpen(image_t *image, select_t *select_section);
void apply_blur(image_t *image, select_t *select_section);
void apply_gaussian_blur(image_t *image, select_t *select_section);

// functions that implement the save command
void save_command(image_t *image, char param[LEN_MAX]);
void save_ascii(image_t *image, char filename[LEN_MAX]);
void save_binary(image_t *image, char filename[LEN_MAX]);

// function that implements the exit command
void exit_command(image_t *image);

// function that prints a message for an invalid command
void invalid_command(char command[LEN_MAX]);
