#include <stdio.h>

int main(void)
{
    // 1. interschimbare cu auxiliar
	int a, b;
	scanf("%d%d", &a, &b);

	int tmp = a;
	a = b;
	b = tmp;
	printf("a = %d b = %d\n", a, b);
	
	// 2. internschimbare cu adunari si scaderi
	// a = a + b;
	// b = a - b;
	// a = a - b;

	// 3. interschimbare cu XOR

	return 0;
}






























//  // interschimbare cu adunari
// 	int m, n;
// 	scanf("%d%d", &m, &n);
// 	m = m + n;
// 	n = m - n;
// 	m = m - n;
// 	printf("%d %d\n", m, n);