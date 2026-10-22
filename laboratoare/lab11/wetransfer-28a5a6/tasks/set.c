#include "set.h"

// Observatie: urmatoarele operatii sunt echivalente
// * n / 8 <=> n >> 3
// * n % 8 <=> n / 7
// In continuare se va folosi varianta cu operatii pe biti
// (bitwise operations ftw).

// is_set
// byte    - byte de intrare pentru care vreau sa verific un bit
// bit     - indexul bitului din byte
// @return - 1, daca bitul este 1
//           0, daca bitul este 0
int is_set(byte_t byte, int bit)
{
    byte_t mask = (1 << bit);
    return (byte & mask) != 0;
}
// alternativa: return (byte & (1 << bit)) != 0;

// set_bit
// byte    - byte de intrare pentru care vreau sa setez un bit
// bit     - indexul bitului din byte
// @return - noul byte
byte_t set_bit(byte_t byte, int bit)
{
    byte_t mask = (1 << bit);
    return (byte | mask);
}
// alternativa: return (byte | (1 << bit));

// reset_bit
// byte    - byte de intrare pentru care vreau sa resetez un bit
// bit     - indexul bitului din byte
// @return - noul byte
byte_t reset_bit(byte_t byte, int bit)
{
    byte_t mask = ~(1 << bit);
    return (byte & mask);
}
// alternativa: return (byte & (~(1 << bit)));

// is_in_set(s, n) - returneaza 1 daca n este in s, 0 altfel
int is_in_set(SET s, unsigned int n)
{
	int byte = (n >> 3);
	int bit = (n & 7);

	return is_set(s[byte], bit);
}

// insert_in_set(s,n) - adauga numarul n in multimea s
void insert_in_set(SET s, unsigned int n)
{
	int byte = (n >> 3);
	int bit = (n & 7);

	s[byte] = set_bit(s[byte], bit);
}

// delete_from_set(s,n) - scoate numarul n din multime s
void delete_from_set(SET s, unsigned int n)
{
	int byte = (n >> 3);
	int bit = (n & 7);

	s[byte] = reset_bit(s[byte], bit);
}

// delete_all_from_set(s) - elimina toate elementele din multime
void delete_all_from_set(SET s)
{
	// n este pe rand fiecare element care ar putea fi in s
	for (int n = 0; n < NMAX; ++n) {
		// sterg pe n din s (stergerea inseamna punerea unui 0;
		// daca elementul nu exista, voi pune 0 peste 0 => tot este corect)
		delete_from_set(s, n);
	}
}

// card_set(s) - returneaza cardinalul multimii s
int card_set(SET s)
{
	int card = 0; // card = cardinalul lui s

	// n este pe rand fiecare element care ar putea fi in s
	for (int n = 0; n < NMAX; ++n) {
		// daca i este in s, il numar
		if (is_in_set(s, n)) {
			card++;
		}
	}

	return card;
}


// is_empty_set(s) - returneaza 1 daca s = {}, 0 alfel
int is_empty_set(SET s)
{
	return card_set(s) == 0;
}

// print_set(s) - functia printeaza elementele multimii s
void print_set(SET s)
{
	// afisez mai intai cardinalul multimii:
	printf("multime cu %d elemente: ", card_set(s));

	// n este pe rand fiecare element care ar putea fi in s
	for (int n = 0; n < NMAX; ++n) {
		// daca i este in s, il afisez
		if (is_in_set(s, n)) {
			printf("%d ", n);
		}
	}

	printf("\n");
}

// read_set(s) - functia citeste numarul n de elemente care se afla in a
// apoi citeste cele n numere si le insereaza in a
// va returna numarul n citit (numarul de elemente)
int read_set(SET s)
{
	delete_all_from_set(s); // s = {}

	int num_elem;
	scanf("%d", &num_elem);

	for (int i = 0; i < num_elem; ++i) {
		int n;
		scanf("%d", &n);
		insert_in_set(s, n);
	}

	return num_elem;
}

// c = AUB
void merge_set(SET a, SET b, SET c)
{
	// trebuie sa construiesc o multime c = a U b
	// initial c = {}
	delete_all_from_set(c);

	// n este pe rand fiecare element care ar putea fi in a, b
	for (int n = 0; n < NMAX; ++n) {
		// i este in REUNIUNE daca este in a **SAU** in b
		if (is_in_set(a, n) || is_in_set(b, n)) {
			insert_in_set(c, n);
		}
	}
}

// c = AnB
void intersect_set(SET a, SET b, SET c)
{
	// trebuie sa construiesc o multime c = a n b
	// initial c = {}
	delete_all_from_set(c);

	// n este pe rand fiecare element care ar putea fi in a, b
	for (int n = 0; n < NMAX; ++n) {
		// i este in INTERSECTIE daca este in a **SI** in b
		if (is_in_set(a, n) && is_in_set(b, n)) {
			insert_in_set(c, n);
		}
	}
}

// c = a - b
void diff_set(SET a, SET b, SET c)
{
	// trebuie sa construiesc o multime c = a - b
	// initial c = {}
	delete_all_from_set(c);

	// n este pe rand fiecare element care ar putea fi in a, b
	for (int n = 0; n < NMAX; ++n) {
		// i este in DIFERENTA daca este in a **SI NU** este in b
		if (is_in_set(a, n) && !is_in_set(b, n)) {
			insert_in_set(c, n);
		}
	}
}
