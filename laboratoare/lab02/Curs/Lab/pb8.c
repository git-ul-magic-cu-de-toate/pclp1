#include <stdio.h>

int main(void)
{
    int k;
    scanf("%d", &k);

    int min, max_div;

    int x;
    scanf("%d", &x);

    int cnt_div = 0;
    for (int d = 1; d <= x / 2; d++)
    {
        if (x % d == 0)
            cnt_div++;
    }
    min = x;
    max_div = cnt_div;

    for (int i = 1; i < k; i++)
    {
        int x;
        scanf("%d", &x);

        int cnt_div = 0;
        for (int d = 1; d <= x / 2; d++)
        {
            if (x % d == 0)
                cnt_div++;
        }
        if (cnt_div > max_div)
        {
            max_div = cnt_div;
            min = x;
        }
        else if (cnt_div == max_div)
        {
            if (x < min)
                min = x;
        }
    }

    printf("%d\n", min);

    return 0;
}