#include <stdio.h>
#include <math.h>

typedef double (*fp)(double);

void listf(double (*fp)(double), double min, double max, double pas)
{
	double x, y;

	for (x = min; x <= max; x = x + pas) {
		y = (*fp)(x); // apel functie de la adresa din "fp"
		printf("%20.10lf %20.10lf\n", x, y);
	}
}

int main(void)
{
	char function_name[6][10] = { "sin", "cos", "tan", "exp" };
	fp functions[] = { sin, cos, tan, exp };

	for (int i = 0; i < 4; ++i) {
		listf(functions[i], 1.0, 20.0, 1.0);
	}

	return 0;
}
