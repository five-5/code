#include <cstdio>

#define maxn 1001
char N[1001];

int main()
{
    int nums[10] = {0};
    scanf("%s", &N);
    for (int i = 0; N[i] != '\0'; ++i) {
        ++nums[N[i] - '0'];
    }

    for (int i = 0; i < 10; ++i) {
        if (nums[i] != 0) {
            printf("%d:%d\n", i, nums[i]);
        }
    }
    return 0;
}
