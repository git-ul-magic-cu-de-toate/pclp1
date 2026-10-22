#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char line[50], command[50];

	while (fgets(line, sizeof(line), stdin)) {
		if (sscanf(line, "%s", command) == 1) {
			;
		}

		printf("%s\n", command);
	}

	return 0;
}
