/* index.c, Created on: 02.02.2012, Author: florinpop */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 100

struct art_cuv {
	int l;			/* lungime cuvant (m<=l<=15)	*/
	char cuv[15];	/* cuvant extras din text		*/
};

int main(int argc, char *argv[]){
	/* declaratia variabilelor */
	int m, n, p;
	FILE *fin, *fout, *f1, *f2;
	char input_file[15], output_file[15];
	char delim[]=" .,:;-\n";
	char line[MAX_LINE], *pcv;
	struct art_cuv a, b;
	int freq, done;

	/* prelucrarea parametrilor liniei de comanda */
	if(argc != 5) {
		fprintf(stderr, "usage: %s text_file n m p\n", argv[0]);
		return -1;
	}
	strcpy(input_file, argv[1]);
	m = atoi(argv[2]);
	n = atoi(argv[3]);
	p = atoi(argv[4]);

	/* formarea numelui fisierului de iesire, cu extensia .idx */
	memset(output_file, 0, 15);
	char *pct = strchr(input_file, '.');
	if (pct) {
		strncpy(output_file, input_file, pct - input_file);
	} else {
		strcpy(output_file, input_file);
	}
	strcat(output_file, ".idx");

	/* deschiderea fisierului de intrare si crearea fisierelor temporare f1 si f2 */
	if ( (fin = fopen(input_file, "rt")) == NULL ){
		fprintf(stderr, "File %s is not readable.\n", input_file);
		return -1;
	}
	if ( (f1 = fopen("f1", "w+b")) == NULL ){
		fprintf(stderr, "Error: creating temporary file.\n");
		return -1;
	}
	if ( (f2 = fopen("f2", "w+b")) == NULL ){
		fprintf(stderr, "Error: creating temporary file.\n");
		return -1;
	}

	/* separarea cuvintelor si scrierea articolelor in fisierul temporar f1 */
	while(!feof(fin)){
		fgets(line, MAX_LINE, fin);
		for(pcv = strtok(line, delim); pcv; pcv = strtok(NULL, delim)){
			a.l = strlen(pcv);
			if(a.l >= m && a.l <= n){
				memset(a.cuv, 0, 15); strcpy(a.cuv, pcv);
				fwrite((char *)&a, sizeof(struct art_cuv), 1, f1);
			}
		}
	}
	fclose(fin);

	/* crearea fisierului de iesire */
	if ( (fout = fopen(output_file, "wb")) == NULL ){
		fprintf(stderr, "Error: creating %s file.\n", output_file);
		fclose(f1); fclose(f2);
		return -1;
	}

	/* prelucrarea cuvintelor din f1 cu ajutorul lui f2 */
	fseek(f1, 0, SEEK_SET);
	while( fread((char *)&a, sizeof(struct art_cuv), 1, f1) ){
		done = 0;
		int pos = ftell(f1); /* pastram pozitia curenta */

		/* cautam cuvantul in fisierul de iesire */
		fseek(f2, 0, SEEK_SET);
		while(fread(&b, sizeof(struct art_cuv), 1, f2)){
			fread(&freq, sizeof(int), 1, f2); /* citire in gol */
			if(!strcmp(a.cuv, b.cuv)){
				done = 1; break;
			}
		}
		/* daca a fost deja prelucrat, trecem la urmatorul cuvant */
		if(done) continue;

		/* daca nu a fost gasit, numaram cate aparitii ale cuvantului sunt in f1 */
		fseek(f1, 0, SEEK_SET);
		freq = 0;
		while(fread(&b, sizeof(struct art_cuv), 1, f1)) {
			if(!strcmp(a.cuv, b.cuv)) freq++;
		}
		/* adaugam cuvantul si frecventa lui in f2 */
		fseek(f2, 0, SEEK_END);
		fwrite(&a, sizeof(struct art_cuv), 1, f2);
		fwrite(&freq, sizeof(int), 1, f2);

		/* continuam citirea urmatorului cuvant */
		fseek(f1, pos, SEEK_SET);
	}
	fclose(f1);

	/* extragem din f2 cuvintele cu freq >= p si le scriem in fisierul de iesire */
	fseek(f2, 0, SEEK_SET);
	while(fread(&a, sizeof(struct art_cuv), 1, f2)){
		fread(&freq, sizeof(int), 1, f2);
		if(freq>=p){
			fwrite(&a, sizeof(struct art_cuv), 1, fout);
			fwrite(&freq, sizeof(int), 1, fout);
			printf("%s - %d\n",a.cuv,freq);
		}
	}
	/* inchidem fisierele */
	fclose(f2); fclose(fout);
	return 0;
}
