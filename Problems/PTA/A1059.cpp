#include <cstdio>
#include <cmath>
const int maxn = 100010;

bool isPrime(long long num)
{
    if (num <= 1) return false;
    for(int i = 2; i <= std::sqrt(num); ++i)
    {
        if (num % i == 0) return false;
    }
    return true;
}

// 构造素数表
int prime[maxn] = {0}, pNum = 0;
void buildTable()
{
    for (int i = 1; i < maxn; ++i)
    {
        if (isPrime(i)) prime[pNum++] = i;
    }
}

int main()
{
    buildTable();
    long long n;
    scanf("%lld", &n);

    printf("%lld=", n);
    if (n == 1) printf("1");
    else
    {
        bool first = true;
        int sqr = std::sqrt(n);
        for (int i = 0; i < pNum && prime[i] <= sqr; ++i)
        {
            int times = 0;
            if (n % prime[i] == 0)
            {
                while (n != 1 && n % prime[i] == 0)
                {
                    ++times;
                    n /= prime[i];
                }
                if (times > 0)
                {
                    if (!first) printf("*");
                    printf("%d", prime[i]);
                    first = false;
                    if (times > 1) printf("^%d", times);
                }
            }
            if (n == 1) break;
        }
        // 如果是大于根号的因子
        if (n != 1)
        {
            if (!first) printf("*");
            printf("%lld", n);
        }

    }

    return 0;
}
