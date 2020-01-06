#include <cstdio>
#include <cmath>

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i <= std::sqrt(n); ++i)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int main()
{
    int n, count = 0;
    scanf("%d", &n);

    for (int i = 3; i + 2 <= n; i+=2)
    {
        if (isPrime(i) && isPrime(i+2))
        {
            ++count;
        }
    }
    printf("%d", count);
    return 0;
}
