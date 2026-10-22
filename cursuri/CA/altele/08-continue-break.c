#include <stdio.h>

int main(void)
{
	// instructiunea continue: in oricare din ciclurile invatate anterior,
    // continue trece direct la executarea urmatorului pas
    int n = 100;
    for (int i = 0; i < n; ++i) {
        if (i % 5 == 0 || i % 7 == 0) {
            continue; // sari la urmatorul pas (adica la urmatoarea valoare a lui i)
        }

        printf("%d ", i);
    }
    printf("\n");

	// instructiunea break: in oricare din ciclurile invatate anterior,
    // break opreste direct ciclul
    n = 100;
    for (int i = 0; i < n; ++i) {
        if (i == 49) {
            break; // stop.
        }

        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < n; ++i) {
        int should_stop = 0;

        for (int j = 0; j < n; ++j) {
            // break/cintinue
            should_stop = 1;
        }

        if (should_stop == 1) {
            break;
        }
            // break/cintinue
        // 
    }

	return 0;
}
