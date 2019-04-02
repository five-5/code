/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 */

#include <iostream>

using std::cout;
using std::endl;

template <typename T, size_t len>
void QuickSortImp(T (&arr)[len], size_t first, size_t last) {
    if (first >= last) {
        return;
    }
    
    size_t low = first;
    size_t high = last;
    T key = arr[first];

    while (first < last) {
        while (first < last && arr[last] >= key) {
            --last;
        }
        if (first < last) {
            arr[first++] = arr[last];
        }

        while (first < last && arr[first] <= key) {
            ++first;
        }
        if (first < last) {
            arr[last--] = arr[first];
        }
    }

    arr[first] = key;
    QuickSortImp(arr, low, first - 1);
    QuickSortImp(arr, first + 1, high);
}

template <typename T, size_t len>
void QuickSort(T (&arr)[len]) {
    QuickSortImp(arr, 0, len - 1);
}

// print
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

    QuickSort(arr);

    cout << "after sort arr by basic: " << endl; 
    print(std::begin(arr), std::end(arr));
    return 0;
}
