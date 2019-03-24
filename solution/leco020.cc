/*
 * @Author: five-5
 * @Description: leetcode 020 有效的括号
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 */

#include "../DataStructure/Stack/array_stack.hpp"

#include <iostream>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        ArrayStack<char> stack;
        for(size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{')
                stack.Push(c);
            else {
                if (stack.IsEmpty()) {
                    return false;
                }
                char top_char = stack.Top();
                if (c == ')' && top_char != '(') {
                    return false;
                }
                if (c == ']' && top_char != '[') {
                    return false;
                }
                if (c == '}' && top_char != '{') {
                    return false;
                }
                stack.Pop();
            }
        }
        
        return stack.IsEmpty();
    }
};

int main()
{

    std::cout << Solution().isValid("{}") << std::endl;
    std::cout << Solution().isValid("{[}") << std::endl;
    return 0;
}