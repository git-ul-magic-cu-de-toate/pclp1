#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "compilatie.h"


int main(int argc, char *argv[])
{
	char *fin_name, *fout_name, *f_name, line[LINE_SIZE], *p;
	FILE *fin, *fout, *f, *tmp_file;
	int index, cnt, no_of_files = 0;

	fin_name = argv[1];
	if ((fin=fopen(fin_name, "r")) == NULL) {
		fprintf(stderr, "Error! Can't open %s file\n", fin_name);
		return -1;
	}
	fout_name = argv[1];
	strtok(fout_name,".");
	strcat(fout_name,".cpl");

	if ((fout=fopen(fout_name,"w")) == NULL) {
		fprintf(stderr, "Error! Can't open %s file\n", fout_name);
		return -1;
	}

	if ((tmp_file=fopen("tmp.txt", "w+")) == NULL) {
		fprintf(stderr, "Error! Can't open tmp.txt file\n");
		return -1;
	}

	while (fgets(line, LINE_SIZE, fin)) {
		/* extracting the filename */
		f_name = strdup(line);
		f_name[strlen(f_name)-1]='\0';

		/* extracting the numbers */
		fgets(line, LINE_SIZE, fin);
		p = strtok(line, " \n");
		index = atoi(p);
		p = strtok(NULL, " \n");
		cnt = atoi(p);

		if ((f=fopen(f_name,"r")) == NULL) {
			fprintf(stderr, "Error! Can't open %s file. File skipped.\n", f_name);
		} else {
			copy_lines(fout, f, index, cnt);
			fclose(f);
			if (!find(tmp_file, f_name)) {
				no_of_files++;
				fseek(tmp_file, 0, SEEK_END);
				fprintf(tmp_file, "%s\n", f_name);
			}
		}
	}
	printf("Compilation comopleted. %d files were used.\n", no_of_files);
	fclose(fin);
	fclose(fout);
	fclose(tmp_file);
	return 0;
}
