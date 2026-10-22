// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <math.h>
#define M_PI 3.14

// Aceasta sursa introduce o notiune noua, care va fi studiata peste cateva
// laboratoare. Se recomanda parcurgerea acestui material dupa acel laborator.

// sa presupunem ca vrem sa afisam functia sin pentru valori intre 0 si 180
// din X in X grade
// scriem un cod care apeleaza sin intr-un for

// sa presupunem ca vrem sa afisam fucntia cos pentru valori intre 0 si 180
// din X in X graade
// scriem un cod care apeleaza cos intr-un for

// sa presupunem ca vrem sa afisam fucntia tan pentru valori intre 0 si 180
// din X in X graade
// scriem un cod care apeleaza tan intr-un for

// Cele 3 exemple de mai sus practic vor reprezenta acelasi cod,
// doar ca apeland sin/cos/tan

// Ce se intampla daca vrem sa printam pentru toate func_t trig?
// Ce se intampla daca vrem sa facem asta pentru 1000 de functii care primesc
// un double si returneaza un double?
//      Copiam de 1000 de ori codul... nu e modularizare
// In schimb putem face o func_ttie in care sa facem forul si care primeste
// ca parametru alta functie.
//       Prima func_ttie va apela functia data ca parametru.
// suna cool... hai sa vedem cum facem.

// tipul func_t e un pointer la o functie care
//     - primeste un parametru double x
//     - returneaza un double
typedef double (*func_t)(double x);

// functia sare din step in step grade intre a si b
// si pentru fiecare punct atins
// printeaza valoarea functiei f in acel punct
// (aici functia primeste parametru in radiani)
void func_t_trig_print(double a, double b, double step, func_t f, char *name)
{
	printf("===== >%s:\n", name);

	for (double x = a; x <= b; x += step) {
		double x_rad = x * M_PI / 180.0;
		printf("%s(%2.3f) = %2.3f\n", name, x, f(x_rad));
	}
}

// functia sare din step in step grade intre a si b
// si pentru fiecare punct atins
// printeaza valoarea functiei f in acel punct
void func_t_print(double a, double b, double step, func_t f, char *name)
{
	printf("===== >%s:\n", name);

	for (double x = a; x <= b; x += step) {
		printf("%s(%2.3f) = %2.3f\n", name, x, f(x));
	}
}

void test_func_t_ptr(void)
{
	//  sa zicem ca vrem sa folosim fucntia func_t_trig_print
	// pt a afisa pe ecran f(x)
	// x =  a, a + step, a + 2*step, ..., b

	// vreau ca x sa fie 0, 15, 30, 45, 60, 75, 90
	double a  = 0, b = 90, step = 15;

	// f == log10
	// hai sa afisam pe ecran
	// log10(1) ,log10(2), ... log10(100)
	// daca avem toate punctele (x, log10(x))
	// cand o sa invatati Matlab o sa puteti sa trasati
	// graficul func_ttiei log10
	func_t_print(1, 10, 1, log10, "log10");

	// f == sin
	// analog, doar ca apelam func_t_trig_print
	// care in plus transforma gradele in radieni
	func_t_trig_print(a, b, step, sin, "sinus");

	// f == cos
	// analog, doar ca apelam func_t_trig_print
	// care in plus transforma gradele in radieni
	func_t_trig_print(a, b, step, cos, "cosinus");
}

void test_array_of_func_t_ptr(void)
{
	// presupun ca ati inteles deja test_func_t_ptr
	// cum facem daca vrem sa printam rezultatele pentru multe functii?
	// ex: sin, cos, tg, ctg etc
	// SOLUTIE: facem un vector de pointeri la functii
	// http://www.cplusplus.com/reference/cmath/
	int n = 3;
	func_t f_trig[] = {sin, cos, tan};
	static const char * const name_trig[] = {"sinus", "cosinus", "tangenta"};

	double a = 15, b = 75, step = 15;
	for (int i = 0; i < n; ++i) {
		func_t_trig_print(a, b, step, f_trig[i], name_trig[i]);
	}
}

int main(void)
{
	test_func_t_ptr();

	// o solutie in care am modularizat mai mult
	// test_array_of_func_t_ptr();

	return 0;
}
