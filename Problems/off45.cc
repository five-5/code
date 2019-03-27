/*
 * @Author: five-5
 * @Description: 剑指offer45 把数组排成最小的数
 * @Date: 2019-03-27
 * @LastEditTime: 2019-03-27
 */
#include <algorithm>
#include <iostream>
#include <vector>



class Solution {
public:
    static std::string ToStr (int ival) {
        std::string result;
        while (ival) {
            result += '0' + ival % 10;
            ival /= 10;
        }
        return std::string(result.rbegin(), result.rend());
    }
    
    static bool compare (int a, int b) {
        std::string ab = ToStr(a) + ToStr(b);
        std::string ba = ToStr(b) + ToStr(a);
        if (ab <= ba) {
            return true;
        } else {
            return false;
        }
    }
    std::string PrintMinNumber(std::vector<int> numbers) {
        std::string result = "";
        if (numbers.empty()) {
            return result;
        }
        
        std::sort(numbers.begin(), numbers.end(), compare);
        
        for (auto num : numbers) {
            result += ToStr(num);
        }
        
        return result;
    }
};

int main()
{
    Solution solo;
    std::vector<int> vec = {3, 32, 321};
    std::cout << solo.PrintMinNumber(vec);
}