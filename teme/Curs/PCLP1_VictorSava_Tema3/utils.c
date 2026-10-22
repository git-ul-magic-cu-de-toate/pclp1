// SAVA Victor 311CA

#include "utils.h"

void init(image_t *image)
{
	image->gray_image = NULL;
	image->color_image = NULL;
	image->is_loaded = 0;
}

void remove_trailing_spaces(char str[LEN_MAX])
{
	str[strlen(str) - 1] = '\0';
	int len = strlen(str);
	while (len > 0 && str[len - 1] == ' ') {
		len--;
	}
	str[len] = '\0';
}

byte_t **alloc_gray_image(int width, int height)
{
	byte_t **gray_image;
	gray_image = (byte_t **)malloc(height * sizeof(byte_t *));

	for (int i = 0; i < height; ++i) {
		gray_image[i] = (byte_t *)malloc(width * sizeof(byte_t));
	}

	return gray_image;
}

void free_gray_image(byte_t **gray_image, int height)
{
	for (int i = 0; i < height; ++i) {
		free(gray_image[i]);
	}

	free(gray_image);
}

colors_t **alloc_color_image(int width, int height)
{
	colors_t **color_image;
	color_image = (colors_t **)malloc(height * sizeof(colors_t *));

	for (int i = 0; i < height; ++i) {
		color_image[i] = (colors_t *)malloc(width * sizeof(colors_t));
	}

	return color_image;
}

void free_color_image(colors_t **color_image, int height)
{
	for (int i = 0; i < height; ++i) {
		free(color_image[i]);
	}

	free(color_image);
}

void free_image(image_t *image)
{
	if (image->gray_image) {
		// free gray
		free_gray_image(image->gray_image, image->height);
		image->gray_image = NULL;
	}

	if (image->color_image) {
		// free color image
		free_color_image(image->color_image, image->height);
		image->color_image = NULL;
	}
}

void load_p2(image_t *image, FILE *in)
{
	// allocate memory to image.gray_image
	image->gray_image = alloc_gray_image(image->width, image->height);

	for (int i = 0; i < image->height; ++i) {
		for (int j = 0; j < image->width; ++j) {
			fscanf(in, "%hhu", &image->gray_image[i][j]);
		}
	}
}

void load_p3(image_t *image, FILE *in)
{
	// allocate memory to image.color_image
	image->color_image = alloc_color_image(image->width, image->height);

	for (int i = 0; i < image->height; ++i) {
		for (int j = 0; j < image->width; ++j) {
			fscanf(in, "%hhu", &image->color_image[i][j].r);
			fscanf(in, "%hhu", &image->color_image[i][j].g);
			fscanf(in, "%hhu", &image->color_image[i][j].b);
		}
	}
}

void load_p5(image_t *image, FILE *in)
{
	// allocate memory to image.gray_image
	image->gray_image = alloc_gray_image(image->width, image->height);

	// skip the newline char after the header
	fgetc(in);

	for (int i = 0; i < image->height; ++i) {
		fread(image->gray_image[i], sizeof(byte_t), image->width, in);
	}
}

void load_p6(image_t *image, FILE *in)
{
	// allocate memory to image.gray_image
	image->color_image = alloc_color_image(image->width, image->height);

	// skip the newline char after the header
	fgetc(in);

	for (int i = 0; i < image->height; ++i) {
		for (int j = 0; j < image->width; ++j) {
			fread(&image->color_image[i][j], sizeof(colors_t), 1, in);
		}
	}
}

void select_all(image_t *image, select_t *select_section)
{
	select_section->x1 = 0;
	select_section->y1 = 0;
	select_section->x2 = image->width;
	select_section->y2 = image->height;
}

