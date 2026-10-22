#include <stdio.h>
#include <math.h>


// declarare / semnatura / prototip functie:
// return_type function_name(type_param1 name_param1, type_param2 name_param2, ...);

// implementare / definitie functie:
// return_type function_name(type_param1 name_param1, type_param2 name_param2, ...)
// {
//      declarare variabile;
//      ...
//      declarare instructiuni;
//      ...
//      return return_value;
// }

// calculeaza suma a doua numere
int compute_sum(int a, int b) {
    int sum = a + b;
    return sum;
}

// returneaza patratul unui numar intreg
int sqr(int n) {
    return n * n;
}

// functia verifica daca un numar este impar
// returneaza 1 daca este impar, 0 alfel
int is_odd(int n) {
    // if (n % 2 == 1) {
    //     return 1;
    // } else {
    //     return 0;
    // }
    return n % 2 == 1;
}

// functia verifica daca un numar este patrat perfect
// returneaza 1 daca este adevarat, 0 alfel
// DARIUS: e gresita. promit.
int is_square(int n) {
    // // tema acasa: 
    // de ce liniile astea sunt gresita? cum corectam?
    double s = sqrt(n);
    return s * s == n; 
}

// functia verifica daca un numar este par
// returneaza 1 daca este par, 0 alfel
int is_even(int n) {
    return n % 2 == 0;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a + b);

    // 1. sa se scrie o functie care calculeaza suma a doua numere
    // sa se apeleze functia
    int sum = compute_sum(a, b);
    printf("%d\n", sum);

    // 2. sa se scrie o functie care calculeaza patratul unui numar intreg
    printf("%d\n", sqr(a));

    // 3. sa se scrie o functie care verifica daca un numar e par / impar
    printf("%d %d\n", is_odd(a), is_even(a));

    // 4. sa se scrie o functie care verifica daca un numar e patrat perfect
    printf("%d\n", is_square(b));

    return 0;
}