#include <cstdio>
#define maxnu 10001
#define maxn 100001
int number[maxnu] = {0};
int guess[maxn] = {0};

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &guess[i]);
        ++number[guess[i]];
    }
    int num = -1;
    for (int i = 0; i < maxn; ++i) {
        if (number[guess[i]] == 1) {
            num = guess[i];
            break;
        }
    }
    if (num == -1) printf("None");
    else printf("%d", num);
    return 0;
}
