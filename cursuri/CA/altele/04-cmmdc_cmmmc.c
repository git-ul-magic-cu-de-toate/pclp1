#include <stdio.h>
int main (void)
{
    int x,y;
    scanf("%d%d", &x, &y);
    int a = x, b = y;
    while(x != y){
        if(x > y){
            x -= y;
        } else {
            y -= x;
        }
    }

    int cmmdc = x;
    int cmmmc = a * b / cmmdc;
    printf("cmmdc = %d cmmmc = %d\n", cmmdc, cmmmc);
    return 0;
}