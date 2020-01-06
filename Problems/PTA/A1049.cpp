#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int total = 0, a = 1;
    int left, cur, right;
    while ( n / a != 0)
    {
        left = n / (a*10);
        cur = n /a % 10;
        right = n % a;
        if (cur == 0) total += left * a;
        else if (cur == 1) total += left * a + right + 1;
        else if (cur > 1) total += (left + 1) * a;
        a *= 10;
    }
    printf("%d", total);
    return 0;
}
