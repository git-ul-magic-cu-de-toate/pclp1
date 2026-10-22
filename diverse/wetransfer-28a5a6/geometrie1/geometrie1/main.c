#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	float x, y;
} point_t;


typedef struct {
	float r;
	point_t center;
} circle_t;

typedef struct {
	point_t ld, ru; 
} rectangle_t;

typedef struct {
	int n;
	point_t *points; 
} cloud_t;


float distance(point_t a, point_t b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;

	return sqrt(dx * dx + dy * dy);
}

int point_in_circle(point_t p, circle_t c) {
	return distance(p, c.center) <= c.r;
}

int point_in_rectangle(point_t p, rectangle_t r) {
	float x1 = r.ld.x, y1 = r.ld.y;
	float x2 = r.ru.x, y2 = r.ru.y;

	return (x1 <= p.x && p.x <= x2) &&
		   (y1 <= p.y && p.y <= y2);
}

// a < b: -1
// a > b: +1
// a== b: 0
int point_cmp(point_t a, point_t b) {
	if (a.x < b.x) {
		return -1;
	}

	if (a.x > b.x) {
		return +1;
	}

	if (a.y < b.y) {
		return -1;
	}

	if (a.y > b.y) {
		return +1;
	}

	return 0;
}

void swap(point_t *a, point_t *b) {
	point_t tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_in_circle(
	cloud_t cloud,
	circle_t c) {

	int cnt = 0;
	int n = cloud.n;
	point_t *points = cloud.points;

	for (int i = 0; i < n; ++i) {
		if (point_in_circle(points[i], c)) {
			cnt++;
		}
	}

	printf("%d puncte sunt in cerc\n", cnt);	
}

void print_in_rectangle(
	cloud_t cloud,
	rectangle_t r) {

	int cnt = 0;
	int n = cloud.n;
	point_t *points = cloud.points;

	for (int i = 0; i < n; ++i) {
		if (point_in_rectangle(points[i], r)) {
			cnt++;
		}
	}

	printf("%d puncte sunt in dreptunghi\n", cnt);	
}


int main(int argc, char const *argv[]) {
	cloud_t cloud;

	scanf("%d", &cloud.n);
	cloud.points = malloc(cloud.n * sizeof(point_t));
	for (int i = 0; i < cloud.n; ++i) {
		float x, y;
		scanf("%f%f", &x, &y);

		cloud.points[i].x = x;
		cloud.points[i].y = y;
	}

	int n = cloud.n;
	point_t *points = cloud.points;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (point_cmp(points[i], points[j]) == 1) {
				swap(&points[i], &points[j]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%5f %5f\n", points[i].x, points[i].y);

	}

	point_t *tmp = malloc(n * sizeof(point_t));
	int j = 0;
	for (int i = 0; i < n; ++i) {
		tmp[j] = points[i];
		j++;

		while (i + 1 < n && point_cmp(points[i], points[i+1]) == 0) {
			printf("skip %f %f\n", points[i+1].x, points[i+1].y);
			++i;
		}
	}
	cloud.n = n = j;
	tmp = realloc(tmp, n * sizeof(point_t));
	free(cloud.points);
	cloud.points = tmp;
	points = cloud.points;

	for (int i = 0; i < n; ++i) {
		printf("%5f %5f\n", points[i].x, points[i].y);
	}

	circle_t c;
	rectangle_t r;
	scanf("%f%f%f", &c.center.x, &c.center.y, &c.r);
	scanf("%f%f%f%f", &r.ld.x, &r.ld.y, &r.ru.x, &r.ru.y);

	print_in_circle(cloud, c);
	print_in_rectangle(cloud, r);


	free(cloud.points);

	return 0;
}