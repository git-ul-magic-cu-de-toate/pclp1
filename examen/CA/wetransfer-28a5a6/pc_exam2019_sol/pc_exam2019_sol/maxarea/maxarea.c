// Copyright 2020 Darius Neatu <neatudarius@gmail.com>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    int n;
    point_t *points;
} poly_t;

poly_t poly_read(FILE *in, int n);
double poly_area(poly_t poly);

int main(int argc, char **argv){
    if (argc < 3) {
        fprintf(stderr, "Usage: ./maxarea filename p1 p2 ... ");
        return -1;
    }

    // deschidere fisier
    char *filename = argv[1];
    FILE *in = fopen(filename, "rb");
	if (in == NULL) {
		fprintf(stderr, "%s doesn't exist\n", filename);
		return -2;
	}

    // initializare maxim cu primul poligon din fisier
    int max_index = atoi(argv[2]);
    poly_t max_poly = poly_read(in, max_index);
    double max_area = poly_area(max_poly);

    // parcurgere restul listei
    for (int i = 3; i < argc; ++i) {
        // citeste polinomul curent
        int index = atoi(argv[i]);
        poly_t poly = poly_read(in, index);
        if (poly.points == NULL) {
            fprintf(stderr, "Invalid index %d\n", index);
            continue;
        }

        // calculam aria
        double area = poly_area(poly);

        // daca aria este mai mare, reactualzieaza maximul
        if (area > max_area) {
            // eliberez memoria (sa nu moara poneiu')
            free(max_poly.points);

            max_index = index;
            max_poly = poly;
            max_area = area;
        } else {
            // eliberez memoria (sa nu moara poneiu')
            free(poly.points);
        }
    }        

    // afisare rezulat
    printf("Poligonul cu arie maxima are indicele %d (aria = %.5lf)\n", max_index, max_area);

    // eliberez memoria (sa nu moara poneiu')
    free(max_poly.points);

    fclose(in);
    return 0;
}

poly_t poly_read(FILE *in, int index) {
    poly_t poly;
    poly.points = NULL;

    // repozitionare la inceputul fisierului
    fseek(in, 0, SEEK_SET);

    // citesc primele index - 1 poligoame
    // nu le folosesc
    for (int i = 0; i < index - 1; ++i) {
        // citim numarul de puncte
        int n;
        if (fread(&n, sizeof(int), 1, in) != 1) {
            return poly;
        }

        // sarim n * sizeof(point_t) bytes (sar peste punctele poligonului curent)
        fseek(in, n * sizeof(point_t), SEEK_CUR);

        // este echivalent cu citirea vectorului si faptul ca nu il folosesc
        // point_t *points = malloc(n * sizeof(point_t));
        // fread(points, sizeof(point_t), n, in);
        // free(points);
    }

    // aici citesc poligonul cu indexul index (si il folosesc)
    fread(&poly.n, sizeof(int), 1, in);
    poly.points = (point_t *) malloc(poly.n * sizeof(point_t));
    if (!poly.points) {
        fprintf(stderr, "malloc failed\n");
    }
    fread(poly.points, sizeof(point_t), poly.n, in);

    return poly;
}

double poly_area(poly_t poly) {
    double area = 0;

    for (int i = 0; i < poly.n; ++i) {
        double x_cur = poly.points[i].x;
        double y_cur = poly.points[i].y;

        int next = (i + 1  < poly.n ? i + 1 : 0);
        double x_next = poly.points[next].x;
        double y_next = poly.points[next].y;

        // https://www.infoarena.ro/problema/aria
        area += x_cur * y_next - x_next * y_cur;
    }

    return 0.5 * area;
}
