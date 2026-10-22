// 311CA Sava Victor
#include <stdio.h>
#include "segment_display_functions.h"
#define NMAX 1001
typedef unsigned long long ull;

int main(void)
{
	// declare n - no. of rows and m - no. of columnns in a matrix
	// declare len - the length of a segment
	int n, m, len;

	// read the number of rows, columns, and the length of a segment
	scanf("%d%d%d", &n, &m, &len);

	// declare the type of command and the matrix for a digit
	char command, digit_matrix[NMAX][NMAX];

	// read the first command
	scanf(" %c", &command);

	// while the command is not Q,
	// check the command type and execute accordingly
	while (command != 'Q') {

		// command that fills the digit matrix with a digit
		if (command == 'F') {
			// function reads a digit and fills the digit matrix with the digit
			fill_matrix_with_digit(digit_matrix, n, m, len);
		}

		// command that translates the digit matrix up by count times
		if (command == 'W') {
			case_w(digit_matrix, n, m);
		}

		// command that translates the digit matrix left by count times
		if (command == 'A') {
			case_a(digit_matrix, n, m);
		}

		// command that translates the digit matrix down by count times
		if (command == 'S') {
			case_s(digit_matrix, n, m);
		}

		// command that translates the digit matrix right by count times
		if (command == 'D') {
			case_d(digit_matrix, n, m);
		}

		// command that prints the digit matrix
		if (command == 'P') {
			print_matrix(digit_matrix, n, m);
		}

		// invalid command
		if (command != 'F' && command != 'W' &&
			command != 'A' && command != 'S' &&
			command != 'D' && command != 'P') {
			case_invalid();
		}

		// read the next command
		scanf(" %c", &command);
	}

	return 0;
}
