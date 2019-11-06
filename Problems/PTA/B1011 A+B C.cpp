#include <iostream>

int main()
{
    int T;
    std::cin >> T;

    for(int i = 1; i <= T; ++i) {
        int a,b,c;
        std::cin >> a >> b >> c;
        bool flag = false;
        // judge A+B > C
        if ((a > c && b >=0) || (b > c && a >= 0)) {    // a,c不同号的范围就包括在这一类别中了
            flag = true;
        } else if ((a > 0 && c > 0) || (a < 0 && c < 0)) {
            flag = (c - a) >= b ? false: true;           // a,c同号时可以直接相减不会超出范围
        }
        std::cout << "Case #" << i << ": ";
        std::cout << (flag? "true" : "false") << std::endl;
    }
    return 0;
}

// 更简单的方法，long long
