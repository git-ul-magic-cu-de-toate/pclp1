// Copyright 2020 Darius Neatu (neatudarius@gmail.com)

#include <stdio.h>
#include <string.h>

typedef union {
	char name[10];
	int age;
	double money;
} union_example_t;

int main(void)
{
	union_example_t u;

    // eu aleg ca u va fi folosit pentru varsta
	u.age = 10;
	printf("u.age = %d\n\n", u.age);

    // pot sa il folosesc pe u si pentru money,
    // DAR in acest moment il voi suprascrie pe age
	u.money = 123.45;
	printf("u.money = %2.2lf (ceea ce a m vrut)\n", u.money);
	printf("u.age = %d       (incorect pt ca am suprascris cu money)\n",
		   u.age);

	strcpy(u.name, "gigel e pe val");
	printf("u.name = %s\n", u.name);
	return 0;
}
