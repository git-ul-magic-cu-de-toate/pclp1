#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n, x, y;
    
    scanf("%d", &n);
    
    while (n > 0)
    {
        scanf("%d%d", &x, &y);
        
        int arr_x[10] = {0}, arr_y[10] = {0}; // declar vectorii pt cifrele lui x si y
        
        int cnt_x, cnt_y; // contor nr de cifre pt x si y
        cnt_x = cnt_y = -1; 
        
        int cp_x = x;
        int cp_y = y;

        do{
            arr_x[++cnt_x] = x % 10;
            x /= 10;
        } while (x);
        cnt_x++;

        do{
            arr_y[++cnt_y] = y % 10;
            y /= 10;
        } while (y);
        cnt_y++;

        if (cnt_x >= 4 && cnt_y >= 4)
        {
            int tmp;
            tmp = arr_x[cnt_x - 2];
            arr_x[cnt_x - 2] = arr_y[1];
            arr_y[1] = tmp;
            
            tmp = arr_y[cnt_y - 2];
            arr_y[cnt_y - 2] = arr_x[1];
            arr_x[1] = tmp;

            x = y = 0;

            for(int i = cnt_x - 1; i >= 0; i--)
            {
                x = x * 10 + arr_x[i];    
            }

            for(int i = cnt_y - 1; i >= 0; i--)
            {
                y = y * 10 + arr_y[i];    
            }

            printf("%d %d\n", x, y);
        }
        else
        {
            printf("%d %d\n", cp_x, cp_y);
        }
        n--;
    }
    
    return 0;
}