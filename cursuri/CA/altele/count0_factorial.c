#include <stdio.h>

int main(void)
{
    int contor_2, contor_5, n;
    contor_2 = contor_5 = 0;

    scanf("%d", &n);

    if (n <= 4)
    {
        printf("0 zerouri\n");
        return 0;
    }

    for (int i = 2; i <= n; i++)
    {
        int tmp = i;
        while(tmp % 2 == 0)
        {
            contor_2++;
            tmp /= 2;
        }
        tmp = i;
        while(tmp % 5 == 0)
        {
            contor_5++;
            tmp /= 5;
        }
    }

    if (contor_5 > contor_2)
        printf("Nr. de zerouri este: %d\n", contor_2);
    else
        printf("Nr. de zerouri este: %d\n", contor_5);
    return 1;
}