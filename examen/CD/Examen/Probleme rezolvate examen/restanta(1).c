#include <stdio.h>
#include <stdlib.h>

/****a****/
typedef struct TPers {
	unsigned int id;
	char *nume;
} TPers;

typedef struct {
	TPers *pers;
	char rol;
} TRol;

typedef struct TFilm {
	TRol roluri[50];
	int nrCrtActori;
	char *numeFilm;
} TFilm;

typedef struct TColectie {
	TPers *pers;
	TFilm *filme;
	int nrCrtActori, nrCrtFilme, nrMaxActori, nrMaxFilme;
} TColectie;


/****b****/
TColectie* allocColectie (int nrMaxActori, int nrMaxFilme) {
	TColectie* c = (TColectie*)malloc(sizeof(TColectie));
	c->pers = (TPers*)malloc(nrMaxActori * sizeof(TPers));
	c->filme = (TFilm*)malloc(nrMaxFilme * sizeof(TFilm));
	c->nrMaxActori = nrMaxActori;
	c->nrMaxFilme = nrMaxFilme;
	c->nrCrtActori = c->nrCrtFilme = 0;

	return c;
}

/****c****/
void adaugaRol (TFilm* f, TPers* p, char rol) {
	f.roluri[p->id].rol = rol;
}

/****d****/
TPers* cautaActorRegizor (TColectie* c, int* nrPers) {
	// vectorul de pointeri returnat cu persoanele care indeplinesc conditia
	TPers* indeplineste = (TPers*)malloc(c->nrMaxActori * sizeof(TPers));

	int i, j, k=0;
	char rolCurent;
	char masque = 3; //0000 0011

	for (i=0; i < c->nrCrtFilme; i++) {
		for (j=0; j < 50; j++) {

			char rolCurent = c->filme[i]->roluri[j].rol;
			TPers* persCurenta = c->filme[i].roluri[j].pers;

			if ( rolCurent & masque == masque ) {
				indeplineste[k] = persCurenta;
				k++;
			}
		}
	}

	*nrPers = k;
	return indeplineste;

}

/****e****/
int AddRegizor (TColectie* c, TFilm* f, unsigned int id) {
	int i;

	for (i = 0; i < c->nrCrtActori; i++) {
		if (c->pers[i].id == id)
			break;
	}

	if ( i == c->nrCrtActori )
		return 0;

	char masque2 = 2; // 0000 0010
	f.roluri[i].rol = f.roluri[i].rol | masque2;

	return 1;
} 

int eliminaPers(TColectie* c, int (*fcond)(TPers*)) {

	int i,j,k;

	for ( i = 0; i < c->nrCrtActori; i++) {
		if ( (*fcond)(c->pers[i]) != 0 ) {

			//eliminarea din toate rolurile (mi-e lene sa fac inca o functie)
			for (j = 0; j < c->nrCrtFilme; j++) {
				for( k = 0; k < c->filme[j].nrCrtActori; k++) {
				
					if ( c->filme[j].roluri[k].pers == c->pers[i] ) {

						c->filme[j].roluri[k].pers = NULL;
						c->filme[j].roluri[k].rol = 0;
					}
				}
			}

			//eliminarea din colectie
			c->pers[i] = c->pers[i+1];

			return 1;
		}
	}


	return 0;
}
	

void destroy (TColectie* c) {

	int i;
	for ( i = 0; i < c->nrCrtFilme; i++)
		free(c->filme[i]);
	free(c->pers);
}














