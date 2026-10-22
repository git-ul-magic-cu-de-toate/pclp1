// 311CA Sava Victor
#include <stdio.h>
#define NMAX 10000

// read n pairs in the form of type and value
// if type is 'H' then add it to hp
// if type is 'S' then put it in the shield array
// if type is any other character is and invalid type
// at the end, return the variable hp and k by reference
void read_type_value(long long *hp, int n, int *shield_count,
					 unsigned int shield[NMAX])
{
	// declare a character variable named type
	// and an unsigned int variable named value
	char type;
	unsigned int value;

	// for each pair of type and value check
	// if type is 'H' then add it to hp
	// if type is 'S' then put it in the shield array
	// if type is any other character is and invalid type
	for (int i = 0; i < n; ++i) {
		scanf(" %c", &type);
		scanf("%u", &value);
		if (type == 'H') {
			*hp += value;
		} else if (type == 'S') {
			shield[*shield_count] = value;
			(*shield_count)++;
		} else {
			printf("Invalid item type.\n");
		}
	}
}

// function that sorts a vector
void sort_vector(int shield_count, unsigned int shield[NMAX])
{
	for (int i = 0; i < shield_count; ++i) {
		for (int j = i + 1; j < shield_count; ++j) {
			if (shield[i] > shield[j]) {
				unsigned int tmp = shield[i];

				shield[i] = shield[j];
				shield[j] = tmp;
			}
		}
	}
}

// function that finds the largest shield item
// less than or equal to the enemy's damage
// if there are no shields left that are smaller or equal
// to the damage dealt, it will return the smallest remaining shield
// and if k is 0, it returns 0
unsigned int find_max_shield(int shield_count, unsigned int shield[NMAX],
							 unsigned int dmg)
{
	if (shield_count == 0) {
		return 0;
	}

	for (int i = shield_count - 1; i >= 0; --i) {
		if (dmg >= shield[i]) {
			return shield[i];
		}
	}
	return shield[0];
}

// function that removes max_shield from the shield array
void remove_shield(int *shield_count, unsigned int shield[NMAX],
				   unsigned int *max_shield)
{
	// declare a pos variable that finds the position of max_shield
	int pos;

	// find the position of max_shield
	for (int i = 0; i < *shield_count; ++i) {
		if (shield[i] == *max_shield) {
			pos = i;
			break;
		}
	}

	// remove the max_shield
	for (int i = pos; i < *shield_count; ++i) {
		shield[i] = shield[i + 1];
	}
	(*shield_count)--;
}

// function that processes M enemy damage, updating HP and managing shields
// finds max_shield <= damage; updates HP, removes max_shield from shield array
// display HP and max_shield if HP >= 0; "You died." if HP < 0
// displays "Foe Vanquished" if all enemies are defeated
void boss_fight(int k, unsigned int shield[NMAX], unsigned int m, long long hp)
{
	while (m) {
		// declare a dmg variable for the damage dealt by an enemy in one round
		unsigned int dmg;

		// read the dmg variable
		scanf("%u", &dmg);

		// declare and initialise max_shield to the shield
		// smaller or equal to the damage dealt
		unsigned int max_shield = find_max_shield(k, shield, dmg);

		// if the damage dealt by an enemy is bigger or equal to max shield
		// update the hp
		if (dmg >= max_shield) {
			hp -= dmg - max_shield;
		}

		// remove the max_shield from shield array
		remove_shield(&k, shield, &max_shield);

		if (hp > 0) {
			if (max_shield == 0) {
				// if max_shield is 0, meaning there are no more shields
				// print hp
				printf("%lld\n", hp);
			} else {
				// if max_shield is not 0
				// print hp
				printf("%lld %u\n", hp, max_shield);
			}
		} else {
			// if hp is negative
			if (max_shield != 0) {
				// if there are still shields in shield vector
				// print 0 and max_shield
				printf("0 %u\n", max_shield);
			} else {
				// if there are no more shields int shield vector
				// print 0
				printf("0\n");
			}
			// at the end print "You died."
			printf("You died.\n");
			break;
		}

		// next enemy
		m--;
	}

	// if there are no more attacks print "Foe Vannquished!"
	if (m == 0) {
		printf("Foe Vanquished!\n");
	}
}
