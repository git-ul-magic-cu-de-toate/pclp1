#include <stdio.h>
#include "set.h"

int main(void)
{
	SET a, b, c; // declar 3 multimi <=> declar 3 vectori

	// a = {}
	delete_all_from_set(a);
	if (is_empty_set(a)) {
		printf("a = {}\n");
	}

	// a = {1, 2, 3, 4, 5, 6, 7};
	for (int i = 1; i <= 7; ++i) {
		// adaug pe i in a
		insert_in_set(a, i);
	}

	// afisez a
	printf("a => ");
	print_set(a); // Multime cu 7 elemente: 1 2 3 4 5 6 7

	// sterg pe 4 si afisez a
	delete_from_set(a, 4);
	if (is_in_set(a, 4)) {
		printf("delete_from_set merge prost! 4 nu ar trebui sa mai fie in a\n");
	}
	printf("a => ");
	print_set(a); // Multime cu 6 elemente: 1 2 3 5 6 7

	// am testat insert, delete, has, print, card (folosit in print), empty

	// construim alte 2 multimi a si b
	delete_all_from_set(a);
	delete_all_from_set(b);
	if (is_empty_set(a)) {
		printf("a = {}\n");
	}
	if (is_empty_set(b)) {
		printf("b = {}\n");
	}

	// a = {1, 10, 100, 500}
	insert_in_set(a, 1);
	insert_in_set(a, 10);
	insert_in_set(a, 100);
	insert_in_set(a, 500);
	printf("a => ");
	print_set(a);

	// a = {10, 55, 100, 200}
	insert_in_set(b, 10);
	insert_in_set(b, 55);
	insert_in_set(b, 100);
	insert_in_set(b, 200);
	printf("b => ");
	print_set(b);

	merge_set(a, b, c);
	printf("a u b => ");
	print_set(c);

	intersect_set(a, b, c);
	printf("a n b => ");
	print_set(c);

	diff_set(a, b, c);
	printf("a - b => ");
	print_set(c);

	diff_set(b, a, c);
	printf("b - a => ");
	print_set(c);

	return 0;
}


// Compile:
// $ make
//
// Run:
// $ ./set
// a = {}
// a => multime cu 7 elemente: 1 2 3 4 5 6 7
// a => multime cu 6 elemente: 1 2 3 5 6 7
// a = {}
// b = {}
// a => multime cu 4 elemente: 1 10 100 500
// b => multime cu 4 elemente: 10 55 100 200
// a u b => multime cu 6 elemente: 1 10 55 100 200 500
// a n b => multime cu 2 elemente: 10 100
// a - b => multime cu 2 elemente: 1 500
// b - a => multime cu 2 elemente: 55 200
//
