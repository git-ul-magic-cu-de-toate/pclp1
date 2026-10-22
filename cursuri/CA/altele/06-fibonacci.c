#include <stdio.h>

long int fibo_iterative(int n)
{
    if (n <= 1) {
        return n;
    }

    long int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long int c = a + b;
        a = b; 
        b = c;
    }

    return b;
}

long int fibo_recursive(int n)
{
    if (n <= 1) {
        return n;
    }

    return fibo_recursive(n - 2) + fibo_recursive(n - 1);
}

int main(void)
{
    // aplicatie: sa calculam al n-lea termen fibonacci iterativ si recursiv
    int n;
    scanf("%d", &n);

    // printf("fibo_iterative(%d) = %ld\n", n, fibo_iterative(n));
    printf("fibo_recursive(%d) = %ld\n", n, fibo_recursive(n));

    return 0;
}

// care este n cel mai mare pentru care fibo(n) incape pe int
// 46
// pe long int
// 103
