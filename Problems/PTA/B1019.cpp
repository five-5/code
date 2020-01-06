#include <cstdio>
#include <algorithm>

bool cmp(int a, int b)
{
    return a > b;
}

void to_array(int n, int num[])
{
    for (int i = 0; i < 4 && n!= 0; ++i)
    {
        num[i] = n %10;
        n /= 10;
    }
}

int to_number(int num[])
{
    int result = 0;
    for (int i = 0; i < 4; ++i)
    {
        result = result * 10 + num[i];
    }

    return result;
}

int main()
{
    int n, MAX, MIN;
    scanf("%d", &n);
    int num[5];
    while (1)
    {
        to_array(n, num);
        std::sort(num, num + 4);
        MIN = to_number(num);
        std::sort(num, num + 4, cmp);
        MAX = to_number(num);
        n = MAX - MIN;
        printf("%04d - %04d = %04d\n", MAX, MIN, n);
        if (n == 0 || n == 6174) break;
    }
    return 0;
}
