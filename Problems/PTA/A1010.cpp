#include <string>
#include <iostream>
#include <map>

typedef long long LL;
LL inf = (1LL << 63) - 1;
std::string n1, n2;
int index;
LL radix;
std::map<char, int> maps;

void init()
{
    for (int i = 0; i < 10; ++i)
    {
        maps[i+'0'] = i;
    }

    for (int i = 0; i < 26; ++i)
    {
        maps[i+'a'] = i + 10;
    }
}
// 将str转换为10进制，t为值上届
LL tr_10(const std::string &str, LL radix, LL t)
{
    LL ans = 0;
    int len = str.size();
    for (int i = 0; i < len; ++i)
    {
        ans = ans * radix + maps[str[i]];
        if (ans < 0 || ans > t) return -1;  // 溢出
    }
    return ans;
}


int cmp(const std::string &str, LL radix, LL t)
{
    int len = str.size();
    LL num = tr_10(n2, radix, t);
    if (num < 0) return 1;   // 溢出
    if (t > num) return -1;
    else if (t == num) return 0;
    else return 1;
}


int get_left(const std::string &str)
{
    char re = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] > re) re = str[i];
    }
    return maps[re] + 1;
}

int binarySearch(const std::string &str, LL left, LL right, LL t)
{
    LL mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        int flag = cmp(str, mid, t);
        if (flag == 0) return mid;
        else if (flag == -1) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main()
{
    // 建立进制转换表
    init();

    std::cin >> n1 >> n2 >> index >> radix;

    // 默认知道n1的进制数
    if (index == 2)
    {
        std::swap(n1, n2);
    }

    // 判断二分查找的范围
    LL t = tr_10(n1, radix, inf);
    LL left = get_left(n2);
    LL right = std::max(left, t) + 1;
    LL ans = binarySearch(n2, left, right, t);
    if (ans == -1) printf("Impossible");
    else printf("%lld", ans);

}
