#include <cstdio>
#include <algorithm>
#define maxn 1001

struct mooncake{
    double store;
    double sell;
    double price;
} mk[maxn];

bool cmp (const mooncake &a, const mooncake &b) {
    return a.price > b.price;
}

int main()
{
    int n;
    double d;
    scanf("%d %lf", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &mk[i].store);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &mk[i].sell);
        mk[i].price = mk[i].sell / mk[i].store;
    }
    std::sort(mk, mk + n, cmp);

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        if (mk[i].store >= d) {
            sum += mk[i].price * d;
            break;
        } else {
            sum += mk[i].sell;
            d -= mk[i].store;
        }
    }
    printf("%.2f", sum);
    return 0;
}
