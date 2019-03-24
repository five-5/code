/*
 * @Author: five-5
 * @Description: 测试数组队列和循环队列
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-25
 */

#include "array_queue.hpp"
#include "loop_queue.hpp"

#include <ctime>
#include <cstdlib>

// 测试使用q运行op_count个push和pop的时间测试
template <typename T>
double TestQueue(Queue<T> *q, int op_count) {
    clock_t start, end;
    double duration;
    start = clock();
    for (int i = 0; i < op_count; ++i) {
        q->push(i);
    }

    for (int i = 0; i < op_count; ++i) {
        q->pop();
    }
    
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    return duration;
}


int main()
{
    ArrayQueue<int> queue = ArrayQueue<int>();
    for (int i = 0; i < 10; ++i) {
        queue.push(i);
        cout << queue << endl;

        if (i % 3 == 2) {
            queue.pop();
            cout << queue << endl;
        }
    }

    LoopQueue<int> loop_queue = LoopQueue<int>();
    for (int i = 0; i < 10; ++i) {
        loop_queue.push(i);
        cout << loop_queue << endl;

        if (i % 3 == 2) {
            loop_queue.pop();
            cout << loop_queue << endl;
        }
    }

    int op_count = 10e4;

    ArrayQueue<int> queue1 = ArrayQueue<int>();
    double time1 = TestQueue(&queue1, op_count);
    std::cout << "ArrayQueue, time: " << time1 << " s" << std::endl;

    LoopQueue<int> loop_queue1 = LoopQueue<int>();
    double time2 = TestQueue(&loop_queue1, op_count);
    std::cout << "LoopQueue, time: " << time2 << " s" << std::endl;
    
    
    return 0;
}