// 311CA Sava Victor
#define NMAX 10000

void read_type_value(long long *hp, int n, int *shield_count,
					 unsigned int shield[NMAX]);

void sort_vector(int shield_count, unsigned int shield[NMAX]);

unsigned int find_max_shield(int shield_count, unsigned int shield[NMAX],
							 unsigned int dmg);

void remove_shield(int *shield_count, unsigned int shield[NMAX],
				   unsigned int *max_shield);

void boss_fight(int k, unsigned int shield[NMAX], unsigned int m, long long hp);
