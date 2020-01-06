#include <iostream>
#include <cstring>

const int MAXN = 110;

bool isPass(char str[])
{
    int numP = 0, numT = 0, localP = -1, localT = -1;
    int lenth = strlen(str);
    for (int i = 0; i < lenth; ++i)
    {
        if (str[i] == 'P')
        {
            ++numP;
            localP = i;
        }
        else if (str[i] == 'T')
        {
            ++numT;
            localT = i;
        }
        else if (str[i] != 'A')
            return false;
    }
    // x: P左边A的个数 y: P和T中间A的个数  z：T后面A的个数
    int x = localP, y = localT - localP - 1, z = lenth - localT - 1;
    if (numP != 1 || numT != 1 || y <=0 )
        return false;
    // 还原为规则2，看是否满足
    if (z - x * (y - 1) == x)
        return true;
    else
        return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        char str[MAXN];
        scanf("%s", str);
        if (isPass(str)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
