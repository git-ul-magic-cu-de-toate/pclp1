// 311CA Sava Victor
#include <stdio.h>
#include "circuits_functions.h"

int main(void)
{
	// declare a string with 5 characters
	char law[5];

	// read a string in law
	scanf("%5s", law);

	// check if the string law is 'I' or "II" or something else
	// then check if the laws are respected or not
	if (law[0] == 'I' && law[1] == '\0') {
		check_law_1();
	} else if (law[0] == 'I' && law[1] == 'I' && law[2] == '\0') {
		check_law_2();
	} else {
		printf("Legile existente sunt doar Legea 1 si Legea a 2-a\n");
	}

	return 0;
}
