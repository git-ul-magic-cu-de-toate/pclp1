#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

void print_all_char_occurrences(char c, char s[N]) // 0 4 8 12 16 17
{
	char *p = strchr(s, c);

	while (p) {
		printf("%ld ", p - s);
		p = strchr(p + 1, c);
	}

	printf("\n");
}

void print_all_str_occurrences(char word[N], char s[N]) // 0 4 8 12 16 17
{
	char *p = strstr(s, word);

	while (p) {
		printf("%ld ", p - s);
		p = strstr(p + 1, word);
	}

	printf("\n");
}

int main(void)
{
	char s[N], c, word[N];
	fgets(s, N, stdin);
	s[strlen(s) - 1] = '\0';

	scanf("%c", &c);
	scanf("%s", word);

	print_all_char_occurrences(c, s); // 0 4 8 12 16 17
	printf("\n");

	print_all_str_occurrences(word, s); // 0 12

	// char s[] = "xlm_xlt_xgm_xmm_xxt";
	// char c = 'x';
	// print_all_char_occurrences(c, s); // 0 4 8 12 16 17
	return 0;
}