#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

int main(void)
{
	char s[N];
	fgets(s, N, stdin);
	s[strlen(s) - 1] = '\0';

	char sep[] = " \t\n.;,?!";

	int wc = 0;
	char *p;
	p = strtok(s, sep);

	while (p) {
		int ok_alpha = 1;
		for (int i = 0; i < strlen(p); ++i) {
			if (isalpha(p[i]) == 0) {
				ok_alpha = 0;
			}
		}

		printf("%s ", p);

		if (ok_alpha == 1) {
			wc++;
		}

		p = strtok(NULL, sep);
	}
	printf("\n");
	printf("#words = %d\n", wc);

	return 0;
}