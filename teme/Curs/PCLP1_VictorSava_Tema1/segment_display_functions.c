// 311CA Sava Victor
#include <stdio.h>
#define NMAX 1001
typedef unsigned long long ull;

// function that prints a matrix
void print_matrix(char digit_matrix[NMAX][NMAX], int n, int m)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%c ", digit_matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// function that fills a matrix with space
void fill_matrix_with_space(char digit_matrix[NMAX][NMAX], int n, int m)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			digit_matrix[i][j] = ' ';
		}
	}
}

// function that fill the a segment of a display
void fill_a(char digit_matrix[NMAX][NMAX], int len)
{
	// declare the width of a segment
	int width;
	width = len / 3;

	int start_li, fin_li, start_col, fin_col;

	start_li = 0;
	fin_li = width;
	start_col = width;
	fin_col = len + width;

	for (int i = start_li; i < fin_li; ++i) {
		for (int j = start_col; j < fin_col; ++j) {
			digit_matrix[i][j] = '^';
		}
	}
}

// function that fill the b segment of a display
void fill_b(char digit_matrix[NMAX][NMAX], int len)
{
	// declare the width of a segment
	int width;
	width = len / 3;

	int start_li, fin_li, start_col, fin_col;

	start_li = width;
	fin_li = len + width;
	start_col = len + width;
	fin_col = len + 2 * width;

	for (int i = start_li; i < fin_li; ++i) {
		for (int j = start_col; j < fin_col; ++j) {
			digit_matrix[i][j] = '^';
		}
	}
}

// function that fill the c segment of a display
void fill_c(char digit_matrix[NMAX][NMAX], int len)
{
	// declare the width of a segment
	int width;
	width = len / 3;

	int start_li, fin_li, start_col, fin_col;

	start_li = len + 2 * width;
	fin_li = 2 * len + 2 * width;
	start_col = len + width;
	fin_col = len + 2 * width;

	for (int i = start_li; i < fin_li; ++i) {
		for (int j = start_col; j < fin_col; ++j) {
			digit_matrix[i][j] = '^';
		}
	}
}

// function that fill the d segment of a display
void fill_d(char digit_matrix[NMAX][NMAX], int len)
{
	// declare the width of a segment
	int width;
	width = len / 3;

	int start_li, fin_li, start_col, fin_col;

	start_li = 2 * len + 2 * width;
	fin_li = 2 * len + 3 * width;
	start_col = width;
	fin_col = width + len;

	for (int i = start_li; i < fin_li; ++i) {
		for (int j = start_col; j < fin_col; ++j) {
			digit_matrix[i][j] = '^';
		}
	}
}

// function that fill the e segment of a display
void fill_e(char digit_matrix[NMAX][NMAX], int len)
{
	// declare the width of a segment
	int width;
	width = len / 3;

	int start_li, fin_li, start_col, fin_col;

	start_li = len + 2 * width;
	fin_li = 2 * len + 2 * width;
	start_col = 0;
	fin_col = width;

	for (int i = start_li; i < fin_li; ++i) {
		for (int j = start_col; j < fin_col; ++j) {
			digit_matrix[i][j] = '^';
		}
	}
}

// function that fill the f segment of a display
void fill_f(char digit_matrix[NMAX][NMAX], int len)
{
	// declare the width of a segment
	int width;
	width = len / 3;

	int start_li, fin_li, start_col, fin_col;

	start_li = width;
	fin_li = len + width;
	start_col = 0;
	fin_col = width;

	for (int i = start_li; i < fin_li; ++i) {
		for (int j = start_col; j < fin_col; ++j) {
			digit_matrix[i][j] = '^';
		}
	}
}

// function that fill the g segment of a display
void fill_g(char digit_matrix[NMAX][NMAX], int len)
{
	// declare the width of a segment
	int width;
	width = len / 3;

	int start_li, fin_li, start_col, fin_col;

	start_li = len + width;
	fin_li = len + 2 * width;
	start_col = width;
	fin_col = len + width;

	for (int i = start_li; i < fin_li; ++i) {
		for (int j = start_col; j < fin_col; ++j) {
			digit_matrix[i][j] = '^';
		}
	}
}

// function that fills the digit matrix for digit 0
void fill_matrix_zero(char digit_matrix[NMAX][NMAX], int n, int m, int len)
{
	fill_matrix_with_space(digit_matrix, n, m);
	fill_a(digit_matrix, len);
	fill_b(digit_matrix, len);
	fill_c(digit_matrix, len);
	fill_d(digit_matrix, len);
	fill_e(digit_matrix, len);
	fill_f(digit_matrix, len);
}

