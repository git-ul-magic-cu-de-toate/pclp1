#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *re_aloc(void *ptr, size_t size)
{
    void *q;
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    q = (void *)malloc(size);
    if (!q) {
        return NULL;
    }
    memcpy(q, ptr, size);
    free(ptr);
    return q;
}

int main()
{
    int *v = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
        v[i] = i;
    int *tmp = re_aloc(v, 6 * sizeof(int));
    if (!tmp) {
        return 1;
    }
    v = tmp;
    v[5] = 5;
    for (int i = 0; i < 6; i++)
        printf("%d ", v[i]);
}