#include <cstdio>
#include <algorithm>
#define maxn 100001
int numbers[maxn];
int n;
long long findm(int left, long long key)
{
    //printf("start find %lld\n", key);
    int right = n - 1;
    if (numbers[right] <= key) return n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (numbers[mid] > key)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    int p;
    int ans = 1;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&numbers[i]);
    }
    std::sort(numbers, numbers + n);

    for (int i = 0; i < n; ++i)
    {
        int j = findm(i + 1, (long long)p*numbers[i]);
        ans = std::max(ans, j - i);
    }

    printf("%d", ans);
    return 0;
}
