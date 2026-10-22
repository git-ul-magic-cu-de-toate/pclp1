/* poli_rar.c, Created on: 02.02.2012, Author: Florin Pop */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
	double c;
	int ex;
} termen;

typedef struct {
	int nn;
	int grd;
	termen *t;
} polinom_rar;

/**
 * Functiile 'newPoly' si 'init' au rolul de a initializa fisierul de intrare
 * pentru testarea programului. Ele nu fac parte din solutia problemei.
 */
polinom_rar *newPoly(int ntn, int g, ...) {
	va_list ap;
	int i;
	polinom_rar *p = (polinom_rar *)malloc(sizeof(polinom_rar));
	p->nn = ntn;
	p->grd = g;
	p->t = (termen *)malloc(ntn * sizeof(termen));
	va_start(ap, g);
	for (i = 0; i < ntn; ++i) {
		p->t[i].c = va_arg(ap, double);
		p->t[i].ex = va_arg(ap, int);
	}
	va_end(ap);
	return p;
}

void init(char *filename) {
	FILE *f;
	int i;
	polinom_rar *p[8] = {
		newPoly(3, 2012, 1.0, 2012, -2.0, 1, 2013.0, 0),
		newPoly(2, 10, 1.0, 10, 1.0, 1),
		newPoly(5, 4, 1.0, 4, 1.0, 3, 1.0, 2, 1.0, 1, 1.0, 0),
		newPoly(4, 4, 1.0, 4, 1.0, 3, 1.0, 2, 1.0, 1),
		newPoly(3, 4, 1.0, 4, 1.0, 3, 1.0, 2),
		newPoly(2, 4, 1.0, 4, 1.0, 3),
		newPoly(1, 4, 1.0, 4),
		newPoly(11, 9, 1.0, 10, 1.0, 9, 1.0, 8, 1.0, 7, 1.0, 6,
				1.0, 5, 1.0, 4, 1.0, 3, 1.0, 2, 1.0, 1, 1.0, 0)
	};
	if ((f = fopen(filename, "wb")) == NULL) {
		fprintf(stderr, "Error: creating file.\n");
		return;
	}
	for (i = 0; i < 8; i++) {
		fwrite(&(p[i]->nn), sizeof(int), 1, f);
		fwrite(&(p[i]->grd), sizeof(int), 1, f);
		fwrite(p[i]->t, sizeof(termen), p[i]->nn, f);
	}
	fclose(f);
}

long pozitie(int ni, int *n_termeni) {
	int i;
	long d = 0;
	for (i = 0; i < ni; d += n_termeni[i++]);
	return 2 * ni * sizeof(int) + d * sizeof(termen);
}

int main(int argc, char *argv[]) {
	/* declararea de variabile */
	FILE *fin;
	int np = 0, ni, poz_pi, ntn, i, j;
	polinom_rar p;
	int *n_termeni = (int *)calloc(1, sizeof(int));

	init(argv[1]); /* se creeaza un fisier de intrare */

	/* validarea numarului de parametri si deschiderea fisierului de intrare */
	if (argc <= 2) {
		fprintf(stderr, "usage: %s file n1 n2 ...\n", argv[0]);
		return -1;
	}
	if ((fin = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "File %s is not readable.\n", argv[1]);
		return -1;
	}

	/* determinarea nr. de polinoame si a nr. de termeni pt fiecare polinom */
	while (fread(&ntn, sizeof(int), 1, fin)) {
		np++;
		n_termeni = realloc(n_termeni, np * sizeof(int));
		n_termeni[np - 1] = ntn;
		fseek(fin, sizeof(int) + ntn * sizeof(termen), SEEK_CUR);
	}

	/* afisarea polinoamelor specificate in linia de comanda */
	for (i = 2; i < argc; i++) {
		ni = atoi(argv[i]) - 1; /* numerotam de la zero */

		/* determinam pozitia si ne pozitionam in fisier */
		poz_pi = pozitie(ni, n_termeni);
		fseek(fin, poz_pi, SEEK_SET);
		/* alocam memoria si citim polinomul */
		p.t = (termen *)malloc(n_termeni[ni] * sizeof(termen));
		fread(&(p.nn), sizeof(int), 1, fin);
		fread(&(p.grd), sizeof(int), 1, fin);
		fread(p.t, sizeof(termen), n_termeni[ni], fin);

		/* afisam polinomul */
		for (j = 0; j < n_termeni[ni]; j++) {
			printf(" + %.2lf * x^%d", p.t[j].c, p.t[j].ex);
		}
		printf("\n");
		/* eliberam memoria pentru a pregati urmatorul polinom */
		free(p.t);
	}
	/* inchidem fisierul de intrare si eliberam memoria */
	fclose(fin);
	free(n_termeni);
	return 0;
}
