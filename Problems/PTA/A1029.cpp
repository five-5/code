#include <cstdio>
#include <algorithm>

#define maxn 200001

long first[maxn], second[maxn];

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%ld",&first[i]);
    }
    std::sort(first, first + n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%ld",&second[i]);
    }
    std::sort(second, second + m);
    // ËÄÉáÎåÈë
    long key = (n+m)/2;
    if ((n+m) % 2)
    {
        ++key;
    }
    int i,j;
    for (i = 1, j = 1; i <= n && j <= m;)
    {
        if (first[i-1] <= second[j-1])
        {
            if (i+j-1 == key)
            {
                printf("%ld",first[i-1]);
                return 0;
            }
            ++i;
        }
        else
        {
            if (i+j-1 == key)
            {
                printf("%ld",second[j-1]);
                return 0;
            }
            ++j;
        }
    }

    if (i<=n)
    {
        printf("%ld",first[key+1-i-j]);
    }
    else if (j<=m)
    {
        printf("%ld",second[key+1-i-j]);
    }
    return 0;
}
