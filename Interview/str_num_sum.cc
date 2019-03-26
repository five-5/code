/*
 * @Author: five-5
 * @Description: str num sum
 * @Date: 2019-03-26
 * @LastEditTime: 2019-03-26
 */


#include <iostream>
#include <string>

int main()
{
    std::string str;
    while (std::cin >> str) {
        long long result = 0;
        long tmp = 0;
        int  flag = 1;
        for (auto ch : str) {
            if (ch >= '0' && ch <= '9') {
                tmp =  (ch - '0') + tmp * 10;
            } else if (ch == '-') {
                result += tmp * flag;
                flag = -1;
                tmp = 0;
            } else {
                result += tmp * flag;
                flag = 1;
                tmp = 0;
            }
            
            std::cout << "tmp = " << tmp << " ch = " << ch << std::endl;
        }
        char ch = str[str.size() - 1];
        if ( ch >= '0' && ch <= '9') {
            result += tmp * flag;
        }
        std::cout << result << std::endl;
    }
    
    return 0;
}