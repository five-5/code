/*
 * @Author: five-5
 * @Date: 2019-07-09 17:38:41
 * @Description: 
 * @LastEditTime: 2019-07-09 19:34:06
 */

#include <random>
#include <iostream>
#include <ctime>

#include "UnionFind1.hpp"
#include "UnionFind2.hpp"
#include "UnionFind3.hpp"
#include "UnionFind4.hpp"
#include "UnionFind5.hpp"
#include "UnionFind6.hpp"

double testUF(UF *uf, int m) {
    int size = uf->size();
    clock_t start, end;
    
    start = clock();
    std::uniform_int_distribution<unsigned> u(0, size);
    std::default_random_engine e;
    for (int i = 0; i < m; ++i) {
        int a = u(e);
        int b = u(e);
        uf->unionElements(a, b);
    }

    for (int i = 0; i < m; ++i) {
        int a = u(e);
        int b = u(e);
        uf->isConnected(a, b);
    }

    end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    return duration;
    
}

int main()
{
    int size = 10000000;
    int m = 10000000;

    // 这种测试方法是种粗略的，随机生成的testcase不同，OS调度状态也不同，所以只能粗略去测试复杂度相差较大的数据结构
    // UnionFind1 uf1(size);
    // std::cout << "UnionFind1 : " << testUF(&uf1, m) << " s\n";

    // UnionFind2 uf2(size);
    // std::cout << "UnionFind2 : " << testUF(&uf2, m) << " s\n";

    UnionFind3 uf3(size);
    std::cout << "UnionFind3 : " << testUF(&uf3, m) << " s\n";

    UnionFind4 uf4(size);
    std::cout << "UnionFind4 : " << testUF(&uf4, m) << " s\n";

    UnionFind5 uf5(size);
    std::cout << "UnionFind5 : " << testUF(&uf5, m) << " s\n";

    UnionFind6 uf6(size);
    std::cout << "UnionFind6 : " << testUF(&uf6, m) << " s\n";

    return 0;
}