/*
 * @Author: five-5
 * @Description: bubble sort
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-28
 */

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;

// basic version
template <typename T, size_t len>
void BubbleSort(T (&arr)[len]) {
    for (size_t i = 0; i < len - 1; ++i) {
        for (size_t j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

// optimized version 
template <typename T, size_t len>
void BubbleSortPlus(T (&arr)[len]) {
    bool orderly = false;
    for (size_t i = 0; i < len - 1 && (!orderly); ++i) {
        orderly = true;
        for (size_t j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j+1]) {
                orderly = false;
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

template <typename T>
void print(T *begin, T *end) {
    for (auto it = begin; it != end; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 3, 9, 5, 0};

    cout << "original arr : " << endl; 
    print(std::begin(arr), std::end(arr));

    BubbleSort(arr);

    cout << "after sort arr by basic: " << endl; 
    print(std::begin(arr), std::end(arr));

    int arr1[] = {1, 3, 9, 5, 0};
    cout << "original arr1 : " << endl; 
    print(std::begin(arr1), std::end(arr1));

    BubbleSortPlus(arr1);
    
    cout << "after sort arr1 by plus: " << endl; 
    print(std::begin(arr1), std::end(arr1));

    return 0;
}