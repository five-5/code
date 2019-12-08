#include <string>
#include <iostream>
#include <algorithm>

const int maxn = 10001;

std::string str[maxn];
bool cmp(const std::string &a, const std::string &b)
{
    return a+b < b+a ;
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> str[i];
    }

    std::sort(str, str + n, cmp);
    std::string ans="";
    for (int i = 0; i < n; ++i)
    {
        ans += str[i];
    }

    // ȥ��ǰ��0
    while(ans.size()!=0 && ans[0] == '0')
    {
        ans.erase(ans.begin());
    }
    // ���sizeΪ0�������0
    std::cout << (ans.size() == 0 ? "0" : ans);
    return 0;
}
