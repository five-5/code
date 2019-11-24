#include <iostream>
#include <algorithm>
#include <string>
#define maxn 30001

struct test_rank {
    std::string registration_number;
    int score;
    int final_rank;
    int location_number;
    int local_rank;
    void print() {
        std::cout << registration_number << " " << final_rank << " " << location_number << " " << local_rank << std::endl;
    }
} testees[maxn];

bool cmp(test_rank a, test_rank b) {
    if (a.score != b.score) return a.score > b.score;
    else return a.registration_number < b.registration_number;
}

void set_rank(int start, int end) {

    testees[start].local_rank = 1; // 排序后第一个排名一定是第一
    // 支持并列第一处理
    for (int i = 1; i <= end - start; ++i) {
        if (testees[start + i].score == testees[start + i -1].score) testees[start + i].local_rank = testees[start + i - 1].local_rank;
        else testees[start + i].local_rank = i + 1;
    }
}

int main()
{
    int n, k;
    int total = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> k;
        for (int j = 0; j < k; ++j, ++total) {
            std::cin >> testees[total].registration_number >> testees[total].score;
            testees[total].location_number = i;
        }
        // 局部sort
        std::sort(testees + total - k, testees + total, cmp);
        // 设置local rank
        set_rank(total - k, total - 1);
    }

    // 全局sort
    std::sort(testees, testees + total, cmp);
    std::cout << total << std::endl;
    int r = 1; // 考生排名
    for (int i = 0; i < total; ++i) {
        if (i > 0 && (testees[i].score != testees[i -1].score)) {
            r = i + 1;
        }
        testees[i].final_rank = r;
        testees[i].print();
    }
    return 0;
}
