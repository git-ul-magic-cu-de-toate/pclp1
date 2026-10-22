#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    int m, n, p;
    n = atoi(argv[2]);
    m = atoi(argv[3]);
    p = atoi(argv[4]);
    FILE *in = fopen(argv[1], "rt");
    if (!in) {
        printf("nu putem\n");
        return 1;
    }
    FILE *f1, *f2, *f3;
    f1 = fopen("help_file1", "wt");
    f3 = fopen("help_file2", "wt");
    fclose(f1);
    char delim[] = " .,:;/\n";
    char c, *s;
    int cnt = 0;
    while (fscanf(in, "%c", &c) != EOF) {
        if (strchr(delim, c)) {
            if (cnt > 0) {
                s[cnt] = '\0';
                char line[16];
                int ok = 1;
                f2 = fopen("help_file1", "rt");
                while (fgets(line, 16, f2)) {
                    line[strlen(line) - 1] = '\0';
                    if (strcmp(s, line) == 0)
                        ok = 0;
                }
                fclose(f2);
                f1 = fopen("help_file1", "a");
                if (ok == 1 && strlen(s) >= m && strlen(s) <= n)
                    fprintf(f1, "%s\n", s);
                if (strlen(s) >= m && strlen(s) <= n)
                    fprintf(f3, "%s\n", s);
                fclose(f1);
                free(s);
                cnt = 0;
            }
        } else {
            cnt++;
            if (cnt == 1) {
                s = malloc(1 * sizeof(char));
                s[cnt - 1] = c;
                continue;
            }
            char *tmp = realloc(s, cnt * sizeof(char));
            if (!tmp) {
                printf("Eroare mare vere\n");
                fclose(in);
                fclose(f1);
                free(s);
            }
            s = tmp;
            s[cnt - 1] = c;
        }
    }
    fclose(f3);
    f3 = fopen("help_file2", "rt");
    f2 = fopen("help_file1", "rt");
    f1 = fopen("file_bin", "wb");
    char line1[16], line2[16];
    while (fgets(line1, 16, f2)) {
        fseek(f3, 0, SEEK_SET);
        int cnt = 0;
        while (fgets(line2, 16, f3)) {
            if (strcmp(line1, line2) == 0)
                cnt++;
        }
        if (cnt >= p) {
            line1[strlen(line1) - 1] = '\0';
            int n = strlen(line1);
            printf("%d %s\n", cnt, line1); 
            fwrite(&n, sizeof(int), 1, f1);
            fwrite(line1, sizeof(char), n + 1, f1);
            fwrite(&cnt, sizeof(int), 1, f1);
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}