void load_command(image_t *image, select_t *select_section,
				  char param[LEN_MAX])
{
	remove_trailing_spaces(param);

	char filename[LEN_MAX];

	if (sscanf(param, "%s", filename) == 1) {
		;
	}

	FILE *in = fopen(filename, "rb");

	if (!in) {
		printf("Failed to load %s\n", filename);
		image->is_loaded = 0;
		return;
	}

	fscanf(in, "%s", image->format);
	fscanf(in, "%d%d", &image->width, &image->height);
	fscanf(in, "%hhu", &image->max_color);

	// Grayscale ASCII file
	if (!strcmp(image->format, "P2")) {
		load_p2(image, in);
	}

	// RGB ASCII file
	if (!strcmp(image->format, "P3")) {
		load_p3(image, in);
	}

	// Grayscale Binary file
	if (!strcmp(image->format, "P5")) {
		load_p5(image, in);
	}

	// RGB Binary file
	if (!strcmp(image->format, "P6")) {
		load_p6(image, in);
	}

	select_all(image, select_section);
	image->is_loaded = 1;
	printf("Loaded %s\n", filename);
	fclose(in);
}

void select_command(image_t *image, select_t *select_section,
					char param[LEN_MAX])
{
	remove_trailing_spaces(param);

	// SELECT ALL case
	if (!strcmp(param, "ALL")) {
		if (image->is_loaded == 0) {
			printf("No image loaded\n");
			return;
		}

		select_all(image, select_section);
		printf("Selected ALL\n");
		return;
	}

	// SELECT <x1> <y1> <x2> <y2> case
	int x1, y1, x2, y2;
	char extra[LEN_MAX];

	int count = sscanf(param, "%d%d%d%d%s", &x1, &y1, &x2, &y2, extra);

	if (count != 4) {
		printf("Invalid command\n");
		return;
	}

	if (image->is_loaded == 0) {
		printf("No image loaded\n");
		return;
	}

	// check if out of bounds
	if ((x1 < 0 || x1 > image->width) ||
		(x2 < 0 || x2 > image->width) ||
		(y1 < 0 || y1 > image->height) ||
		(y2 < 0 || y2 > image->height) ||
		(x1 - x2 == 0 || y1 - y2 == 0)) {
		printf("Invalid set of coordinates\n");
		return;
	}

	// check order (x1 < x2 && y1 < y2)
	if (x1 > x2) {
		int tmp = x1;
		x1 = x2;
		x2 = tmp;
	}

	if (y1 > y2) {
		int tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	select_section->x1 = x1;
	select_section->y1 = y1;
	select_section->x2 = x2;
	select_section->y2 = y2;

	printf("Selected %d %d %d %d\n", x1, y1, x2, y2);
}

void rotate_gray_all_90(image_t *image)
{
	byte_t **rotated_gray_image;
	rotated_gray_image = alloc_gray_image(image->height, image->width);

	// copy and tranpose the image
	for (int i = 0; i < image->height; ++i) {
		for (int j = 0; j < image->width; ++j) {
			rotated_gray_image[j][i] = image->gray_image[i][j];
		}
	}

	// reverse rows
	for (int i = 0; i < image->width; i++) {
		for (int j = 0; j < image->height / 2; j++) {
			byte_t tmp = rotated_gray_image[i][j];
			rotated_gray_image[i][j] =
				rotated_gray_image[i][image->height - j - 1];
			rotated_gray_image[i][image->height - j - 1] = tmp;
		}
	}

	free_gray_image(image->gray_image, image->height);

	image->gray_image = alloc_gray_image(image->height, image->width);

	for (int i = 0; i < image->width; ++i) {
		for (int j = 0; j < image->height; ++j) {
			image->gray_image[i][j] = rotated_gray_image[i][j];
		}
	}

	free_gray_image(rotated_gray_image, image->width);

	// swap width and height
	int tmp = image->width;
	image->width = image->height;
	image->height = tmp;
}

void rotate_gray_all(image_t *image, int angle)
{
	angle = (angle % 360 + 360) % 360;

	if (angle == 90) {
		rotate_gray_all_90(image);
	} else if (angle == 180) {
		rotate_gray_all_90(image);
		rotate_gray_all_90(image);
	} else if (angle == 270) {
		rotate_gray_all_90(image);
		rotate_gray_all_90(image);
		rotate_gray_all_90(image);
	}
}

void rotate_color_all_90(image_t *image)
{
	colors_t **rotated_color_image;
	rotated_color_image = alloc_color_image(image->height, image->width);

	// copy and tranpose the image
	for (int i = 0; i < image->height; ++i) {
		for (int j = 0; j < image->width; ++j) {
			rotated_color_image[j][i] = image->color_image[i][j];
		}
	}

	// reverse rows
	for (int i = 0; i < image->width; i++) {
		for (int j = 0; j < image->height / 2; j++) {
			colors_t tmp = rotated_color_image[i][j];
			rotated_color_image[i][j] =
				rotated_color_image[i][image->height - j - 1];
			rotated_color_image[i][image->height - j - 1] = tmp;
		}
	}

	free_color_image(image->color_image, image->height);

	image->color_image = alloc_color_image(image->height, image->width);

	for (int i = 0; i < image->width; ++i) {
		for (int j = 0; j < image->height; ++j) {
			image->color_image[i][j] = rotated_color_image[i][j];
		}
	}

	free_color_image(rotated_color_image, image->width);

	// swap width and height
	int tmp = image->width;
	image->width = image->height;
	image->height = tmp;
}

void rotate_color_all(image_t *image, int angle)
{
	angle = (angle % 360 + 360) % 360;

	if (angle == 90) {
		rotate_color_all_90(image);
	} else if (angle == 180) {
		rotate_color_all_90(image);
		rotate_color_all_90(image);
	} else if (angle == 270) {
		rotate_color_all_90(image);
		rotate_color_all_90(image);
		rotate_color_all_90(image);
	}
}

void rotate_gray_selection_90(image_t *image, select_t *select_section)
{
	int x1 = select_section->x1;
	int y1 = select_section->y1;
	int x2 = select_section->x2;
	int y2 = select_section->y2;

	int new_width = x2 - x1;
	int new_height = y2 - y1;

	byte_t **rotated_gray_image;
	rotated_gray_image = alloc_gray_image(new_width, new_height);

	// copy the selection into an auxiliary matrix
	for (int i = 0; i < new_height; ++i) {
		for (int j = 0; j < new_width; ++j) {
			rotated_gray_image[i][j] = image->gray_image[y1 + i][x1 + j];
		}
	}

	// transpose image
	for (int i = 0; i < new_height; ++i) {
		for (int j = i + 1; j < new_width; ++j) {
			byte_t tmp = rotated_gray_image[i][j];
			rotated_gray_image[i][j] = rotated_gray_image[j][i];
			rotated_gray_image[j][i] = tmp;
		}
	}

	// reverse rows
	for (int i = 0; i < new_width; i++) {
		for (int j = 0; j < new_height / 2; j++) {
			byte_t tmp = rotated_gray_image[i][j];
			rotated_gray_image[i][j] =
				rotated_gray_image[i][new_height - j - 1];
			rotated_gray_image[i][new_height - j - 1] = tmp;
		}
	}

	// replace selection data with auxiliary matrix
	for (int i = 0; i < new_width; ++i) {
		for (int j = 0; j < new_height; ++j) {
			image->gray_image[y1 + i][x1 + j] = rotated_gray_image[i][j];
		}
	}

	free_gray_image(rotated_gray_image, new_height);
}

void rotate_gray_selection(image_t *image, select_t *select_section, int angle)
{
	angle = (angle % 360 + 360) % 360;

	if (angle == 90) {
		rotate_gray_selection_90(image, select_section);
	} else if (angle == 180) {
		rotate_gray_selection_90(image, select_section);
		rotate_gray_selection_90(image, select_section);
	} else if (angle == 270) {
		rotate_gray_selection_90(image, select_section);
		rotate_gray_selection_90(image, select_section);
		rotate_gray_selection_90(image, select_section);
	}
}

void rotate_color_selection_90(image_t *image, select_t *select_section)
{
	int x1 = select_section->x1;
	int y1 = select_section->y1;
	int x2 = select_section->x2;
	int y2 = select_section->y2;

	int new_width = x2 - x1;
	int new_height = y2 - y1;

	colors_t **rotated_color_image;
	rotated_color_image = alloc_color_image(new_width, new_height);

	// copy the selection into an auxiliary matrix
	for (int i = 0; i < new_height; ++i) {
		for (int j = 0; j < new_width; ++j) {
			rotated_color_image[i][j] = image->color_image[y1 + i][x1 + j];
		}
	}

	// transpose image
	for (int i = 0; i < new_height; ++i) {
		for (int j = i + 1; j < new_width; ++j) {
			colors_t tmp = rotated_color_image[i][j];
			rotated_color_image[i][j] = rotated_color_image[j][i];
			rotated_color_image[j][i] = tmp;
		}
	}

	// reverse rows
	for (int i = 0; i < new_width; i++) {
		for (int j = 0; j < new_height / 2; j++) {
			colors_t tmp = rotated_color_image[i][j];
			rotated_color_image[i][j] =
				rotated_color_image[i][new_height - j - 1];
			rotated_color_image[i][new_height - j - 1] = tmp;
		}
	}

	// replace selection data with auxiliary matrix
	for (int i = 0; i < new_width; ++i) {
		for (int j = 0; j < new_height; ++j) {
			image->color_image[y1 + i][x1 + j] = rotated_color_image[i][j];
		}
	}

	free_color_image(rotated_color_image, new_height);
}

void rotate_color_selection(image_t *image, select_t *select_section, int angle)
{
	angle = (angle % 360 + 360) % 360;

	if (angle == 90) {
		rotate_color_selection_90(image, select_section);
	} else if (angle == 180) {
		rotate_color_selection_90(image, select_section);
		rotate_color_selection_90(image, select_section);
	} else if (angle == 270) {
		rotate_color_selection_90(image, select_section);
		rotate_color_selection_90(image, select_section);
		rotate_color_selection_90(image, select_section);
	}
}

void rotate_command(image_t *image, select_t *select_section,
					char param[LEN_MAX])
{
	remove_trailing_spaces(param);

	if (image->is_loaded == 0) {
		printf("No image loaded\n");
		return;
	}

	int angle = strtol(param, NULL, 10);

	if (angle % 90) {
		printf("Unsupported rotation angle\n");
		return;
	}

	int x1 = select_section->x1;
	int y1 = select_section->y1;
	int x2 = select_section->x2;
	int y2 = select_section->y2;

	if (!((x1 == 0 && y1 == 0 && x2 == image->width && y2 == image->height) ||
		  (x2 - x1 == y2 - y1))) {
		printf("The selection must be square\n");
		return;
	}

	// rotation applied to whole image
	if (x1 == 0 && y1 == 0 && x2 == image->width && y2 == image->height) {
		if (!strcmp(image->format, "P2") || !strcmp(image->format, "P5")) {
			// Gray image
			rotate_gray_all(image, angle);
			select_all(image, select_section);
		} else {
			// Color image
			rotate_color_all(image, angle);
			select_all(image, select_section);
		}
	} else {
		// rotation applied to square selection
		if (!strcmp(image->format, "P2") || !strcmp(image->format, "P5")) {
			// Gray image
			rotate_gray_selection(image, select_section, angle);
		} else {
			// Color image
			rotate_color_selection(image, select_section, angle);
		}
	}

	printf("Rotated %d\n", angle);
}

void crop_gray(image_t *image, select_t *select_section)
{
	int x1 = select_section->x1;
	int y1 = select_section->y1;
	int x2 = select_section->x2;
	int y2 = select_section->y2;

	int new_width = x2 - x1;
	int new_height = y2 - y1;

	byte_t **cropped_gray_image = alloc_gray_image(new_width, new_height);

	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			cropped_gray_image[i - y1][j - x1] = image->gray_image[i][j];
		}
	}

	free_gray_image(image->gray_image, image->height);

	image->gray_image = alloc_gray_image(new_width, new_height);

	for (int i = 0; i < new_height; ++i) {
		for (int j = 0; j < new_width; ++j) {
			image->gray_image[i][j] = cropped_gray_image[i][j];
		}
	}

	free_gray_image(cropped_gray_image, new_height);

	image->width = new_width;
	image->height = new_height;
}