// function that fills the digit matrix for digit 1
void fill_matrix_one(char digit_matrix[NMAX][NMAX], int n, int m, int len)
{
	fill_matrix_with_space(digit_matrix, n, m);
	fill_b(digit_matrix, len);
	fill_c(digit_matrix, len);
}

// function that fills the digit matrix for digit 2
void fill_matrix_two(char digit_matrix[NMAX][NMAX], int n, int m, int len)
{
	fill_matrix_with_space(digit_matrix, n, m);
	fill_a(digit_matrix, len);
	fill_b(digit_matrix, len);
	fill_d(digit_matrix, len);
	fill_e(digit_matrix, len);
	fill_g(digit_matrix, len);
}

// function that fills the digit matrix for digit 3
void fill_matrix_three(char digit_matrix[NMAX][NMAX], int n, int m, int len)
{
	fill_matrix_with_space(digit_matrix, n, m);
	fill_a(digit_matrix, len);
	fill_b(digit_matrix, len);
	fill_c(digit_matrix, len);
	fill_d(digit_matrix, len);
	fill_g(digit_matrix, len);
}

// function that fills the digit matrix for digit 4
void fill_matrix_four(char digit_matrix[NMAX][NMAX], int n, int m, int len)
{
	fill_matrix_with_space(digit_matrix, n, m);
	fill_b(digit_matrix, len);
	fill_c(digit_matrix, len);
	fill_f(digit_matrix, len);
	fill_g(digit_matrix, len);
}

// function that fills the digit matrix for digit 5
void fill_matrix_five(char digit_matrix[NMAX][NMAX], int n, int m, int len)
{
	fill_matrix_with_space(digit_matrix, n, m);
	fill_a(digit_matrix, len);
	fill_c(digit_matrix, len);
	fill_d(digit_matrix, len);
	fill_f(digit_matrix, len);
	fill_g(digit_matrix, len);
}

// function that fills the digit matrix for digit 6
void fill_matrix_six(char digit_matrix[NMAX][NMAX], int n, int m, int len)
{
	fill_matrix_with_space(digit_matrix, n, m);
	fill_a(digit_matrix, len);
	fill_c(digit_matrix, len);
	fill_d(digit_matrix, len);
	fill_e(digit_matrix, len);
	fill_f(digit_matrix, len);
	fill_g(digit_matrix, len);
}

// function that fills the digit matrix for digit 7
void fill_matrix_seven(char digit_matrix[NMAX][NMAX], int n, int m, int len)
{

	fill_matrix_with_space(digit_matrix, n, m);
	fill_a(digit_matrix, len);
	fill_b(digit_matrix, len);
	fill_c(digit_matrix, len);
}

// function that fills the digit matrix for digit 8
void fill_matrix_eight(char digit_matrix[NMAX][NMAX], int n, int m, int len)
{
	fill_matrix_with_space(digit_matrix, n, m);
	fill_a(digit_matrix, len);
	fill_b(digit_matrix, len);
	fill_c(digit_matrix, len);
	fill_d(digit_matrix, len);
	fill_e(digit_matrix, len);
	fill_f(digit_matrix, len);
	fill_g(digit_matrix, len);
}

// function that fills the digit matrix for digit 9
void fill_matrix_nine(char digit_matrix[NMAX][NMAX], int n, int m, int len)
{
	fill_matrix_with_space(digit_matrix, n, m);
	fill_a(digit_matrix, len);
	fill_b(digit_matrix, len);
	fill_c(digit_matrix, len);
	fill_d(digit_matrix, len);
	fill_f(digit_matrix, len);
	fill_g(digit_matrix, len);
}

// function reads a digit and fills the digit matrix for the read digit
void fill_matrix_with_digit(char digit_matrix[NMAX][NMAX],
							int n, int m, int len)
{
	// declare digit
	int digit;

	// read digit
	scanf("%d", &digit);

	// switch case for each digit
	// if the input is not a digit print a message
	switch (digit) {
	case 0:
		fill_matrix_zero(digit_matrix, n, m, len);

		break;
	case 1:
		fill_matrix_one(digit_matrix, n, m, len);

		break;
	case 2:
		fill_matrix_two(digit_matrix, n, m, len);

		break;
	case 3:
		fill_matrix_three(digit_matrix, n, m, len);

		break;
	case 4:
		fill_matrix_four(digit_matrix, n, m, len);

		break;
	case 5:
		fill_matrix_five(digit_matrix, n, m, len);

		break;
	case 6:
		fill_matrix_six(digit_matrix, n, m, len);

		break;
	case 7:
		fill_matrix_seven(digit_matrix, n, m, len);

		break;
	case 8:
		fill_matrix_eight(digit_matrix, n, m, len);

		break;
	case 9:
		fill_matrix_nine(digit_matrix, n, m, len);

		break;
	default:
		printf("The input given is not a digit.\n");
		break;
	}
}

