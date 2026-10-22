int is_bisect(int an)
{
    if ((an % 4 == 0 && an % 100 != 0) || (an % 400 == 0))
        return 1;
    else
        return 0;
}

int interval(int zi1, int luna1, int an1, int zi2, int luna2, int an2)
{
    int zile_luna[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int interval = 0;
    if (an2 - an1 == 0)
    {
        if (luna2 - luna1 == 0)
            return zi2 - zi1;
        else
        {
            for (int luna = luna1; luna <= luna2; luna++)
                interval += zile_luna[luna];
        }
    }
    else if (an2 - an1 == 1)
    {
        if (luna2 - luna1 < 0)
        {
            for (int luna = luna1 + 1; luna <= 12; luna++)
                interval += zile_luna[luna];
            for (int luna = 1; luna <= luna2 - 1; luna++)
                interval += zile_luna[luna];
            interval += zi1 + zi2;
        }
        else if (luna2 == luna1)
        {
            if (zi2 < zi1)
            {
                interval += 365 - (zi2 - zi1);
            }
            else
            {
                interval += 365 + zi2 - zi1;
            }
        }
    }
}