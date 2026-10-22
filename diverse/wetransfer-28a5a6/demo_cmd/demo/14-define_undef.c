
#define SQR(x) ((x) * (x))
#define CUBE(x) ((x) * SQR(x))

int x = SQR(100 + 3);

// stergi SQR
#undef SQR

// int y  = SQR(100 + 3); // nu compileaza pt ca SQR nu e definit aici

int main(void) { return 0; }
