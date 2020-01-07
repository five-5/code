#include <cstdio>
#include <cstring>
const int maxn = 1001;
char num[maxn], result[maxn];

int main()
{
    int dividor, left = 0, j = 0;
    scanf("%s %d", num, &dividor);
    auto lenth = strlen(num);
    for(int i = 0; i < lenth; ++i)
    {
        int tmp = left * 10 + num[i] - '0';
        if (tmp < dividor)
        {
            left = tmp;
            if ( i != 0)
                result[j++] = '0';
        }
        else
        {
            result[j++] = tmp / dividor + '0';
            left = tmp % dividor;
        }
    }
    if (j == 0) result[j++] = '0';
    result[j] = '\0';
    printf("%s %d", result, left);
    return 0;
}
