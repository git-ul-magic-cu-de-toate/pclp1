#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 1000000


#

//10101111
//vrem al 6 lea bit
//10111111
int get_k_bit(char x, int k)
{
    char mask = (1 << k);
    if ((x & mask))
        return 1;
    return 0;
}

char set_k_bit(char x, int k)
{
    char mask = (1 << k);
    char a = (x | mask);
    return a;
}

char reset_k_bit(char x, int k)
{
    char mask = (1 << k);
    mask = (~ mask);
    char a = (x & mask);
    return a;
}

void insert(char *freq, int x)
{
    int cat = x / 8;
    int rest = x % 8;
    freq[cat] = set_k_bit(freq[cat], rest);
}

void rmove(char *freq, int x)
{
    int cat = x / 8;
    int rest = x % 8;
    freq[cat] = reset_k_bit(freq[cat], rest);
}

int is_in_set(char *freq, int x)
{
    int cat = x / 8;
    int rest = x % 8;
    return get_k_bit(freq[cat], rest);
}

int cardinal(char *freq)
{
    int cnt = 0;
    for (int i = 0; i < NMAX; i++) {
        if (is_in_set(freq, i))
            cnt++;
    }
    return cnt;
}

int main()
{
    int n, x;
    scanf("%d", &n);
    char *freq = (char *)calloc(NMAX / 8, sizeof(char));
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(freq, x);
    }
    rmove(freq, 20);
    printf("%d\n", is_in_set(freq, 1));
    printf("%d\n", cardinal(freq));
    return 0;
}