// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

// Remarcati:
// 1. coding style
//	- nume enum => day_t (ca la structuri)
//	- numele unui element de tip enum
//		DEOARECE ESTE O CONSTANTA (ca un define), e cu majuscule
//
// 2. nu le dau neaparat valoare, vor primi cate un int automat
//
// Ce obtin deci? In loc sa folosesc numere pt zile si sa zic
// if (day == 1) {
//	   printf("E luni ma duc la facultate!\n");
// }
//
// o sa zic
//
// if (day == MONDAY) {
//	   printf("E luni ma duc la facultate!\n");
// }
// (e mai clar codul acum - iful ala verifica ca ziua e luni)

#include <stdio.h>

typedef enum {
	MONDAY,      // default: 0
	TUESDAY,     // 1
	WEDNESDAY,   // 2
	THURSDAY,    // 3
	FRIDAY,      // 4
	SATURDAY,    // 5
	SUNDAY       // 6
} day_t;

int main(void)
{
	printf("%d %d\n", MONDAY, SUNDAY);
	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./02-demo_enum_errors
// 0 6
// /
