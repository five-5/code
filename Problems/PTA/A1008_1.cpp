#include <cstdio>
const int MAXN = 101;
int A[MAXN];
int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    int n, m, tmp, pos, next;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &A[i]);
    }

    m = m % n;
    if (m != 0)
    {
        int d = gcd(n, m); // d为n和m的最大公约数及覆盖整个数组需要遍历的次数
        for (int i = n - m; i < n - m + d; ++i)
        {
            tmp = A[i];
            pos = i;
            do {
                next = (pos - m + n) % n;
                if (next != i) A[pos] = A[next];
                else A[pos] = tmp;
                pos = next;
            } while (pos != i);
        }
    }

    printf("%d", A[0]);
    for (int i = 1; i < n; ++i)
    {
        printf(" %d", A[i]);
    }
}
