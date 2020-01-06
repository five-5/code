#include <cstdio>
#include <cmath>

int main()
{
    long long n;
    scanf("%lld", &n);
    long long sqrn = std::sqrt(n), lenth = 0, start = 0;
    // 遍历连续因子第一个数从[2,sqrt(n)]
    for (int i = 2; i <= sqrn; ++i)
    {
        long long j = i, tmp = 1;
        while(1)
        {
            tmp *= j;
            if (n % tmp != 0) break;
            if (j - i + 1 > lenth)
            {
                lenth = j - i + 1;
                start = i;
            }
            ++j;
        }
    }

    // 如果无解，只有自身是自己的因子
    if (lenth == 0)
    {
        printf("1\n%lld", n);
    }
    else
    {
        printf("%lld\n", lenth);
        for (int i = 0; i < lenth; ++i)
        {
            if (i > 0) printf("*");
            printf("%lld", start + i);
        }
    }
    return 0;
}