void crop_color(image_t *image, select_t *select_section)
{
	int x1 = select_section->x1;
	int y1 = select_section->y1;
	int x2 = select_section->x2;
	int y2 = select_section->y2;

	int new_width = x2 - x1;
	int new_height = y2 - y1;

	colors_t **cropped_color_image = alloc_color_image(new_width, new_height);

	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			cropped_color_image[i - y1][j - x1].r = image->color_image[i][j].r;
			cropped_color_image[i - y1][j - x1].g = image->color_image[i][j].g;
			cropped_color_image[i - y1][j - x1].b = image->color_image[i][j].b;
		}
	}

	free_color_image(image->color_image, image->height);

	image->color_image = alloc_color_image(new_width, new_height);

	for (int i = 0; i < new_height; ++i) {
		for (int j = 0; j < new_width; ++j) {
			image->color_image[i][j].r = cropped_color_image[i][j].r;
			image->color_image[i][j].g = cropped_color_image[i][j].g;
			image->color_image[i][j].b = cropped_color_image[i][j].b;
		}
	}

	free_color_image(cropped_color_image, new_height);

	image->width = new_width;
	image->height = new_height;
}

void crop_command(image_t *image, select_t *select_section)
{
	if (image->is_loaded == 0) {
		printf("No image loaded\n");
		return;
	}

	// ASCII file
	if (!strcmp(image->format, "P2") || !strcmp(image->format, "P5")) {
		crop_gray(image, select_section);
	}

	// Binary file
	if (!strcmp(image->format, "P3") || !strcmp(image->format, "P6")) {
		crop_color(image, select_section);
	}

	select_all(image, select_section);

	printf("Image cropped\n");
}

