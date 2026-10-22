/* sort.c, Created on: 13.01.2012, Author: Florin Pop */

#include <stdio.h>
#include <stdlib.h>

int allDone(int n, int *buffer){
	int i;
	for(i=0; i<n; i++){
		if(buffer[i]==0){ return 0; }
	}
	return 1;
}

int minIndex(int n, long *buffer, int *done){
	int i, j=0;
	for(i=0; i<n && done[i]; i++);
	for(j=i; i<n; i++){
		if(!done[i] && buffer[i] < buffer[j]){
			j = i;
		}
	}
	return j;
}

int main(int argc, char *argv[]){

	int filesNo, *done, i, j;
	long *buffer;
	FILE **files, *output;

	if(argc < 3){
		fprintf(stderr, "Usage: %s file_1 file_2 ... file_n output.bin\n", argv[0]);
		return -1;
	}

	filesNo = argc - 2;

	if((files=(FILE **)malloc(filesNo * sizeof(FILE *))) == NULL){
		fprintf(stderr, "Error: Out of memory.");
		return -1;
	}
	if((buffer=(long *)malloc(filesNo * sizeof(long))) == NULL){
		fprintf(stderr, "Error: Out of memory.");
		return -1;
	}
	if((done=(int *)calloc(filesNo, sizeof(int))) == NULL){
		fprintf(stderr, "Error: Out of memory.");
		return -1;
	}
	if((output=fopen(argv[argc-1],"wb"))==NULL){
		fprintf(stderr, "Error: Unable to create output file: %s.", argv[argc-1]);
		return -1;
	}

	for(i=0; i<filesNo; i++){
		if((files[i]=fopen(argv[i+1],"rb"))==NULL){
			fprintf(stderr, "Error: Unable to open input file: %s.", argv[i+1]);
			return -1;
		}
		fread(&buffer[i], 1, sizeof(long), files[i]);
	}

	while(1){
		if(allDone(filesNo, done)) break;

		j = minIndex(filesNo, buffer, done);
		fwrite(&buffer[j], 1, sizeof(long), output);

		if(fread(&buffer[j], 1, sizeof(long), files[j])==0){
			done[j]=1;
			fclose(files[j]);
		}
	}

	free(buffer); free(done); free(files);
	fclose(output);

	return 0;
}
