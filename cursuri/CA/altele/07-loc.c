#include <stdio.h>


void f(void)
{
    static int cnt = 0; // locala statica: se declara si initializeaza DOAR la primul apel al lui f
    // se distruge la terminarea functiei main()

    cnt++; // se executa la fiecare apel al lui f

    printf("was called %d times\n", cnt);
}

void g(void);

int main(void)
{
    f();
    g();


    return 0;
}

void g(void)
{
    static int cnt = 0; // locala statica: se declara si initializeaza DOAR la primul apel al lui f
    // se distruge la terminarea functiei main()

    cnt++; // se executa la fiecare apel al lui f

    printf("was called %d times\n", cnt);
}