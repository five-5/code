#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 21;
struct biginteger{
    int lenth;
    int num[maxn];
    biginteger()
    {
        lenth = 0;
        for (int i = 0; i < maxn; ++i)
            num[i] = 0;
    }
}origin, result;

// 字符串转biginteger
biginteger str2num(char *str)
{
    biginteger result;
    int lenth = strlen(str);
    result.lenth = lenth;
    for (int i = 0; i < lenth; ++i)
        result.num[i] = str[i] - '0';

    return result;
}

// 两倍
void twice(biginteger input, biginteger &result)
{
    if (input.num[0] >= 5)
        result.lenth = input.lenth + 1;
    else
        result.lenth = input.lenth;

    int inc = 0;
    int i = input.lenth - 1, j = result.lenth - 1;
    for(; i >= 0; --i, --j)
    {
        int tmp = input.num[i] * 2 + inc;
        result.num[j] = tmp % 10;
        inc = tmp / 10;
    }

    if (j == 0) result.num[j] = inc;
}

// 判断是否数字包含完全相同
bool isYes(biginteger a, biginteger b)
{
    if (a.lenth != b.lenth) return false;
    std::sort(a.num, a.num+a.lenth);
    std::sort(b.num, b.num+b.lenth);
    for (int i = 0; i < a.lenth; ++i)
        if (a.num[i] != b.num[i]) return false;

    return true;
}

int main()
{
    char str[21];
    scanf("%s", str);
    origin = str2num(str);
    twice(origin, result);
    if (isYes(origin, result)) printf("Yes\n");
    else printf("No\n");
    for (int i = 0; i < result.lenth; ++i)
        printf("%d", result.num[i]);
    return 0;
}
