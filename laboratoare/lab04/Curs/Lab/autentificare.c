#include <stdio.h>

int cmmdc(int n, int m)
{
    while (m)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

void login(int username, int password)
{
    int div;
    div = cmmdc(username, password);

    int status;

    if (div == 1)
    {
        printf("Autentificare cu succes\n");
        status = 1;
    }
    else
    {
        printf("Autentificare esuata\n");
        status = 0;
    }

    printf("%d\n", status);
}