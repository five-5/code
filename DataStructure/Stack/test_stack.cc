/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-25
 */

#include "array_stack.hpp"
#include "link_list_stack.hpp"
#include "stack.h"

#include <cstdlib>
#include <ctime>

// 测试使用stack运行op_count个push和pop操作所需要的时间，单位：秒
double test_stack(Stack<int> *stack, int op_count) {
    clock_t start, end;
    
    start = clock();
    
    for (int i = 0; i < op_count; ++i) {
        stack->Push(i);
    }
    
    for (int i = 0; i < op_count; ++i) {
        stack->Pop();
    }

    
    end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    return duration;
}

int main() 
{
    int op_count = 10000000;

    // 两者的算法复杂度无大的差异
    // opcount链表栈的new操作会更多，虽然数组栈扩容缩容也会带来损耗

    ArrayStack<int> stack = ArrayStack<int>();
    double time1 = test_stack(&stack, op_count);
    std::cout << "ArrayStack, time: " << time1 << " s" << std::endl;

    LinkListStack<int> linkstack = LinkListStack<int>();
    double time2 = test_stack(&linkstack, op_count);
    std::cout << "LinkListStack, time: " << time2 << " s" << std::endl;

    return 0;   
}