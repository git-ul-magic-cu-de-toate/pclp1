#include <stdio.h>

int f() {
    printf("f was called\n");
    return 0;
}

int g(void) {
    printf("f was called\n");
    return 0;
}

int main(void) {
    // Cum apelez corect f?
    f();
    f("Hai Steaua!");
    f(1, 2, 3, 4, -1);
    f(f());

    // NU compileaza daca punem void
    // g();
    // g("Hai Steaua!");
    // g(1, 2, 3, 4, -1);
    // g(g());

    // main();

    return 0;
}


// Concluzie: Cum e corect sa scriem semnatura functiei main?