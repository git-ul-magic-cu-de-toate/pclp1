// Sa se scrie un program care sa citeasca de la tastatura un numar k.
// Se citeste de k ori cate un numar n.
//  - Daca n este par, se va afisa un triunghi de stelute de forma
//     exemplu n = 4
//      *
//      **
//      ***
//      ****
//  - Daca n este par, se va afisa un triunghi de stelute de forma
//     exemplu n = 4
//      ****
//      ***
//      **
//      *
//    
#include <stdio.h>

// declarare / semnatura / prototip functie void:
// void function_name(type_param1 name_param1, type_param2 name_param2, ...);

// implementare / definitie functie:
// void function_name(type_param1 name_param1, type_param2 name_param2, ...)
// {
//      declarare variabile;
//      ...
//      declarare instructiuni;
//      ...
// }

void myprintf(int n) {
    if (n % 2 == 0) {
        printf("*\n**\n***\n");
    } else {
        printf("***\n**\n*\n");
    }
}
int main()
{
    int k;
    scanf("%d", &k);

    for (int i = 1; i <= k; ++i) {
        int n;
        scanf("%d", &n);
        myprintf(n);
    }
    return 0;
}