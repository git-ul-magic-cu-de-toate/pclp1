#include <stdio.h>
#define NMAX 100

void scanf_vector(int n, int v[NMAX])
{
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
}

void printf_vector(int n, int v[NMAX])
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int sum_vector(int n, int v[NMAX])
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
    }
    return sum;
}

int produs_vector(int n, int v[NMAX])
{
    int produs = 0;
    for (int i = 0; i < n; ++i) {
        produs *= v[i];
    }
    return produs;
}

double average_vector(int n, int v[NMAX])
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
    }
    return 1.0 * sum / n;
}

int min_vector(int n, int v[NMAX])
{
    int min;
    min = v[0];
    for (int i = 1; i < n; ++i) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

int max_vector(int n, int v[NMAX])
{
    int max;
    max = v[0];
    for (int i = 1; i < n; ++i) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

int pos_min_vector(int n, int v[NMAX])
{
    int min, pos_min;
    min = v[0];
    pos_min = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i] < min) {
            min = v[i];
            pos_min = i;
        }
    }
    return pos_min;
}

int pos_max_vector(int n, int v[NMAX])
{
    int max, pos_max;
    max = v[0];
    pos_max = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i] < max) {
            max = v[i];
            pos_max = i;
        }
    }
    return pos_max;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int v[NMAX];
    scanf_vector(n, v);
    
    int sum = sum_vector(n, v);
    printf("sum = %d\n", sum);
    
    printf("average = %5.3lf\n", average_vector(n, v));

    int min = min_vector(n, v);
    printf("min = %d\n", min);

    int max = max_vector(n, v);
    printf("max = %d\n", max);

    int pos_min = pos_min_vector(n, v);
    printf("Pozitia minima = %d\n", pos_min);

    int pos_max = pos_max_vector(n, v);
    printf("Pozitia maxima = %d\n", pos_max);

    return 0;
}

// TODO 0: suma / produs
// TODO 1: average
// TODO 2: min / max
// TODO 3: pos_min / pos_max
