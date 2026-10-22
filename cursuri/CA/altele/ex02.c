#include <stdio.h>

int main(void) 
{
    long S = 0, x;

    while (1) {
        scanf("%ld", &x);
        if (x > 0) {
            S += x;
        } else {
            goto exit;
        }
    }

start:
    if (S % 2 == 0) {
        printf("S = %ld\n", S/2);
    } else {
        exit:
        printf("S = %ld\n", S);
        goto start;
    }
    
    return 0;
}