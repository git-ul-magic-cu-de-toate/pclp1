
    

    #include <stdio.h>

int main(void) {
	char x = -1;
	int y = x;

	printf("%u\n", x);
	printf("%u\n", y);

	char a = 1;
	int b = a;

	printf("%u\n", a);
	printf("%u\n", b);

	return 0;
}