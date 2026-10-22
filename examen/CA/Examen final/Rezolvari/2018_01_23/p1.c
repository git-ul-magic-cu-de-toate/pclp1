#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#









#














int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("NU avem nr de parametri corect\n");
        return 1;
    }
    FILE *in = fopen(argv[1], "rt");
    FILE *help = fopen("help_file", "wt");
    FILE *exp;
    if (!in || !help) {
        printf("NU putem deschide\n");
        fclose(in);
        fclose(help);
    }
    char line[1001];
    while (fgets(line, 1001, in)) {
        if (line[0] == '#' && line[1] == 'i' && line[9] == '"') {
            char filename[40];
            int cnt = 0;
            for (int i = 10; line[i] != '"'; i++)
                filename[cnt++] = line[i];
            filename[cnt] = '\0';
            exp = fopen(filename, "rt");
            while(fgets(line, 1001, exp))
                fprintf(help, "%s", line);
            fclose(exp);
        } else {
            fprintf(help, "%s", line);
        }
    }
    fclose(in);
    in = fopen(argv[1], "wt");
    fclose(help);
    help = fopen("help_file", "rt");
    while (fgets(line, 1001, help))
        fprintf(in, "%s", line);
    fclose(in);
    fclose(help);
    return 0;
}