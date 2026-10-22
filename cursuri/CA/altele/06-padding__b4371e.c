// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

// Intrebare:
//     sizeof(structura) == sizeof(membru_1) + ... + sizeof(membru_n) ?
// Raspuns: depinde daca avem sau nu padding!
// Urmatoarele exemple sunt rulate pe arhitectura 64-bit.
//

typedef struct {
	int n; // 4B
} a_t;
// sizeof(a_t) = 4B

typedef struct {
	char n; // 1B
} b_t;
// sizeof(b_t) = 1B

typedef struct {
	char x; // 1B
	int y;	// 4B
	char z; // 1B
} wtf_a_t;
// sizeof(wtf_a_t) = 12B

typedef struct {
	int y;	// 4B
	char z; // 1B
	char x; // 1B
} wtf_b_t;
// sizeof(wtf_b_t) = 8B

typedef struct {
	int y;	// 4B
	char z; // 1B
	char x; // 1B
	char o; // 1B
} wtf_c_t;
// sizeof(wtf_c_t) = 8B

typedef struct {
	int n;	  // 4B
	double q; // 8B
	char x;	  // 1B
} wtf_d_t;
// sizeof(wtf_e_t) = 24B

typedef struct {
	char z;	  // 1B
	int n;	  // 4B
	char x;	  // 1B
	double q; // 8B
} wtf_e_t;
// sizeof(wtf_e_t) = 24B

typedef struct {
	double q; // 8B
	int n;	  // 4B
	char z;	  // 1B
	char x;	  // 1B
} wtf_f_t;
// sizeof(wtf_f_t) = 16B

int main(void)
{
	printf("sizeof(%s) = %zu bytes\n", "a_t", sizeof(a_t));
	printf("sizeof(%s) = %zu bytes\n", "b_t", sizeof(b_t));
	printf("sizeof(%s) = %zu bytes\n", "wtf_a_t", sizeof(wtf_a_t));
	printf("sizeof(%s) = %zu bytes\n", "wtf_b_t", sizeof(wtf_b_t));
	printf("sizeof(%s) = %zu bytes\n", "wtf_c_t", sizeof(wtf_c_t));
	printf("sizeof(%s) = %zu bytes\n", "wtf_d_t", sizeof(wtf_d_t));
	printf("sizeof(%s) = %zu bytes\n", "wtf_e_t", sizeof(wtf_e_t));
	printf("sizeof(%s) = %zu bytes\n", "wtf_f_t", sizeof(wtf_f_t));
	return 0;
}
