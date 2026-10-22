#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generic_sort(void *base, size_t n, size_t size, int (*compare)(const void *, const void*))
{
    int t = 0;
    while (t == 0) {
        t = 1;
        for (int i = 0; i < n - 1; i++) {
            int cmp = compare((char *)base + i * size, (char *)base + (i + 1) * size);
            printf("%d\n", cmp);
            if (cmp > 0) {
                void *pi = (char *)base + i * size, *pi_1 = (char *)base + (i + 1) * size;
                void *aux;
                *aux = *pi;
                *pi = *pi_1;
                *pi_1 = *aux;
                t = 0;
            }

        }
    }
}

int compare_int(const void *first, const void *second)
{
    return *(int *)first - *(int *)second;
}

int main()
{
    int v[] = {29,2,10,4,5};
    generic_sort(v, 5, sizeof(int), compare_int);
    for (int i = 0; i < 5; i++)
        printf("%d ", v[i]);
}