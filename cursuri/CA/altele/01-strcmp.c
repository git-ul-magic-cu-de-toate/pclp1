#include <stdio.h>
#include <string.h>

int main(void)
{
    char *a = "ana";
    char *b = "ana2";
    printf("%d\n", strcmp(a, b));
    printf("%d\n", strcmp(b, a));
    printf("%d\n", strcmp(a, a));
    return 0;
}

// TODO: man string.h
