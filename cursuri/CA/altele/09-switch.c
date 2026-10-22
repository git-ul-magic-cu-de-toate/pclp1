#include <stdio.h>

int main(void)
{
	// instructiunea switch: aplicare - determinare daca un numar e de forma 7k, 7k+1, ...

    int n;
    scanf("%d", &n);

    if (n % 7 == 0) {
        printf("%d = 7k\n", n);
    } else if (n % 7 == 1) {
        printf("%d = 7k + 1\n", n);
    } else if (n % 7 == 2) {
        printf("%d = 7k + 2\n", n);
    } else if (n % 7 == 3) {
        printf("%d = 7k + 3\n", n);
    } else if (n % 7 == 4) {
        printf("%d = 7k + 4\n", n);
    } else if (n % 7 == 5) {
        printf("%d = 7k + 5\n", n);
    } else if (n % 7 == 6) {
        printf("%d = 7k + 6\n", n);
    }

    switch (n % 7) {
    case 0: {
        printf("%d = 7k\n", n);
        break;
    }
    case 1: {
        printf("%d = 7k+1\n", n);
        break;
    }
    case 2: {
        printf("%d = 7k+2\n", n);
        break;
    }
    case 3: {
        printf("%d = 7k+3\n", n);
        break;
    }
    case 4: {
        printf("%d = 7k+4\n", n);
        break;
    }
    case 5: {
        printf("%d = 7k+5\n", n);
        break;
    }

    case 6: {
        printf("%d = 7k+6\n", n);
        break;
    }

    default: {
        break;
    }
    }

	return 0;
}





































   