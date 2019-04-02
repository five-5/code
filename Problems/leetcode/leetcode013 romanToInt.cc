/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-02
 */
/*
 * @Author: five-5
 * @Description: romanToInt
 * @Date: 2019-03-28
 * @LastEditTime: 2019-04-02
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> dict = {
                                {'I', 1},
                                {'V', 5},
                                {'X', 10},
                                {'L', 50},
                                {'C', 100},
                                {'D', 500},
                                {'M', 1000}};
        
        int result = 0;
        if (s.empty()) {
            return result;
        }
        
        int pre = s[0];
        for (size_t i = 1; i < s.size(); ++i) {
            
            printf("s[%d] = %c map[%c] = %d\n", i, s[i], pre, dict[pre]);
            
            if (dict[pre] >= dict[s[i]]) {
                result += dict[pre];
            } else {
                result -= dict[pre];
            }
            cout << "pre = " << pre << endl;
            cout << "result = " << result << endl;
            pre = s[i];
            
        }
        
        result += dict[s[s.size() - 1]];
        
        return result;
    }
};

int main()
{
    Solution so;
    cout << so.romanToInt("III") << endl;
    return 0;
}