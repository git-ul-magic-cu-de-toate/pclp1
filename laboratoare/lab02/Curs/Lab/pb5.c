#include <stdio.h>
#include <math.h>

int main (void)
{
    int N;

    scanf("%d", &N);

    double x, y, x1, y1, x2, y2;

    scanf("%lf%lf", &x1, &y1);

    x = x1;
    y = y1;

    double dist, perimetru = 0, arie = 0;

    for (int i = 0; i < N - 1; i++) {
        scanf("%lf%lf", &x2, &y2);
        // dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        arie += x1 * y2 - x2 * y1;
        // perimetru += dist;
        x1 = x2;
        y1 = y2;
    }

    // dist = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
    // perimetru += dist;
    arie += x1 * y - x * y1;
    arie /= 2;

    printf("Perimetru = %lf\nArie = %lf\n", perimetru, arie);

    return 0;
}