#include <cstdio>
#include <algorithm>
#define maxn 100001
int coupon[maxn];
int product[maxn];
int main()
{
    int nc, np;
    scanf("%d", &nc);
    for (int i = 0; i < nc; ++i)
    {
        scanf("%d", &coupon[i]);
    }
    scanf("%d", &np);
    for (int i = 0; i < np; ++i)
    {
        scanf("%d", &product[i]);
    }
    long long sum = 0;
    // 从小到大排序
    std::sort(coupon, coupon + nc);
    std::sort(product, product + np);

    // 正向处理负数
    for (int i = 0, j = 0; i < nc && j < np; ++i, ++j)
    {
        if (coupon[i] < 0 && product[j] < 0)
        {
            sum += coupon[i] * product[j];
        }
        else
        {
            break;
        }
    }

    // 反向处理正数
    for (int i = nc - 1, j = np - 1; i >= 0 && j >= 0; --i, --j)
    {
        if (coupon[i] > 0 && product[j] > 0)
        {
            sum += coupon[i] * product[j];
        }
        else
        {
            break;
        }
    }
    printf("%lld", sum);
    return 0;
}
