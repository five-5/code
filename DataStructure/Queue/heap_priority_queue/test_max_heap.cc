/*
 * @Author: five-5
 * @Description: 测试最大堆
 * @Date: 2019-04-17
 * @LastEditTime: 2019-04-17
 */

#include <iostream>
#include <random>
#include <climits>
#include <vector>
#include <ctime>

#include "max_heap.hpp"

template <typename T>
void IsCorrect(MaxHeap<T> & max_heap, int lenth) {
    std::vector<int> arr(lenth);
    for (int i = 0; i < lenth; ++i) {
        arr[i] = max_heap.ExtractMax();
    }

    for (int i = 1; i < lenth; ++i) {
        if (arr[i - 1] < arr[i]) {
            throw std::runtime_error("Error");
        }
    }

    std::cout << "Test MaxHeap completed." << std::endl;
}

double  TestHeap(const std::vector<int> &test_data, bool is_heapify) {
    clock_t start = clock();
    
    if (is_heapify) {
        MaxHeap<int> max_heap(test_data);
        IsCorrect(max_heap, test_data.size());
    } else {
        MaxHeap<int> max_heap;
        for (size_t i = 0; i < test_data.size(); ++i) {
            max_heap.add(test_data[i]);
        }
        IsCorrect(max_heap, test_data.size());
    }
    
    clock_t end = clock();

    double elapse_time = (double)(end - start) / CLOCKS_PER_SEC;
    return elapse_time;
}

int main()
{
    int n = 1000000;

    std::default_random_engine random_engine(INT_MAX);
    std::vector<int> test_data(n);
    for (int i = 0; i < n; ++i) {
        test_data[i] = random_engine();
    }

    double time1 = TestHeap(test_data, false);
    std::cout << "Without heapify " << time1 << " s" << std::endl;
    
    double time2 = TestHeap(test_data, true);
    std::cout << "With heapify " << time2 << " s" << std::endl;

    
    return 0;
}