void histogram_command(image_t *image, char param[LEN_MAX])
{
	remove_trailing_spaces(param);

	if (image->is_loaded == 0) {
		printf("No image loaded\n");
		return;
	}

	int x, y;
	char extra[LEN_MAX];

	int count = sscanf(param, "%d%d%s", &x, &y, extra);

	if (strlen(param) == 0 || count != 2 || y % 2 != 0) {
		printf("Invalid command\n");
		return;
	}

	if (!strcmp(image->format, "P3") || !strcmp(image->format, "P6")) {
		printf("Black and white image needed\n");
		return;
	}

	// frequency for values [0, 255]
	int freq[LEN_MAX] = { 0 };
	for (int i = 0; i < image->height; ++i) {
		for (int j = 0; j < image->width; ++j) {
			freq[image->gray_image[i][j]]++;
		}
	}

	// frequency for values in bins
	int freq_bin[y];
	memset(freq_bin, 0, y * sizeof(int));
	for (int i = 0; i < y; ++i) {
		for (int j = i * (256 / y); j < (i + 1) * (256 / y); ++j) {
			freq_bin[i] += freq[j];
		}
	}

	// find max frequency
	int max_freq = freq_bin[0];
	for (int i = 1; i < y; ++i) {
		if (freq_bin[i] > max_freq) {
			max_freq = freq_bin[i];
		}
	}

	// calculate no of stars
	int freq_stars[y];
	memset(freq_stars, 0, y * sizeof(int));
	for (int i = 0; i < y; ++i) {
		freq_stars[i] = (freq_bin[i] * x) / max_freq;
	}

	// print histogram
	for (int i = 0; i < y; ++i) {
		printf("%d\t|\t", freq_stars[i]);

		for (int j = 0; j < freq_stars[i]; ++j) {
			printf("*");
		}

		printf("\n");
	}
}

