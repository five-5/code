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
    // ���յ�������վ��
    st[n].price = 0.0;
    st[n].distance = d;

    // ������Լ���վ��������
    std::sort(st, st + n, cmp);

    // �ж���㴦�Ƿ��м���վ
    if (st[0].distance != 0)
    {
        printf("The maximum travel distance = 0.00");
    }
    else
    {
        int now = 0;       // ��ǰ���ڼ���վ���
        double curTank = 0, sum = 0, maxDistance = c * d_a;
        while (now < n)
        {
            // ���������н��ķ�Χ������ͼ۵ļ���վ���м���
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
            // �ж��Ƿ�û���ܹ���ʹ���ļ���վ
            if (k == -1) break;
            // ������ʹ���ļ���վ
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
