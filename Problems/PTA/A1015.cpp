#include <cstdio>
#include <cmath>

bool isPrime(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i <= std::sqrt(num); ++i)
    {
        if (num % i == 0) return false;
    }

    return true;
}

// 按radix进制将num反转，输出10进制的值
int rever(int num, int radix)
{
    int result = 0;
    while(num)
    {
        result = result * radix + num % radix;
        num /= radix;
    }
    return result;
}

int main()
{
    int n, d;
    while (1)
    {
        scanf("%d", &n);
        if (n < 0) break;
        scanf("%d", &d);

        if (isPrime(n) && isPrime(rever(n, d)))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