void equalize_command(image_t *image)
{
	if (image->is_loaded == 0) {
		printf("No image loaded\n");
		return;
	}

	if (!strcmp(image->format, "P3") || !strcmp(image->format, "P6")) {
		printf("Black and white image needed\n");
		return;
	}

	// calculate frequency for values [0, 255]
	int freq[LEN_MAX] = { 0 };
	for (int i = 0; i < image->height; ++i) {
		for (int j = 0; j < image->width; ++j) {
			freq[image->gray_image[i][j]]++;
		}
	}

	// calculate new values for pixels
	double area = image->width * image->height;
	for (int i = 0; i < image->height; ++i) {
		for (int j = 0; j < image->width; ++j) {
			// calculate sum of frequencies
			int sum = 0;
			for (int k = 0; k <= image->gray_image[i][j]; ++k) {
				sum += freq[k];
			}

			double tmp = round((255 * sum) / area);

			// clamp
			if (tmp < 0) {
				tmp = 0;
			} else if (tmp > 255) {
				tmp = 255;
			}

			image->gray_image[i][j] = (byte_t)tmp;
		}
	}

	printf("Equalize done\n");
}

void apply_edge(image_t *image, select_t *select_section)
{
	int x1 = select_section->x1;
	int y1 = select_section->y1;
	int x2 = select_section->x2;
	int y2 = select_section->y2;

	if (x1 == 0) {
		x1++;
	}
	if (y1 == 0) {
		y1++;
	}
	if (x2 == image->width) {
		x2--;
	}
	if (y2 == image->height) {
		y2--;
	}

	colors_t **edgy_image = alloc_color_image(image->width, image->height);

	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			int sum_r = 0;
			int sum_g = 0;
			int sum_b = 0;

			for (int k = i - 1; k < i + 2; ++k) {
				for (int l = j - 1; l < j + 2; ++l) {
					if (k == i && l == j) {
						sum_r += (image->color_image[k][l].r * 8);
						sum_g += (image->color_image[k][l].g * 8);
						sum_b += (image->color_image[k][l].b * 8);
					} else {
						sum_r += (-image->color_image[k][l].r);
						sum_g += (-image->color_image[k][l].g);
						sum_b += (-image->color_image[k][l].b);
					}
				}
			}

			// clamp red
			if (sum_r < 0) {
				sum_r = 0;
			} else if (sum_r > 255) {
				sum_r = 255;
			}

			// clamp green
			if (sum_g < 0) {
				sum_g = 0;
			} else if (sum_g > 255) {
				sum_g = 255;
			}

			// clamp blue
			if (sum_b < 0) {
				sum_b = 0;
			} else if (sum_b > 255) {
				sum_b = 255;
			}

			edgy_image[i][j].r = sum_r;
			edgy_image[i][j].g = sum_g;
			edgy_image[i][j].b = sum_b;
		}
	}

	// copy the pixels in color_image matrix
	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			image->color_image[i][j] = edgy_image[i][j];
		}
	}

	free_color_image(edgy_image, image->height);
}

