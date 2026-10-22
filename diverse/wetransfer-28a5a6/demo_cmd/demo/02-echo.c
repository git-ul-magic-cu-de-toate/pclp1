#include <stdio.h>

int main(int argc, char **argv)
{
    // 1. cum prelucreaza argumentele
	for (int i = 1; i < argc; ++i) {
		printf("%s ", argv[i]);
	}
	printf("\n");

    // 2. ce cod returneaza
	return 0;
}
