// 311CA Sava Victor
#define NMAX 1001
typedef unsigned long long ull;

void print_matrix(char digit_matrix[NMAX][NMAX], int n, int m);
void fill_matrix_with_space(char digit_matrix[NMAX][NMAX], int n, int m);

// functions for filling segments a to g
void fill_a(char digit_matrix[NMAX][NMAX], int len);
void fill_b(char digit_matrix[NMAX][NMAX], int len);
void fill_c(char digit_matrix[NMAX][NMAX], int len);
void fill_d(char digit_matrix[NMAX][NMAX], int len);
void fill_e(char digit_matrix[NMAX][NMAX], int len);
void fill_f(char digit_matrix[NMAX][NMAX], int len);
void fill_g(char digit_matrix[NMAX][NMAX], int len);

// functions for filling a matrix with digit from 0 to 9
void fill_matrix_zero(char digit_matrix[NMAX][NMAX], int n, int m, int len);
void fill_matrix_one(char digit_matrix[NMAX][NMAX], int n, int m, int len);
void fill_matrix_two(char digit_matrix[NMAX][NMAX], int n, int m, int len);
void fill_matrix_three(char digit_matrix[NMAX][NMAX], int n, int m, int len);
void fill_matrix_four(char digit_matrix[NMAX][NMAX], int n, int m, int len);
void fill_matrix_five(char digit_matrix[NMAX][NMAX], int n, int m, int len);
void fill_matrix_six(char digit_matrix[NMAX][NMAX], int n, int m, int len);
void fill_matrix_seven(char digit_matrix[NMAX][NMAX], int n, int m, int len);
void fill_matrix_eight(char digit_matrix[NMAX][NMAX], int n, int m, int len);
void fill_matrix_nine(char digit_matrix[NMAX][NMAX], int n, int m, int len);

void fill_matrix_with_digit(char digit_matrix[NMAX][NMAX],
							int n, int m, int len);

// functions for translation of a matrix
void move_up(char digit_matrix[NMAX][NMAX], int n, int m, ull count);
void move_left(char digit_matrix[NMAX][NMAX], int n, int m, ull count);
void move_down(char digit_matrix[NMAX][NMAX], int n, int m, ull count);
void move_right(char digit_matrix[NMAX][NMAX], int n, int m, ull count);

// functions for type of command in main()
void case_w(char digit_matrix[NMAX][NMAX], int n, int m);
void case_a(char digit_matrix[NMAX][NMAX], int n, int m);
void case_s(char digit_matrix[NMAX][NMAX], int n, int m);
void case_d(char digit_matrix[NMAX][NMAX], int n, int m);
void case_invalid(void);
