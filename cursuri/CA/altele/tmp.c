#include <stdio.h>
#define NMAX 100001

void read_vector(int n, int v[NMAX])
{
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &v[i]);
	}
}

int main(void)
{
	freopen("interclasare.in", "r", stdin);
	freopen("interclasare.out", "w", stdout);

	int n, a[NMAX];
	scanf("%d", &n);
	read_vector(n, a);

	int m, b[NMAX];
	scanf("%d", &m);
	read_vector(m, b);

	int	p = 0, c[2 * NMAX];
	int i = 1, j = 1;

	while (i <= n && j <= m) {
		if (a[i] < b[j]) {
			c[++p] = a[i++];
		} else {
			c[++p] = b[j++];
		}
	}

	while (i <= n) {
		c[++p] = a[i++];
	}

	while (j <= m) {
		c[++p] = b[j++];
	}

	for (i = 1; i <= p; ++i) {
		printf("%d ", c[i]);
		if (i % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}
