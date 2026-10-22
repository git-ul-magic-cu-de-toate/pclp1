#include <stdio.h>

int main(void)
{
	// operator atribuire: =
	int x1 = 10;
	const int c = 10;
	int sum;
	// ...
	sum = x1;
	sum = x1 + c;

	// operatori aritmetici: +, -, *, /
	int x = 10;
	int y = 10 / 2; // 5
	int z = 10 / 3; // 3 // [10 / 3]
	float f = 10 / 3; // 3.0
	printf("%7.3f\n", f); // va afisa cu 7 caractere "3"

	// cast-uri
	// float t = 1.0 * 10 / 3; // 3.333
	// float t = (float) 10 / 3; // 3.333
	float t = (float) (10 / 3); // 3.0
	// printf("%10.4f\n", t);

	
	// % = restul impartirii lui a la b
	int a = 10;
	int b = 3;
	printf("a %% b = %d\n", (a % b));
	// printf("\"Simona Halep\"\n");


	// ++, -- (ambele variante)
	// int a = 3;
	// a = a + 2; // 5
	// a = a + 1; // 6
	// postfixat: ++, --
	// a++; // 7
	// a--; // 6
	// prefixat: ++, ---
	// ++a; // 7;
	// --a; // 6
	// int copy_a_1 = a++; // copy_a_1 = 6, a = 7
	// int copy_a_2 = ++a; // a = 7, copy_a_2 = 7
	// a += 1; // a = a + 1;
	// a += 7; // a = a + 7;
	// a /= 3; // a = a / 3;

	// operator logici
	// conditie1 SI conditie2
	// && = SI logic
	// || = SAU logic
	// ! = NOT logic
	if (a % 3 == 0 || (a % 5 == 0 && a % 7 != 0)) {
		// ...
	}


	return 0;
}
