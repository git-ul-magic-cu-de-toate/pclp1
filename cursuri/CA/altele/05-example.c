// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
// aceasta sursa e un exemplu de pasare prin referinta(pointer)
// a unui param unui functii; se doreste a modifica variabila in functie!

void f(int *x)
{
	*x = 17;
}

int main(void)
{
	int x = 10;

	printf("x_before = %d\n", x);
	f(&x);
	printf("x_after  = %d\n", x);

	// deci de aia faceam "magia" la scanf
	int n;
	scanf("%d", &n);   // scanf primeste pointer ca sa il poata modifica!!!
	printf("%d\n", n); // iar printf primeste valoarea, pt vrem sa afisam
					   // valoarea si e ok (corect) sa faca o copie
	return 0;
}
