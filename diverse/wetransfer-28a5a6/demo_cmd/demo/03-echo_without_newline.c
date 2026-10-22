#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int print_newline = 1;

    // 1. cum prelucreaza argumentele
	for (int i = 1; i < argc; ++i) {
		if (i == 1 && !strcmp(argv[i], "-n")) {
			print_newline = 0;
			continue;
		}

		printf("%s%c", argv[i], (i < argc - 1 ? ' ' : '\0'));
	}
	if (print_newline) {
		printf("\n");
	}

    // 2. ce cod returneaza
	return 0;
}
