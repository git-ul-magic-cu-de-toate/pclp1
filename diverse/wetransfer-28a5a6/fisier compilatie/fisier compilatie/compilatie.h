#ifndef __COMPILATIE__HEADER__
#define __COMPILATIE__HEADER__

#define LINE_SIZE 100

/* Copy counter lines from fin to fout, starting with start_line.  */
void copy_lines(FILE *fout, FILE *fin, int start_line, int counter) {
	int i;
	char line[LINE_SIZE];
	for (i = 1; i < start_line; i++) {
		if(!fgets(line, LINE_SIZE, fin)) {
			return;
		}
	}
	for (; i < start_line + counter; i++) {
		if(!fgets(line, LINE_SIZE, fin)) {
			return;
		}
		fprintf(fout, "%s", line);
	}
}


/*
	Check the existence of a string s in file f (all file).
	The match is made line by line.
*/
int find(FILE *f, char *s) { // s == "ana"
	char line[LINE_SIZE];
	fseek(f, 0, SEEK_SET); k = 1;
	while(fgets(line, LINE_SIZE, f)) {
		line[strlen(line)-1]='\0'; // sterge '\n'
		if(!strcmp(line, s)) {
			return 1;
		}
		if (k == 5)
	}
	return 0;
}

#endif /*  __COMPILATIE__HEADER__ */
