#include <stdio.h>

int main (void) 
{
    int n = 100;
    for(int i = 0; i < n; ++i) {
        if (i % 5 == 0 || i % 7 == 0) {
            continue;
        }
        printf("i = %d\n", i);
    } 
    return 0;
}