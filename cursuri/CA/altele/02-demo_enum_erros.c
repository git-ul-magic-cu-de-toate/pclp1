// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

//     Un exemplu real-life.
//     Facem o aplicatie in C. O aplicatie in C este un program, deci
// are un int main() { ... return cod_eroare; }.
//
//     Pentru ca din exterior sa stim ca aplicatia s-a terminat cu succes,
// va trebui ca aplicatia noastra sa returneze anumite valori in main:
//     0 => [SUCCES] executie cu success
//    1 => [EROARE] lucru cu fisiere
//    2 => [EROARE] eroare de conectare la retea
//    3 => [EROARE] pointerul care indica catre datele primite este NULL
//                   (nu am date)
//
//    ... si putem extinde lista oricand
//
//    Daca noi o sa punem prin main
//
//    ...
//			return 1;
//
//    ...
//			return 2;
//
//    ...
//			return 1;
//
//    return 0;
//
//    ...
//			return 2;
//
//    ...
//			return 1;
//
//    ...
//			return 2;
//						return 3;
//
//     return 0;
//
//     De fiecare data cand citim codul si vedem de exemplu
//     3 trebuie sa ne aducem aminte ce inseamna "return 3;"
//     ca si logica...
//
//     Problema: Daca lista de coduri de erori e mare? ce fac?
//     Clar nu ma apuc sa memorez, mai ales ca e posibil sa incurc numerele.
//
//     Solutie => ENUM

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	SUCCESS = 0,            // executie cu success
	ERROR_FILE_SYS = 1,     // eroare de lucru cu sistemul de fisiere
	ERROR_NETWORK_CONN = 2, // eroare de lucru cu reteaua (ex. sockets)
	ERROR_NULL_PTR = 123,   // eroare de lucru cu pointeri (pointer NULL)
	ERROR_MEM_ALLOC = 4     // eroare la alocare de memorie
} error_t;

int send_array(void *v, int n)
{
    // incearca sa trimiti pe retea
	if (1) {
		// aici presupun ca verificam asta si constatam ca nu pot trimite
		return ERROR_NETWORK_CONN;
	}

    // fac asta doar sa scap de warning ca nu folsoesc variabilele :D
	v = v;
	n = n;
    // e o functie care doar arata cum folosesc enum, altfel ea nu are sens

	return SUCCESS;
}

int main(void)
{
	int status = SUCCESS;

	int n = 10;

    // incerc sa aloc un vector cu n elemente
	int *v = malloc(n * sizeof(int));
	if (!v) {
		return ERROR_MEM_ALLOC;
	}

    // populez vectorul
	for (int i = 0; i < n; ++i) {
		v[i] = i; // nu conteaza valoarea
	}

    // salvez vectorul in fisier
	FILE * file_descriptor = fopen("gigel.in", "w");
	if (!file_descriptor) {
		return ERROR_FILE_SYS;
	}

	for (int i = 0; i < n; ++i) {
		fprintf(file_descriptor, "%d\n", v[i]);
	}
	fclose(file_descriptor);

    // incearca sa il trimit pe retea
	status = send_array(v, n);
    // sa returneze daca s-a executat cu SUCCESS sau cu ERROR_*

    // daca nu ai putut opreste programul
	if (status != SUCCESS) {
		free(v);
		return status;
	}

    // daca ai putut, atunci mai fa alte nebunii
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...
    // ...

	free(v);
	return status;
}

// Compile:
// $ make
//
// Run:
// ./02-demo_enum_errors
//
