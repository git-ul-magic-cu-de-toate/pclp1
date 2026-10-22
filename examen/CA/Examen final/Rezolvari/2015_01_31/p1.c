#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#



#











int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("No catalog file\n");
        return 1;
    }
    char *compil = (char *)malloc((strlen(argv[1]) + 5) * sizeof(char));
    if (!compil) {
        printf("could not alloc\n");
        return 2;
    }
    strcpy(compil, argv[1]);
    strcat(compil, ".cpl");
    FILE *in, *out;
    in = fopen(argv[1], "rt");
    out = fopen(compil, "wt");
    if (!in) {
        free(compil);
        printf("Could not open\n");
        return 2;
    }
    char line[500];
    char content[500];
    char **filenames;
    int n = 0;
    while (fgets(line, 500, in)) {
        n++;
        if (n == 1) {
            filenames = (char **)malloc(1 * sizeof(char *));
            if (!filenames) {
                printf("COuld not alloc\n");
                return 3;
            }
        } else {
            char **tmp = (char **)realloc(filenames, n * sizeof(char *));
            if (!tmp) {
                printf("Could not alloc space\n");
                for (int j = 0; j < n - 1; j++)
                    free(filenames[j]);
                free(filenames);
                return 4;
            }
            filenames = tmp;
        }
        char *q = strtok(line, " ");
        char filename[500];
        int cnt = 0;
        int first, line_cnt;
        while (q) {
            cnt++;
            if (cnt == 1) {
                filenames[n - 1] = (char *)malloc((strlen(q) + 1) * sizeof(char));
                strcpy(filenames[n - 1], q);
            }
            else if (cnt == 2)
                first = atoi(q);
            else
                line_cnt = atoi(q);
            q = strtok(NULL, " ");
        }
        FILE *in_filenames = fopen(filenames[n - 1], "rt");
        if (!in_filenames) {
            printf("COuld not open file\n");
            fclose(out);
            fclose(in);
            for (int i = 0; i < n; i++)
                free(filenames[i]);
            free(filenames);
            free(compil);
            return 5;
        }
        cnt = 0;
        while(fgets(content, 500, in_filenames)) {
            cnt++;
            if (cnt >= first && cnt <= first + line_cnt - 1) {
                fprintf(out, "%s", content);
            }
            if (cnt > first + line_cnt - 1)
                break;
        }
        fclose(in_filenames);
    }
    int uniq, numara = 0;
    for (int i = 0; i < n; i++) {
        uniq = 1;
        for (int j = i + 1; j < n && uniq == 1; j++)
            if (strcmp(filenames[i], filenames[j]) == 0)
                uniq = 0;
        if (uniq == 1)
            numara++;
    }
    for (int i = 0; i < n; i++)
        free(filenames[i]);
    free(filenames);
    printf("%d\n", numara);
    fclose(out);
    fclose(in);
    free(compil);
    return 0;
}