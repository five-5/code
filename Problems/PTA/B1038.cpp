#include <cstdio>

int numbers[101] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    int tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        ++numbers[tmp];
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &tmp);
        if (i > 0) printf(" ");
        printf("%d",numbers[tmp]);

    }
    return 0;
}
