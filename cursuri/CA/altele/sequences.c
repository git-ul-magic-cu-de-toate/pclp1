#include <stdio.h>

void read_vector(int N, int v[1001])
{
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
    }
}

int main(void)
{
    int a[1001], b[1001], N;
    
    scanf("%d", &N);
    read_vector(N, a);
    read_vector(N, b);

    if (N == 1)
    {
        printf("%d\n", a[0]);
        return 0;
    }
    int lung_max = 0, start = 0, end = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] < b[i])
        {
            int lung = 0, j = i;
            while (j < N && a[j] < b[j])
            {
                lung++;
                j++;
            }
            j--;
            if (lung > lung_max)
            {
                lung_max = lung;
                start = j - lung + 1;
                end = j;
            }
            i = j;
        }
        else if (a[i] == b[i])
        {
            int lung = 0, j = i;
            while (j < N && a[j] == b[j])
            {
                lung++;
                j++;
            }
            j--;
            if (lung > lung_max)
            {
                lung_max = lung;
                start = j - lung + 1;
                end = j;
            }
            i = j;
        }
        else if (a[i] > b[i])
        {
            int lung = 0, j = i;
            while (j < N && a[j] > b[j])
            {
                lung++;
                j++;
            }
            j--;
            if (lung > lung_max)
            {
                lung_max = lung;
                start = j - lung + 1;
                end = j;
            }
            i = j;
        }
    }

    // printf("%d %d\n", start, end);
    for (int i = start; i <= end; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