// function that translates the digit matrix up by count times
void move_up(char digit_matrix[NMAX][NMAX], int n, int m, ull count)
{
	// reduce count to a number smaller than the number of rows
	count %= n;

	for (ull k = 1; k <= count; ++k) {
		int tmp[NMAX] = { 0 };
		for (int j = 0; j < m; ++j) {
			tmp[j] = digit_matrix[0][j];
		}

		for (int j = 0; j < m; ++j) {
			for (int i = 0; i < n - 1; ++i) {
				digit_matrix[i][j] = digit_matrix[i + 1][j];
			}
			digit_matrix[n - 1][j] = tmp[j];
		}
	}
}

// function that translates the digit matrix left by count times
void move_left(char digit_matrix[NMAX][NMAX], int n, int m, ull count)
{
	// reduce count to a number smaller than the number of columns
	count %= m;

	for (ull k = 1; k <= count; ++k) {
		int tmp[NMAX] = { 0 };
		for (int i = 0; i < n; ++i) {
			tmp[i] = digit_matrix[i][0];
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m - 1; ++j) {
				digit_matrix[i][j] = digit_matrix[i][j + 1];
			}
			digit_matrix[i][m - 1] = tmp[i];
		}
	}
}

// function that translates the digit matrix down by count times
void move_down(char digit_matrix[NMAX][NMAX], int n, int m, ull count)
{
	// reduce count to a number smaller than the number of rows
	count %= n;

	for (ull k = 1; k <= count; ++k) {
		int tmp[NMAX] = { 0 };
		for (int j = 0; j < m; ++j) {
			tmp[j] = digit_matrix[n - 1][j];
		}

		for (int j = 0; j < m; ++j) {
			for (int i = n - 1; i >= 1; --i) {
				digit_matrix[i][j] = digit_matrix[i - 1][j];
			}
			digit_matrix[0][j] = tmp[j];
		}
	}
}

// function that translates the digit matrix right by count times
void move_right(char digit_matrix[NMAX][NMAX], int n, int m, ull count)
{
	// reduce count to a number smaller than the number of columns
	count %= m;

	for (ull k = 1; k <= count; ++k) {
		int tmp[NMAX] = { 0 };
		for (int i = 0; i < n; ++i) {
			tmp[i] = digit_matrix[i][m - 1];
		}

		for (int i = 0; i < n; ++i) {
			for (int j = m; j >= 1; --j) {
				digit_matrix[i][j] = digit_matrix[i][j - 1];
			}
			digit_matrix[i][0] = tmp[i];
		}
	}
}

// function for command 'W'
void case_w(char digit_matrix[NMAX][NMAX], int n, int m)
{
	// declare count - no. of translations
	ull count;

	// read count
	scanf("%llu", &count);

	// translate digit matrix up by count times
	move_up(digit_matrix, n, m, count);
}

// function for command 'A'
void case_a(char digit_matrix[NMAX][NMAX], int n, int m)
{
	// declare count - no. of translations
	ull count;

	// read count
	scanf("%llu", &count);

	// translate digit matrix left by count times
	move_left(digit_matrix, n, m, count);
}

// function for command 'S'
void case_s(char digit_matrix[NMAX][NMAX], int n, int m)
{
	// declare count - no. of translations
	ull count;

	// read count
	scanf("%llu", &count);

	// translate digit matrix down by count times
	move_down(digit_matrix, n, m, count);
}

// function for command 'D'
void case_d(char digit_matrix[NMAX][NMAX], int n, int m)
{
	// declare count - no. of translations
	ull count;

	// read count
	scanf("%llu", &count);

	// translate digit matrix right by count times
	move_right(digit_matrix, n, m, count);
}

// function for invalid command
void case_invalid(void)
{
	// declare count - no. of translations
	ull count;

	// read count
	scanf("%llu", &count);

	printf("Invalid command.\n");
}
