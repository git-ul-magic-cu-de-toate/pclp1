// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

#include "util.h"

// Functie care interschimba valorile a doua variabile de tip int.
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
