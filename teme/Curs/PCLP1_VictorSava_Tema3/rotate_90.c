#include <stdio.h>

int main(void)
{
	int mat[2][4], res[4][2];

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			mat[i][j] = i + j;
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d ", mat[i][j]);
		}

		printf("\n");
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			res[j][2 - i - 1] = mat[i][j];
		}
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 2; ++j) {
			printf("%d ", res[i][j]);
		}

		printf("\n");
	}

	return 0;
}
