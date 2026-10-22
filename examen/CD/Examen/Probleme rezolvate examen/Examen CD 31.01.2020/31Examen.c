#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	unsigned int param;
	unsigned int num;
	unsigned long long *termeni;
	unsigned long long *(*generator)(unsigned int, unsigned int);
} TSerie;

typedef struct {
	char *descriere;
	unsigned int numSerii;
	TSerie **serii;
} TColectie;

unsigned long long *generatorPrime(unsigned int, unsigned int);
unsigned long long *generatorFibo(unsigned int, unsigned int);
unsigned long long *generatorAritm(unsigned int, unsigned int);
unsigned long long *generatorGeom(unsigned int, unsigned int);

TSerie *alocaSerie(unsigned int num, unsigned int param) {
	TSerie *s = (TSerie *) calloc(1, sizeof(TSerie));

	if (!s) {
		fprintf(stderr, "Allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	s->param = param;
	s->num = num;

	switch (param << 24 >> 24) {
		case 0:
			s->generator = generatorPrime;
			break;
		case 1:
			s->generator = generatorFibo;
			break;
		case 2:
			s->generator = generatorAritm;
			break;
		default:
			s->generator = generatorGeom;
			break;
	}

	s->termeni = s->generator(param, num);

	return s;
}

TColectie *alocaColectie(unsigned int numSerii, unsigned int *numTerms) {
	TColectie *c = (TColectie *) calloc(1, sizeof(TColectie));

	if (!c) {
		fprintf(stderr, "Allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	c->numSerii = numSerii;

	c->serii = (TSerie **) calloc(numSerii, sizeof(TSerie *));
	if (!c->serii) {
		free(c);
		fprintf(stderr, "Allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	int param = 2 + 2 << 8 + 2 << 16;
	int i;
	for (i = 0; i < numSerii; i++) {
		c->serii[i] = alocaSerie(numTerms[i], param);
	}

	return c;
}

unsigned long long *generatorPrime(unsigned int param, unsigned int num) {
	unsigned long long *values = (unsigned long long *) calloc(num,
		sizeof(unsigned long long));

	if (!values) {
		fprintf(stderr, "Allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	int count = 0, i, ok;
	unsigned long long prime = 2;

	while (count < num) {
		ok = 1;
		for (i = 0; i < sqrt(prime); i++) {
			if (prime % i == 0) {
				ok = 0;
				break;
			}
		}

		if (ok == 1) {
			values[count++] = prime;
		}
		prime++;
	}

	return values;
}

unsigned long long *generatorFibo(unsigned int param, unsigned int num) {
	unsigned long long *values = (unsigned long long *) calloc(num,
		sizeof(unsigned long long));

	if (!values) {
		fprintf(stderr, "Allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	values[0] = 0;
	values[1] = 1;
	int i;
	for (i = 2; i < num; i++) {
		values[i] = values[i - 1] + values[i - 2];
	}

	return values;
}

unsigned long long *generatorAritm(unsigned int param, unsigned int num) {
	return NULL;
}

unsigned long long *generatorGeom(unsigned int param, unsigned int num) {
	return NULL;
}

void completeazaSiScrieDescriere(TColectie **colectie) {
	TColectie *c = *colectie;
	int i, j;
	unsigned long long sum;
	double avg;

	char *buffer = (char *) calloc(1000, sizeof(char));

	if (!buffer) {
		fprintf(stderr, "Allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	char types[4][20] = {
		"serie numere prime",
		"serie Fibonacci",
		"serie aritmetica",
		"serie geometrica"
	};

	for (i = 0; i < c->numSerii; i++) {
		sum = 0;
		for (j = 0; j < c->serii[i]->num; j++) {
			sum += c->serii[i]->termeni[j];
		}

		if (c->serii[i]->num) {
			avg = sum / (double) c->serii[i]->num;
		} else {
			avg = 0;
		}

		sprintf(buffer, "Seria %d de tip %s cu media %lf", i,
			types[c->serii[i]->param << 24 >> 24], avg);

		c->descriere = strdup(buffer);
	}

	free(buffer);

	FILE *f = fopen("out.txt", "w");

	for (i = 0; i < c->numSerii; i++) {
		fprintf(f, "%s\n", c->descriere);
	}

	fclose(f);
}

unsigned long long termenComun(TColectie **colectie) {
	TColectie *c = *colectie;

	unsigned long long common = -1;
	int i, j, k;

	for (i = c->serii[0]->num - 1; i >= 0; i--) {
		int ok = 1;
		for (j = 1; j < c->numSerii; j++) {
			int foundInCurrentTerms = 0;
			for (k = c->serii[j]->num - 1; k >= 0; k--) {
				if (c->serii[0]->termeni[i] == c->serii[j]->termeni[k]) {
					foundInCurrentTerms = 1;
					break;
				}
			}

			if (!foundInCurrentTerms) {
				ok = 0;
			}
		}

		if (ok) {
			common = c->serii[0]->termeni[i];
			break;
		}
	}

	return common;
}

void dezalocaColectie(TColectie **colectie) {
	int i;
	for (i = 0; i < (*colectie)->numSerii; i++) {
		
		if ((*colectie)->serii[i]->termeni) {
			free((*colectie)->serii[i]->termeni);
		}
		free((*colectie)->serii[i]);
	}

	free((*colectie)->serii);
	if ((*colectie)->descriere) {
		free((*colectie)->descriere);
	}
	free((*colectie));
	*colectie = NULL;
}

int main() {

	return 0;
}
