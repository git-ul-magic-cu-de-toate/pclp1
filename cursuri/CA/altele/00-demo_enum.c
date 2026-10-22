// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

typedef enum {
	false = 0,
	true = 1
} bool;

// Implementare is_odd fara tipul bool
// int is_odd(int n) {
//     return n % 2 == 1;
// }

// implementare cu bool
bool is_odd(int n)
{
	return n % 2 == 1;
}

int main(void)
{
	printf("cast la int\n");
	bool b = false;
	printf("b = %d\n", b);
	printf("false = %d\n", false);
	printf("true = %d\n", false);

    // utilizare
	if (is_odd(21) == true) { // sau if (is_odd(21))
		printf("21 e impar\n");
	}

	if (is_odd(20) == false) { // if (!is_odd(21))
		printf("20 e par\n");
	}

	return 0;
}
