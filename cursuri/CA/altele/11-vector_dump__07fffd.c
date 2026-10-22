// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

int main(void)
{
	/*  există următoarele echivalenţe de notaţii
	pentru un vector v:

	v[0] <==> *v
	v[1] <==> *(v + 1)
	v[k] <==> *(v + k)
	&v[0] <==> v
	&v[1] <==> v + 1
	&v[k] <==> v + k
	*/

	int v[5] = { 10, 20, 30, 40, 50 };

	for (int k = 0; k < 5; ++k) {
		printf("k = %d:\n", k);
		printf(" v[%d] <==> *(v + %d) a.k.a. %d <==> %d\n",
			   k, k, v[k], *(v + k));
		printf("&v[%d] <==>   v + %d  a.k.a. %p <==> %p\n",
			   k, k, &v[k], v + k);

		printf("\n");
	}

	return 0;
}
