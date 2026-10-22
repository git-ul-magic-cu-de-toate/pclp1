#include <stdio.h>

// int main(void)
// {
//     printf("Hello Gigel\n");
//     return 0;
// }

// argc = argument count
// argv = argment values
int main(int argc, char **argv)
{
	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; ++i) {
		printf("argv[%d] = \"%s\"\n", i, argv[i]);
	}

	return 0;
}

// nm ./gigel | grep main
//                  U __libc_start_main@@GLIBC_2.2.5
// 0000000000001149 T main
// functia __libc_start_main() aloca toate datele necesare
// apeleaz main cu sau fara param
// ia return value de la main
// elibereaza, daca e necesar, argv

// $ ./gigel
// argc = 1
// argv[0] = "./gigel"
// $ ./gigel 1
// argc = 2
// argv[0] = "./gigel"
// argv[1] = "1"
// $ ./gigel 1 22
// argc = 3
// argv[0] = "./gigel"
// argv[1] = "1"
// argv[2] = "22"
// $ ./gigel 1 22 33
// argc = 4
// argv[0] = "./gigel"
// argv[1] = "1"
// argv[2] = "22"
// argv[3] = "33"
// $ ./gigel 1 22 33 4 5 6
// argc = 7
// argv[0] = "./gigel"
// argv[1] = "1"
// argv[2] = "22"
// argv[3] = "33"
// argv[4] = "4"
// argv[5] = "5"
// argv[6] = "6"
// $ ./gigel 1 22 33 "    4   5   6  "
// argc = 5
// argv[0] = "./gigel"
// argv[1] = "1"
// argv[2] = "22"
// argv[3] = "33"
// argv[4] = "    4   5   6  "
