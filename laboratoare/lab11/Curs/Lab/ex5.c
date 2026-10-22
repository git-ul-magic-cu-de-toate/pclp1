#include <stdio.h>
#define SET_SIZE 100
typedef unsigned char SET[SET_SIZE];

int is_in_set(SET s, int n)
{
	int byte = n / 8;
	int bit = n % 8;

	if (((s[byte] << bit) & 1) == 1) {
		return 1;
	}

	return 0;
}

int main(void)
{
	SET s;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%hhu", s[i]);
	}



	return 0;
}
