// 311CA Sava Victor
#include <stdio.h>
#include <math.h>
#define NMAX 1001

// function that reads the endpoint nodes and intensity of the wire between
// and stores the following values in columns:
// in column 0, stores the sum of the intensities entering the node
// in column 1, stores the sum of the intensities leaving the node
// in column 2, stores the number of wires entering or exiting the node
void store_intensity_matrix(double intensity[NMAX][3], int w)
{
	for (int i = 0; i < w; ++i) {
		// declare the endpoint nodes and intensity of the wire bewteen
		int start_node, final_node;
		double node_intensity;

		// read the endpoint nodes and intensity of the wire
		scanf("%d%d", &start_node, &final_node);
		scanf("%lf", &node_intensity);

		// in column 0, store the sum of the intensities entering the node
		// in column 1, store the sum of the intensities leaving the node
		// in column 2, store the number of wires entering or exiting the node
		intensity[final_node][0] += node_intensity;
		intensity[start_node][1] += node_intensity;
		intensity[final_node][2]++;
		intensity[start_node][2]++;
	}
}

// functions that checks if the circuit is open
// if the number of wires that enter or exit a node is less than 2
// then the circuit is open
// function returns 1 if the circuit is opened and 0 otherwise
int check_open_circuit(double intensity[NMAX][3], int n)
{
	for (int i = 1; i <= n; ++i) {
		if (intensity[i][2] < 2) {
			printf("Circuitul este deschis in nodul %d.\n", i);
			return 1;
		}
	}

	return 0;
}

// function that checks if the sum of the intensities entering the node
// is equal to the sum of the intensities leaving the node
// function returns 0 if the sums are not equal and 1 otherwise
int check_equal_sum_1(double intensity[NMAX][3], int n)
{
	// declare a constant epsilon as error
	const double eps = .00000001;

	for (int i = 1; i <= n; ++i) {
		// check if the difference between the sum of the intensities
		// entering the node and the sum of the intensities
		// leaving the node is bigger or equal to the error
		if (fabs(intensity[i][0] - intensity[i][1]) >= eps) {
			printf("Legea 1 a lui Kirchhoff nu se respecta pentru ");
			printf("egalitatea %.9lfA = ", intensity[i][0]);
			printf("%.9lfA ", intensity[i][1]);
			printf("in nodul %d.\n", i);
			return 0;
		}
	}

	return 1;
}

// function that checks if law 1 of Kirchhoff is respected
void check_law_1(void)
{
	// declare N - no. of nodes and W - no. of wires
	int n, w;

	// read N and W
	scanf("%d%d", &n, &w);

	// declare a matrix with 1001 rows and 3 columns, as there are 1000 nodes
	// in column 0, store the sum of the current intensities entering the node
	// in column 1, store the sum of the current intensities leaving the node
	// in column 2, store the number of wires entering or exiting the node
	double intensity[NMAX][3] = { 0 };

	// fill the intensity matrix with values
	store_intensity_matrix(intensity, w);

	// check if the circuit is open
	if (check_open_circuit(intensity, n) == 1) {
		return;
	}

	// check if the sum of the intensities entering the node
	// is equal to the sum of the intensities leaving the node
	if (check_equal_sum_1(intensity, n) == 0) {
		return;
	}

	// Law 1 is respected
	printf("Legea 1 a lui Kirchhoff se respecta pentru circuitul dat.\n");
}

// function that calculates the sum of resistances and generators
// function returns 1 if any generator component has a negative value
// and 0 otherwise
int calculate_sums(double *sum_r, double *sum_e, int w)
{
	for (int i = 0; i < w; ++i) {
		// declare the endpoint nodes and intensity of a wire
		// mumber of components and node intensity
		int start_node, final_node, no_components;
		double node_intensity;

		// read the endpoint nodes and intensity of a wire
		// mumber of components and node intensity
		scanf("%d%d%lf", &start_node, &final_node, &node_intensity);
		scanf("%d", &no_components);

		// for each component on a wire, read the type of component and value
		// if component is R add it to sum_R
		// if component is E add it to sum_E
		// if component is other letter print "Componenta dorita nu exista."
		for (int j = 0; j < no_components; ++j) {
			char component;
			double value;

			scanf(" %c", &component);

			if (component == 'R') {
				scanf("%lf", &value);

				*sum_r += node_intensity * value;
			} else if (component == 'E') {
				scanf("%lf", &value);

				if (value < 0) {
					printf("Sursa de tensiune nu poate fi negativa.\n");
					return 1;
				}

				*sum_e += value;
			} else {
				printf("Componenta dorita nu exista.\n");
				scanf("%lf", &value);
			}
		}
	}

	return 0;
}

// function that checks if the sum of resistance
// is equal to the sum of generators
// function returns 0 if the sums are not equal and 1 otherwise
int check_equal_sum_2(double sum_r, double sum_e)
{
	// declare a constant epsilon as error
	const double eps = .00000001;

	// check if the sum of resistance is equal to the sum of generators
	if (fabs(sum_r - sum_e) >= eps) {
		printf("Legea a 2-a lui Kirchhoff nu se respecta pentru egalitatea ");
		printf("%.9lfV = %.9lfV.\n", sum_r, sum_e);
		return 0;
	}

	return 1;
}

// function that checks if law 2 of Kirchhoff is respected
void check_law_2(void)
{
	// declare N - no. of nodes and W - no. of wires
	int n, w;

	// read N and W
	scanf("%d%d", &n, &w);

	// declare sum_R - the sum of resistance and sum_E - the sum of generators
	double sum_r, sum_e;
	sum_r = 0;
	sum_e = 0;

	// calculate sum_R and sum_E and check if any generator component
	// has a negative value
	if (calculate_sums(&sum_r, &sum_e, w) == 1) {
		return;
	}

	// check if the sum of resistance is equal to the sum of generators
	if (check_equal_sum_2(sum_r, sum_e) == 0) {
		return;
	}

	// the law is respected
	printf("Legea a 2-a lui Kirchhoff se respecta ");
	printf("pentru circuitul dat.\n");
}