void apply_blur(image_t *image, select_t *select_section)
{
	int x1 = select_section->x1;
	int y1 = select_section->y1;
	int x2 = select_section->x2;
	int y2 = select_section->y2;

	if (x1 == 0) {
		x1++;
	}
	if (y1 == 0) {
		y1++;
	}
	if (x2 == image->width) {
		x2--;
	}
	if (y2 == image->height) {
		y2--;
	}

	colors_t **sharpy_image = alloc_color_image(image->width, image->height);

	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			int sum_r = 0;
			int sum_g = 0;
			int sum_b = 0;

			for (int k = i - 1; k < i + 2; ++k) {
				for (int l = j - 1; l < j + 2; ++l) {
					sum_r += image->color_image[k][l].r;
					sum_g += image->color_image[k][l].g;
					sum_b += image->color_image[k][l].b;
				}
			}

			sum_r /= 9;
			sum_g /= 9;
			sum_b /= 9;

			// clamp red
			if (sum_r < 0) {
				sum_r = 0;
			} else if (sum_r > 255) {
				sum_r = 255;
			}

			// clamp green
			if (sum_g < 0) {
				sum_g = 0;
			} else if (sum_g > 255) {
				sum_g = 255;
			}

			// clamp blue
			if (sum_b < 0) {
				sum_b = 0;
			} else if (sum_b > 255) {
				sum_b = 255;
			}

			sharpy_image[i][j].r = sum_r;
			sharpy_image[i][j].g = sum_g;
			sharpy_image[i][j].b = sum_b;
		}
	}

	// copy the pixels in color_image matrix
	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			image->color_image[i][j] = sharpy_image[i][j];
		}
	}

	free_color_image(sharpy_image, image->height);
}

