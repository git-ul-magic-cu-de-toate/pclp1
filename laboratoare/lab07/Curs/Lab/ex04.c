#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

int count_occurences(char s[N], char word[N])
{
	char *p = strstr(s, word);
	int cnt = 0;

	while (p) {
		cnt++;
		p = strstr(p + 1, word);
	}

	return cnt;
}

int main(void)
{
	char s[N], word[N];
	fgets(s, N, stdin);
	s[strlen(s) - 1] = '\0';

	scanf("%s", word);

	int cnt = count_occurences(s, word);
	printf("%d\n", cnt);

	// char s[] = "Gigel is Gigel all the time except when isn't Gigel, but he is still a gigel...";
	// char word[] = "Gigel";
	return 0;
}
