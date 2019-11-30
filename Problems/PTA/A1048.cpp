#include <cstdio>
#define maxn 1001
int coins[maxn] = {0};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int coin;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &coin);
        ++coins[coin];
    }

    for (int i = 1; i <= 500 && m <= 1000 && i < m; ++i) {
        if (coins[i] && coins[m-i]) {
            if (m-i == i && coins[m-i] < 2) {
                continue;
            }

            printf("%d %d", i, m-i);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
