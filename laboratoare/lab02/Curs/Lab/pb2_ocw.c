#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void wait(int seconds)
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait)
    {
    }
}

int main(void)
{
    int d;

    srand(0x1234);
     
    for (int i = 0; i < 5; i++)
    {
        d = rand(); // generează valori random.
        printf("%d\n", d);
        wait(1);
    }
    return 0;
}