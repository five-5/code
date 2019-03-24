/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 */

#include "array_stack.hpp"

int main() 
{
    ArrayStack<int> stack = ArrayStack<int>();

    for (int i = 0; i < 5; ++i) {
        stack.Push(i);
        std::cout << stack << std::endl;
    }
    
    stack.Pop();
    std::cout << stack << std::endl;

    return 0;   
}