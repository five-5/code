#include <iostream>
#include <string>

std::string getSuffix(const std::string &pre, const std::string &cur) {

    int plenth = pre.size();
    int clenth = cur.size();

    // 为空或者一开始就不同直接返回
    if (plenth == 0 || clenth == 0 || pre[plenth-1] != cur[clenth - 1])
        return "";
    int i = 0;
    for ( ; i < plenth && i < clenth; ++i) {
        if (pre[plenth - 1 - i] != cur[clenth - 1 - i]) {
            break;
        }
    }

    return cur.substr(clenth - i, i);
}

int main()
{
    int N;
    char tmp;
    std::string pre, cur;
    std::cin >> N;
    std::cin.get(tmp);  // 去除换行符
    getline(std::cin, pre);
    for (int i = 1; i < N; ++i) {
        getline(std::cin, cur);
        pre = getSuffix(pre, cur);
    }

    if (pre.size() != 0) {
        std::cout << pre;
    } else {
        std::cout << "nai";
    }
    return 0;
}
