#include <stdio.h>

void read_vector(int N, int a[1001][1001])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    }
}

void write_vector(int N, int a[1001][1001])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void pas_1(int N, int a[1001][1001])
{
    for (int k = 0; k < N; k++)
    {
        if (k % 2 == 1)
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if(a[k][i] > a[k][j])
                    {
                        int tmp = a[k][i];
                        a[k][i] = a[k][j];
                        a[k][j] = tmp;
                    }
        }
        else
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if(a[k][i] < a[k][j])
                    {
                        int tmp = a[k][i];
                        a[k][i] = a[k][j];
                        a[k][j] = tmp;
                    }
        }
    }
    write_vector(N, a);
}

void pas_2(int N, int a[1001][1001])
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if(a[i][k] < a[j][k])
                {
                    int tmp = a[i][k];
                    a[i][k] = a[j][k];
                    a[j][k] = tmp;
                }
    }
    write_vector(N, a);
}

int main(void)
{
    int a[1001][1001], N;
    
    scanf("%d", &N);
    read_vector(N, a);

    pas_1(N, a);

    pas_2(N, a);

    return 0;
}
