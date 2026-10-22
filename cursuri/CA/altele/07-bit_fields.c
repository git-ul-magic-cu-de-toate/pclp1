// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

typedef struct __attribute__((packed)) {
	unsigned char day; // 1B
	unsigned char month; // 1B
	unsigned short int year; // 2B
	unsigned char is_bisect; // 1B
} day_t;
// sizeof(day_t) = 1 + 1 + 2 + 1 = 5B

typedef struct __attribute__((packed)) {
	unsigned char day : 5; // 1-31 -> 5 bits
	unsigned char month : 4; // 1-12 -> 4 bits
	unsigned short int year : 12; // 0-4095 -> 12 bits
	unsigned char is_bisect : 1; // 0-1 -> 1 bit
} day_bits_t;
// sizeof(day_t) in bits = 5 + 4 + 12 + 1 = 22 = 2 * 8 + 6 -> 3B
// sizeof(day_t) = 3B

int main(void)
{
	printf("sizeof(%s) = %lu\n", "day_t", sizeof(day_t));
	printf("sizeof(%s) = %lu\n", "day_bits_t", sizeof(day_bits_t));
	return 0;
}

// Compile:
// $ make
//
// Run:
// $ ./07-bit_fields
// sizeof(day_t) = 5
// sizeof(day_bits_t) = 3
//
// Homework: Run with padding.
//