void apply_gaussian_blur(image_t *image, select_t *select_section)
{
	int x1 = select_section->x1;
	int y1 = select_section->y1;
	int x2 = select_section->x2;
	int y2 = select_section->y2;

	if (x1 == 0) {
		x1++;
	}
	if (y1 == 0) {
		y1++;
	}
	if (x2 == image->width) {
		x2--;
	}
	if (y2 == image->height) {
		y2--;
	}

	colors_t **sharpy_image = alloc_color_image(image->width, image->height);

	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			int sum_r = 0;
			int sum_g = 0;
			int sum_b = 0;

			int dif_line[9] = { -1, -1, -1,  0, 0, 0,  1, 1, 1 };
			int dif_col[9] = { -1,  0,  1, -1, 0, 1, -1, 0, 1 };
			int multiply[9] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };

			for (int k = 0; k < 9; ++k) {
				sum_r += (image->color_image[i + dif_line[k]]
						  [j + dif_col[k]].r) * multiply[k];
				sum_g += (image->color_image[i + dif_line[k]]
						  [j + dif_col[k]].g) * multiply[k];
				sum_b += (image->color_image[i + dif_line[k]]
						  [j + dif_col[k]].b) * multiply[k];
			}

			sum_r /= 16;
			sum_g /= 16;
			sum_b /= 16;

			// clamp red
			if (sum_r < 0) {
				sum_r = 0;
			} else if (sum_r > 255) {
				sum_r = 255;
			}

			// clamp green
			if (sum_g < 0) {
				sum_g = 0;
			} else if (sum_g > 255) {
				sum_g = 255;
			}

			// clamp blue
			if (sum_b < 0) {
				sum_b = 0;
			} else if (sum_b > 255) {
				sum_b = 255;
			}

			sharpy_image[i][j].r = sum_r;
			sharpy_image[i][j].g = sum_g;
			sharpy_image[i][j].b = sum_b;
		}
	}

	// copy the pixels in color_image matrix
	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			image->color_image[i][j] = sharpy_image[i][j];
		}
	}

	free_color_image(sharpy_image, image->height);
}

void apply_sharpen(image_t *image, select_t *select_section)
{
	int x1 = select_section->x1;
	int y1 = select_section->y1;
	int x2 = select_section->x2;
	int y2 = select_section->y2;

	if (x1 == 0) {
		x1++;
	}
	if (y1 == 0) {
		y1++;
	}
	if (x2 == image->width) {
		x2--;
	}
	if (y2 == image->height) {
		y2--;
	}

	colors_t **sharpy_image = alloc_color_image(image->width, image->height);

	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			int sum_r = 5 * image->color_image[i][j].r -
				image->color_image[i + 1][j].r -
				image->color_image[i][j + 1].r -
				image->color_image[i - 1][j].r -
				image->color_image[i][j - 1].r;
			int sum_g = 5 * image->color_image[i][j].g -
				image->color_image[i + 1][j].g -
				image->color_image[i][j + 1].g -
				image->color_image[i - 1][j].g -
				image->color_image[i][j - 1].g;
			int sum_b = 5 * image->color_image[i][j].b -
				image->color_image[i + 1][j].b -
				image->color_image[i][j + 1].b -
				image->color_image[i - 1][j].b -
				image->color_image[i][j - 1].b;

			// clamp red
			if (sum_r < 0) {
				sum_r = 0;
			} else if (sum_r > 255) {
				sum_r = 255;
			}

			// clamp green
			if (sum_g < 0) {
				sum_g = 0;
			} else if (sum_g > 255) {
				sum_g = 255;
			}

			// clamp blue
			if (sum_b < 0) {
				sum_b = 0;
			} else if (sum_b > 255) {
				sum_b = 255;
			}

			sharpy_image[i][j].r = sum_r;
			sharpy_image[i][j].g = sum_g;
			sharpy_image[i][j].b = sum_b;
		}
	}

	// copy the pixels in color_image matrix
	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			image->color_image[i][j] = sharpy_image[i][j];
		}
	}

	free_color_image(sharpy_image, image->height);
}

