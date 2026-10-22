// Acest fisier este o schita. Nu compileaza.
// Sa se scrie un program care citeste de la tastura un numar n.
// 1) Va citi apoi n numere naturale pe ecran
// si va calcula si afisa media lor aritmetica cu 2 zecimale.
// 2) Va citi apoi alte n numere reale pe ecran
// si va calcula si afisa elementul minim.
// 3) Va citi apoi alte n numere intregi si va numara
// si afisa cate elemente negative sunt in sir.
// 4) Va citi apoi alte n numere naturale pe ecran
// si va calcula si afisa media lor aritmetica cu 5 zecimale.
// 5) Va citi apoi alte n numere reale pe ecran
// si va calcula si afisa elementul minim.
// 6) Va citi apoi alte n numere intregi si va numara
// afisa cate elemente negative sunt in sir.
// ...
#include <stdio.h> // scanf + printf
#include <math.h>

void media_2(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);

        sum += x;
    }
    double average = 1.0 * sum / n;
    printf("average = %.2lf", average);
}

void minim_interval(int n)
{
    double min;
    double x;
    scanf("%lf", &x);
    min = x;
    for (int i = 2; i <= n; ++i)
    {
        double x;
        scanf("%lf", &x);

        if (x < min)
        {
            min = x;
        }
    }
    printf("min = %.5lf", min);
}

void contor_negative(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);

        if (x < 0)
        {
            ++cnt;
        }
    }
    printf("cnt = %d\n", cnt);
}

void media_5(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);

        sum += x;
    }

    double average = 1.0 * sum / n;
    printf("average = %.5lf", average);
}

int main()
{

    int n;
    scanf("%d", &n);

    media_2(n);

    minim_interval(n);

    contor_negative(n);

    media_5(n);

    minim_interval(n);

    contor_negative(n);
    
    return 0;
}
