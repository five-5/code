#include <cstdio>
#include <algorithm>

typedef long long ll;
struct fraction
{
    long long up;
    long long down;
}sum, tmp;

ll gcd(ll a, ll b); // a,b最大公约数
fraction reduction(fraction result); // 化简
fraction add(fraction a, fraction b);
void showResult(fraction f);

int main()
{
    int n;
    scanf("%d", &n);
    sum.up = 0, sum.down = 1;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld/%lld", &tmp.up, &tmp.down);
        sum = add(sum, tmp);
    }
    showResult(sum);
    return 0;
}

// a,b最大公约数
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 化简
fraction reduction(fraction result)
{
    if (result.down < 0)
    {
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0)
    {
        result.down = 1;
    }
    else
    {
        int d = gcd(std::abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

// 分数相加
fraction add(fraction a, fraction b)
{
    fraction result;
    result.up = a.up * b.down + b.up * a.down;
    result.down = a.down * b.down;
    return reduction(result);
}

// 展示结果
void showResult(fraction f)
{
    reduction(f);
    if (f.down == 1) printf("%lld\n", f.up);
    else if (std::abs(f.up) > f.down) printf("%lld %lld/%lld\n", f.up/f.down, std::abs(f.up) % f.down, f.down);
    else printf("%lld/%lld\n", f.up, f.down);
}
