#include <iostream>
#define maxn 2001

double a[11];
double e[maxn] = {0.0};
int ae[11];

int main()
{
    int m, n;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> ae[i] >> a[i];
    }
    std::cin >> n;
    int be;
    double b;
    for (int j = 0; j < n; ++j) {
        std::cin >> be >> b;
        for (int i = 0; i < m; ++i) {
            e[ae[i] + be] += a[i] * b;
        }
    }

    int count = 0;
    for (int i = 0; i < maxn; ++i) {
        if (e[i] != 0.0) {
            ++count;
        }
    }

    printf("%d", count);
    for (int i = maxn - 1; i >= 0; --i) {
        if (e[i] != 0.0) {
            printf(" %d %.1f", i, e[i]);
        }
    }
    std::cout << std::endl;

    return 0;
}