void apply_command(image_t *image, select_t *select_section,
				   char param[LEN_MAX])
{
	remove_trailing_spaces(param);

	if (image->is_loaded == 0) {
		printf("No image loaded\n");
		return;
	}

	// no parameter
	if (strlen(param) == 0) {
		printf("Invalid command\n");
		return;
	}

	// invalid parameter
	if (!strcmp(param, "EDGE")) {
	} else if (!strcmp(param, "SHARPEN")) {
	} else if (!strcmp(param, "BLUR")) {
	} else if (!strcmp(param, "GAUSSIAN_BLUR")) {
	} else {
		printf("APPLY parameter invalid\n");
		return;
	}

	// grayscale command
	if (!strcmp(image->format, "P2") || !strcmp(image->format, "P5")) {
		printf("Easy, Charlie Chaplin\n");
		return;
	}

	// APPLY <parameter>
	if (!strcmp(param, "EDGE")) {
		apply_edge(image, select_section);
	} else if (!strcmp(param, "SHARPEN")) {
		apply_sharpen(image, select_section);
	} else if (!strcmp(param, "BLUR")) {
		apply_blur(image, select_section);
	} else if (!strcmp(param, "GAUSSIAN_BLUR")) {
		apply_gaussian_blur(image, select_section);
	}

	printf("APPLY %s done\n", param);
}

void exit_command(image_t *image)
{
	if (image->is_loaded == 0) {
		printf("No image loaded\n");
	} else {
		free_image(image);
	}
}

void save_ascii(image_t *image, char filename[LEN_MAX])
{
	FILE *out = fopen(filename, "w");

	if (!strcmp(image->format, "P2") || !strcmp(image->format, "P5")) {
		// Grayscale format
		fprintf(out, "P2\n%d ", image->width);
		fprintf(out, "%d\n%hhu\n", image->height, image->max_color);

		for (int i = 0; i < image->height; ++i) {
			for (int j = 0; j < image->width; ++j) {
				fprintf(out, "%hhu ", image->gray_image[i][j]);
			}

			fprintf(out, "\n");
		}
	} else {
		// RGB format
		fprintf(out, "P3\n%d ", image->width);
		fprintf(out, "%d\n%hhu\n", image->height, image->max_color);

		for (int i = 0; i < image->height; ++i) {
			for (int j = 0; j < image->width; ++j) {
				fprintf(out, "%hhu ", image->color_image[i][j].r);
				fprintf(out, "%hhu ", image->color_image[i][j].g);
				fprintf(out, "%hhu ", image->color_image[i][j].b);
			}

			fprintf(out, "\n");
		}
	}

	fclose(out);
}

void save_binary(image_t *image, char filename[LEN_MAX])
{
	FILE *out = fopen(filename, "wb");

	if (!strcmp(image->format, "P2") || !strcmp(image->format, "P5")) {
		// Grayscale format
		fprintf(out, "P5\n%d ", image->width);
		fprintf(out, "%d\n%hhu\n", image->height, image->max_color);

		for (int i = 0; i < image->height; ++i) {
			fwrite(image->gray_image[i], sizeof(byte_t), image->width, out);
		}
	} else {
		// RGB format
		fprintf(out, "P6\n%d ", image->width);
		fprintf(out, "%d\n%hhu\n", image->height, image->max_color);

		for (int i = 0; i < image->height; ++i) {
			for (int j = 0; j < image->width; ++j) {
				fwrite(&image->color_image[i][j], sizeof(colors_t), 1, out);
			}
		}
	}

	fclose(out);
}

void save_command(image_t *image, char param[LEN_MAX])
{
	remove_trailing_spaces(param);

	if (image->is_loaded == 0) {
		printf("No image loaded\n");
		return;
	}

	char filename[LEN_MAX], attribute[LEN_MAX];

	if (sscanf(param, "%s", filename) == 1) {
		;
	}

	if (sscanf(param, "%s", attribute) == 1) {
		// if "ascii" is present
		save_ascii(image, filename);
	} else {
		// if "ascii" is not present
		save_binary(image, filename);
	}

	printf("Saved %s\n", filename);
}

void invalid_command(char command[LEN_MAX])
{
	if (!strcmp(command, "LOAD")) {
	} else if (!strcmp(command, "SELECT")) {
	} else if (!strcmp(command, "ROTATE")) {
	} else if (!strcmp(command, "CROP")) {
	} else if (!strcmp(command, "HISTOGRAM")) {
	} else if (!strcmp(command, "EQUALIZE")) {
	} else if (!strcmp(command, "APPLY")) {
	} else if (!strcmp(command, "SAVE")) {
	} else if (!strcmp(command, "EXIT")) {
	} else {
		printf("Invalid command\n");
	}
}
