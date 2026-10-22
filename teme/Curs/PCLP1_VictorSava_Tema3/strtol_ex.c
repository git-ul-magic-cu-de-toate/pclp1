#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buffer[20];

	scanf("%s", buffer);

	int angle = strtol(buffer, NULL, 10);

	if (angle % 90) {
		printf("Unsupported rotation angle\n");
		return 0;
	}

	return 0;
}
