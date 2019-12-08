#include <cstdio>
#define maxn 100001
long long sum[maxn] = {0};

// 返回第一个大于x的下标
int upper_bound(int L, int R, int x)
{
    while (L < R)
    {
        int mid = L + (R-L)/2;
        if (sum[mid] > x)
        {
            R = mid;
        }
        else
        {
            L = mid + 1;
        }
    }

    return L;
}

int main()
{
    int n, m, nearm = 100000010;
    scanf("%d %d", &n, &m);
    // 边输入边获取前缀和
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }

    // 获取nearm
    for (int i = 1; i <= n; ++i)
    {
        int j = upper_bound(i, n + 1, sum[i-1] + m);
        if (sum[j-1] - sum[i-1] == m)
        {
            nearm = m;
            break;
        }
        else if (j <= n && sum[j] - sum[i-1] < nearm)
        {
            nearm = sum[j] - sum[i-1];
        }
    }

    // 输出所有序列和为nearm的段
    for (int i = 1; i <= n; ++i)
    {
        int j = upper_bound(i, n + 1, sum[i-1] + nearm);
        if (sum[j-1] - sum[i-1] == nearm)
            printf("%d-%d\n", i, j-1);
    }

    return 0;
}
