// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include  <stdio.h>

// TEORIE C:
// const e un keyword care face chestia pe care este aplicat sa fie constanta
// (adica nu o putem modifica - spune ca NU o putem SCRIE)
//      Ce inseamna READ?
//          Orice ii face o copie:
//          Ex. int x;
//                   y = x;
//                   printf("%d", x);
//                   z = x + 1;
//              (in toate cele 3 cazuri x se citeste)
//
//      Ce inseamna WRITE?
//         Orice ii modifica valoarea varibilei
//         Ex. int x;
//                  x = 2;
//                  x++;
//                  scanf("%d", &x);
//              (in toate cele 3 cazuri x e modificat)
// ATENTIE! Ce am zis mai sus e valabil pentru ORICE variabila.
//
//    Un pointer e o variabila, deci se aplica acelaesi reguli.
// int *p = ...;
// Ce inseamna READ pe pointer?   => q = p; sau printf("%p", p);
// Ce inseamna WRITE pe pointer?  => p = p + 10; sau ++p;
//    Un pointer indica catre adresa altei variabile (de obicei) - adica *p
// Ce inseamna  READ pe valoarea indicata de pointer?
//      =>  x = *p; sau printf("%d", *p);
// Ce inseamna WRITE pe valoarea indicata de pointer?
//      =>  *p = x; sau scanf("%d", p);

// const e un keyword care face chestia pe care este aplicat sa fie constanta
// REGULA: const se aplica pe PRIMA chestie de la stanga!!!,
//         daca nu exista o ia pe prima de la dreapta.
// Ex. int const *p; // p e un pointer variabil la un int constant
// Ex. const int *p; // p e un pointer variabil la un int constant

// urmati instructiunile din main
// dupa ce ati inteles ce face fiecare functie,
// consultati tabelul de la finalul fisierului

void test_variable_vs_const(void)
{
	int myvar = 0; // variabila
	myvar++;

	const int myconst = 0; // constanta
	// myconst++; // decomenteaza aceasta linie pentru eroare
	// eroare de compilare: increment of read-only variable ‘myconst’
	printf("pwp de la Gigel\n");
}

void test_pointer_to_variable(void)
{
	int v[5] = {0, 1, 2, 3, 4};

	int *p = v; // p este un pointer la un int
				// atat pointerul cat si valoare se pot modifica

	// modificare valoare
	*p = -1; // <=> v[0] == -1
	printf("%d\n", v[0]);

	// modificare pointer
	p++;     // acum p pointeaza catre v[1]
	*p = -2; // <=> v[1] == -2
	printf("%d\n", v[1]);
}

void test_pointer_to_const_value(void)
{
	int v[5] = {0, 1, 2, 3, 4};

	const int *p = v; // p este un pointer (care se poate modifica);
					  // el pointeaza la o valoare care nu se poate modifica

	printf("p = %p, *p = %d, &v[0] = %p, v[0] = %d\n", p, *p, &v[0], v[0]);
	// va afisa pe v[0]

	p++;

	printf("p = %p, *p = %d, &v[1] = %p, v[1] = %d\n ", p, *p, &v[1], v[1]);
	// va afisa pe v[1]

	//*p = 5;
	// eroare la compilare: error: assignment of read-only location ‘*p’
}

void test_const_pointer_to_variable(void)
{
	int v[5] = {0, 1, 2, 3, 4};

	int * const p = v; //  p pointeaza catre v[0]: p NU poate fi modificat,
					   // valoarea indicata de p DA!
	// p++;
	// eroare la compilare: error: increment of read-only variable ‘p’
	printf("p = %p, *p = %d, &v[0] = %p, v[0] = %d\n", p, *p, &v[0], v[0]);
	*p = 40; // v[0] = 40, cat ati luat la partial :D
	printf("p = %p, *p = %d, &v[0] = %p, v[0] = %d\n ", p, *p, &v[0], v[0]);
}

void test_const_pointer_to_const_value(void)
{
	int v[5] = {123, 1, 2, 3, 4};

	const int * const p = v;

	// singurele operatii pe care am voie sa le fac cu p
	printf("%p %p\n", p, &v[0]);
	printf("%d %d\n", *p, v[0]);

	// p++;       // error: increment of read-only variable ‘p’
	// *p = 0;    // error: assignment of read-only location ‘*p
}

int main(void)
{
	printf("Decomenteaza pe rand cate un apel de functie din main!\n");

	// test_variable_vs_const();
	// test_pointer_to_variable();
	// test_pointer_to_const_value();
	// test_const_pointer_to_variable();
	// test_const_pointer_to_const_value();

	return 0;
}

//  int v;
//  const int c;
//  | |  READ (ceva = c/v)  |  WRITE (c/v =  ceva)  |
//  |v|         DA          |           DA          |
//  |c|         DA          |           NU          |
//
// Concluzie: O variabila simpla pe care s-a pus const se poate doar citi.
//
//  int x;
//  int *p              = &x;
//  const int *q1       = &x;
//  int const *q2       = &x;
//  int *const r        = &x;
//  const int *const s1 = &x;
//  int const *const s2 = &x;
//
//  |  |  READ_PTR  |  WRITE_PTR  |||  READ_VALUE |  WRITE_VALUE |
//  |  |(ceva = ptr)|(ptr =  ceva)|||(ceva = *ptr)|(*ptr =  ceva)|
//  | p|     DA     |      DA     |||     DA      |      DA      |
//  |q1|     DA     |      DA     |||     DA      |      DA      |
//  |q2|     DA     |      DA     |||     DA      |      DA      |
//  | r|     DA     |      NU     |||     DA      |      NU      |
//  |s1|     DA     |      NU     |||     DA      |      NU      |
//  |s2|     DA     |      NU     |||     DA      |      NU      |
//
//  Concluzie 1: Daca ptr este un pointer la un tip constant,
//               nu putem modifica valoarea indicata.
//  Concluzie 2: Daca ptr este un pointer constant, nu il putem schimba
//               (ex. nu il putem muta sa pointeze catre altceva.)
//
