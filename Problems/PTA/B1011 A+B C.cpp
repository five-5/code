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
        if ((a > c && b >=0) || (b > c && a >= 0)) {    // a,c��ͬ�ŵķ�Χ�Ͱ�������һ�������
            flag = true;
        } else if ((a > 0 && c > 0) || (a < 0 && c < 0)) {
            flag = (c - a) >= b ? false: true;           // a,cͬ��ʱ����ֱ��������ᳬ����Χ
        }
        std::cout << "Case #" << i << ": ";
        std::cout << (flag? "true" : "false") << std::endl;
    }
    return 0;
}

// ���򵥵ķ�����long long
