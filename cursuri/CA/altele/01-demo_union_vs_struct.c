// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>

typedef struct {
	char name[10];
	int age;
	double money;
} struct_example_t;

typedef union {
	char name[10];
	int age;
	double money;
} union_example_t;

int main(void)
{
	struct_example_t s;
	union_example_t u;

	printf("\n struct_example_t s;\n");
	printf("&s       = %p\n", &s);
	printf("&s.name  = %p\n", &s.name);
	printf("&s.age   = %p\n", &s.age);
	printf("&s.money = %p\n", &s.money);

	printf("\n union_example_t u;\n");
	printf("&u       = %p\n", &u);
	printf("&u.name  = %p\n", &u.name);
	printf("&u.age   = %p\n", &u.age);
	printf("&u.money = %p\n", &u.money);

	printf("conclusion?\n");

	return 0;
}
