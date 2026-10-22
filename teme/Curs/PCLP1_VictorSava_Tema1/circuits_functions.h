// 311CA Sava Victor
#define NMAX 1001

// functions for law 1
void store_intensity_matrix(double intensity[NMAX][3], int w);
int check_open_circuit(double intensity[NMAX][3], int n);
int check_equal_sum_1(double intensity[NMAX][3], int n);
void check_law_1(void);

// functions for law 2
int calculate_sums(double *sum_r, double *sum_e, int w);
int check_equal_sum_2(double sum_r, double sum_e);
void check_law_2(void);
