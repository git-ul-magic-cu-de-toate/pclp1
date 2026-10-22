int power_iterativ(int b, int e)
{
    int nr;
    nr = 1;

    if (e == 0)
        return 1;
    
    for(int i = 1; i <= e; i++)
        nr *= b;
    return nr;
}

int power_recursiv(int b, int e)
{
    int nr = b;
    if (e == 0)
        return 0;
    if (e == 1)
        return nr;
    else return nr * power_recursiv(b, e - 1);
    
}

int count_digits(int x)
{
    if (x < 9)
        return 1;
    else return 1 + count_digits(x/10); 
}

int reverse_number(int x)
{
    int cnt = count_digits(x) - 1;

    if (x <= 9)
        return x;
    return x % 10 * power_iterativ(10, cnt) + reverse_number(x / 10);
}

int is_palindrome(int x)
{
    if (x == reverse_number(x))
        return 1;
    else 
        return 0;
}

int next_palindrome(int x)
{
    while (1)
    {
        if (is_palindrome(x) == 1)
            return x;
        x++;
    }
}

int is_prime(int x)
{
    if (x == 2)
        return 1;
    else if (x < 2)
        return 0;
    else if (x % 2 == 0)
        return 0;
    else{
        for(int d = 3; 1L * d * d <= x; d += 2)
            if (x % d == 0)
                return 0;
    }
    return 1;
}