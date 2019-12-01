#include <cstdio>
#include <limits>
#include <algorithm>
#define maxn 510
struct station {
    double price;
    double distance;
} st[maxn];

bool cmp(const station &a, const station &b) {
    return a.distance < b.distance;
}

int main()
{
    double c, d, d_a;
    int n;
    scanf("%lf %lf %lf %d", &c, &d, &d_a, &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", &st[i].price, &st[i].distance);
    }
    // 将终点加入加油站中
    st[n].price = 0.0;
    st[n].distance = d;

    // 按距离对加油站进行排序
    std::sort(st, st + n, cmp);

    // 判断起点处是否有加油站
    if (st[0].distance != 0)
    {
        printf("The maximum travel distance = 0.00");
    }
    else
    {
        int now = 0;       // 当前所在加油站编号
        double curTank = 0, sum = 0, maxDistance = c * d_a;
        while (now < n)
        {
            // 在满载能行进的范围内找最低价的加油站进行加油
            int k = -1;
            double price_min = std::numeric_limits<double>::max();
            for (int i = now + 1; i <= n && st[i].distance - st[now].distance <= maxDistance; ++i) {
                if (st[i].price < price_min)
                {
                    price_min = st[i].price;
                    k = i;
                    if (price_min < st[now].price) break;
                }
            }
            // 判断是否没有能够行使到的加油站
            if (k == -1) break;
            // 有能行使到的加油站
            double tank = (st[k].distance - st[now].distance) / d_a;
            if (price_min < st[now].price)
            {
                if (curTank < tank)
                {
                    sum += (tank - curTank) * st[now].price;
                    curTank = tank;
                }
            }
            else
            {
                sum += (c - curTank) * st[now].price;
                curTank = c;
            }
            now = k;
            curTank -= tank;
        }

        if (now == n)
        {
            printf("%.2f", sum);
        }
        else
        {
            printf("The maximum travel distance = %.2f", st[now].distance + maxDistance);
        }
    }

    return 0;
}
