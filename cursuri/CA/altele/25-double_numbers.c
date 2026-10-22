// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#define NMAX 100

int main(void)
{
	// numele fisierului de intrare
	char input_filename[] = "25-double_numbers.in";

	// deschidere fisier de intrare pentru
	// citire (r) in modul binar (b)
	FILE *in = fopen(input_filename, "rb");
	// verific daca fisierul a fost deschis cu succes
	// altfel opresc executia (in cazul acestei probleme)
	if (!in) {
		fprintf(stderr, "ERROR: Can't open file %s\n", input_filename);
		return -1;
	}

	// numarul de elemente si vectorul
	int n, v[NMAX];

	// citesc n din fisier, apoi citesc tabloul
	fread(&n, sizeof(int), 1, in);
	fread(v, sizeof(int), n, in);

	// deoarece stiu sigur ca nu mai am nimic de citit
	// pot inchide fisierul de intrare
	fclose(in);

	// dublez elementele din vector
	for (int i = 0; i < n; ++i) {
		v[i] *= 2;
	}

	// deschid fisierul pentru a scrie rezultatele
	char output_filename[] = "25-double_numbers.out";
	// deschid pentru scriere (w) in modul binar (b)
	FILE *out = fopen(output_filename, "wb");
	// verific daca fisierul a fost deschis cu succes
	// altfel opresc executia (in cazul acestei probleme)
	if (!out) {
		fprintf(stderr, "ERROR: Can't open file %s\n", output_filename);
		return -1;
	}

	// scriu n in fisier, apoi tabloul
	fwrite(&n, sizeof(int), 1, out);
	fwrite(v, sizeof(int), n, out);

	// inchid fisierul de iesire
	fclose(out);

	return 0;
}

// Compile:
// $make
//
// Run:
// $ ./07-double_numbers
//
// Check:
// $ hexdump -C 07-double_numbers.in
// 00000000  07 00 00 00 02 00 00 00  ff 45 00 00 00  |............E...|
// 00000010  40 00 00 00 20 00 00 00  00 04 00 00 f6 ff  |@... ...........|
// 00000020
// $ hexdump -C 07-double_numbers.out
// 00000000  07 00 00 00 04 00 00 00  fe ff 8a 00 00 00  |................|
// 00000010  80 00 00 00 40 00 00 00  00 08 00 00 ec ff  |....@...........|
// 00000020
//
// Hint:
//      04-double_numbers.in <=> 07-double_numbers.in
//      04-double_numbers.out <=> 07-double_numbers.ref
//
// 32bits intergers
// 2 conventions:
// - https://en.wikipedia.org/wiki/Two%27s_complement
// - https://en.wikipedia.org/wiki/Ones%27_complement
//
// The used representation is 2's complement:
// - positive value n: binary simple representation
// - negative value n: ~|n| + 1
//
//  1 = 0x00.00.00.01
// 69 = 0x00.00.00.45
//
// -1 = 0xFF.FF.FF.FF
//		-1 => 1 = 00000000.00000000.00000000.00000001
//			 ~1 = 11111111.11111111.11111111.11111110
//	     ~1 + 1 = 11111111.11111111.11111111.11111111
//	              1111|1111.1111|1111.1111|1111.1111|1111
//					F   F    F     F   F     F    F   F
//
// -2 = 0xFF.FF.FF.FE
//		-2 => 2 = 00000000.00000000.00000000.00000010
//			 ~2 = 11111111.11111111.11111111.11111101
//	     ~2 + 1 = 11111111.11111111.11111111.11111110
//	              1111|1111.1111|1111.1111|1111.1111|1110
//					F   F    F     F   F     F    F   E
//
//
// -10 = 0XFF.FF.FF.F6
//	  10 = 0X00.00.00.0A
//   ~10 = 0XFF.FF.FF.F5
// ~10+1 = 0XFF.FF.FF.F6
//
// -20 = 0XFF.FF.FF.F6
//	  20 = 0X00.00.00.14
//   ~10 = 0XFF.FF.FF.EB
// ~10+1 = 0XFF.FF.FF.EC
//
