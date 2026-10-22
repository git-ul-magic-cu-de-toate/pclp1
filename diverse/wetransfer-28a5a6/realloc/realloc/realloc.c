#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_allocations_functions.h"


int main() {
	int i;
	int *v = (int *) my_malloc(100);

	for (i = 0; i < 8; i++) {
		v[i] = 255;
		printf("%d\n", v[i]);
	}
	my_realloc(v, 100);
	for (i = 0; i < 100; i++) {
		printf("%d ",v[i]);
	}
    return 0;
}

