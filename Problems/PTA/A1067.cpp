#include <cstdio>
#include <algorithm>
#define maxn 100010

int pos[maxn];


int main()
{
    int n;
    scanf("%d", &n);
    int left = n - 1, num;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num);
        pos[num] = i;
        if (num == i && num != 0 )
        {
            --left;
        }
    }

    int k = 1;  // 存放除0以外当前不在本位上的最小的数
    int times = 0;
    while (left > 0)
    {
        if (pos[0] == 0)
        {
            while (k < n)
            {
                if (pos[k] != k)
                {
                    std::swap(pos[0], pos[k]);
                    ++times;
                    break;
                }
                ++k; // 下次判断初始位置
            }
        }

        while (pos[0] != 0)
        {
            std::swap(pos[0], pos[pos[0]]);
            ++times;
            --left;
        }
    }

    printf("%d", times);
    return 0;
}
