#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

void is_palindrome(char s[N])
{
	int len = strlen(s);

	// make all characters lowercase
	for (int i = 0; i < len; ++i) {
		s[i] = tolower(s[i]);
	}

	// eliminate spaces
	for (int i = 0; i < strlen(s); ++i) {
		if (s[i] == ' ') {
			strcpy(s + i, s + i + 1);
		}
	}

	// recalculate len
	len = strlen(s);

	// verify if palindrome
	for (int i = 0; i < len / 2; ++i) {
		if (s[i] != s[len - i - 1]) {
			printf("NOT PALINDROME\n");
			return;
		}
	}

	printf("PALINDROME\n");
}

int main(void)
{
	char s[N];
	fgets(s, N, stdin);
	s[strlen(s) - 1] = '\0';

	is_palindrome(s);
	return 0;
}