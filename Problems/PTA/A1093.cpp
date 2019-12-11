#include <cstdio>
#include <cstring>
#define maxn 100005
const int MOD = 1000000007;
char str[maxn];
int leftP[maxn] = {0};
int main()
{
    scanf("%s", str);
    int lenth = strlen(str);
    for (int i = 0; i < lenth; ++i)
    {
        if (i > 0)
            leftP[i] = leftP[i-1];

        if (str[i] == 'P')
            ++leftP[i];
    }
    int rightT = 0;
    long result = 0;


    for (int i = lenth - 1; i >=0; --i)
    {
        if (str[i] == 'T') ++rightT;
        else if (str[i] == 'A')
            result = (result + leftP[i] * rightT) % MOD;
    }

    printf("%ld",result);
    return 0;
}
