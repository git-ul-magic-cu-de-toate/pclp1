#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

void sort_strings(int n, char v[N][N])
{
	int length[N] = { 0 };
	for (int i = 0; i < n; ++i) {
		length[i] = strlen(v[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (length[i] > length[j]) {
				char tmp[N];
				strcpy(tmp, v[i]);
				strcpy(v[i], v[j]);
				strcpy(v[j], tmp);

				int nr_tmp = length[i];
				length[i] = length[j];
				length[j] = nr_tmp;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (length[i] == length[j]) {
				char tmp[N];
				strcpy(tmp, v[i]);
				strcpy(v[i], v[j]);
				strcpy(v[j], tmp);

				int nr_tmp = length[i];
				length[i] = length[j];
				length[j] = nr_tmp;
			}
		}
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	char v[N][N];

	// read the words
	for (int i = 0; i < n; ++i) {
		scanf("%s", v[i]);
	}

	// sort words
	sort_strings(n, v);

	// print sorted words
	for (int i = 0; i < n; ++i) {
		printf("%s ", v[i]);
	}
	printf("\n");

	return 0;
}