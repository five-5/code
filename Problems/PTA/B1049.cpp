#include <cstdio>
const int MAXN = 100001;
double in[MAXN];
int main()
{
    int n;
    double result = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lf", &in[i]);
        result += in[i] * i * (n + 1 - i);
    }

    printf("%.2f", result);

    return 0;
}
