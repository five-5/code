#include <cstdio>
#include <algorithm>

#define maxn 100001
int coins[maxn] = {0};

int found(int left, int right, int key)
{
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if (coins[mid] == key)
        {
            return mid;
        }
        else if (coins[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&coins[i]);
    }
    std::sort(coins, coins + n);
    int j = -1;
    for (int i = 0; i < n && coins[i] <= m/2; ++i)
    {

        j =found(i+1, n-1, m-coins[i]);
        if (j != -1)
        {
            printf("%d %d", coins[i], coins[j]);
            break;
        }
    }

    if (j == -1)
        printf("No Solution");
    return 0;
}
