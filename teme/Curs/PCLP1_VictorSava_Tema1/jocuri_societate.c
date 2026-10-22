// 311CA Sava Victor
#include <stdio.h>
#include "joc_soc_functions.h"
#define NMAX 10000

int main(void)
{
	// declare the hp(health points) variable
	// and n the no. of objects(shield or health potion)
	long long hp;
	int n;

	// read the hp and n variable
	scanf("%lld%d", &hp, &n);

	// declare shield_count for the number of shields
	// and shield - a vector that stores the value of each shield
	int shield_count = 0;
	unsigned int shield[NMAX] = { 0 };

	// read n pairs of type and value
	// store in shield vector the shield objects
	// and update the shield_count
	read_type_value(&hp, n, &shield_count, shield);

	// sort the shield vector
	sort_vector(shield_count, shield);

	// declare m - no. of enemies
	unsigned int m;

	// read m - no. of enemies
	scanf("%u", &m);

	// print the initial health points
	printf("Initial health points: %lld\n", hp);

	// function that processes M enemy damage, updating HP and managing shields
	// finds max_shield <= damage; updates HP
	// removes max_shield from shield array
	// display HP and max_shield if HP >= 0; "You died." if HP < 0
	// displays "Foe Vanquished" if all enemies are defeated
	boss_fight(shield_count, shield, m, hp);

	return 0;
}
