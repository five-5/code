#include <cstdio>
#include <cmath>
const int MAXN = 10001;
long long prime[MAXN];

bool isPrime(long long num)
{
    if (num <= 1) return false;
    for (long long i = 2; i <= std::sqrt(num); ++i)
    {
        if (num % i == 0) return false;
    }
    return true;
}

void init(int s, int e)
{
    int count = 0;
    for (long long i = 2; count < e; ++i)
    {
        if (isPrime(i))
        {
            ++count;
            if (count >= s)
                prime[count-s] = i;
        }
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    init(m, n);
    for (int i = 0; i <= n - m; ++i)
    {
        if (i % 10)
            printf(" ");
        else if (i != 0)
            printf("\n");
        printf("%lld", prime[i]);
    }
    return 0;
}
