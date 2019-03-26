/*
 * @Author: five-5
 * @Description: seq 8bit and step
 * @Date: 2019-03-26
 * @LastEditTime: 2019-03-26
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

int main()
{
    int n, step;
    std::vector<int> seq;
    while (std::cin >> n) {
        int num;
        for (int i = 0; i < n; ++i) {
            std::cin >> num;
            seq.push_back(num);
        }
        std::cin >> step;

        if (!seq.empty()) {
            int end = seq[n-1];
            unsigned char result = 0;
            std::set<int> seq_set(seq.begin(),seq.end());
            std::vector<int> last_seq;
            for (int i = n - 1; i >= 0; --i, end = end - step) {
                last_seq.push_back(end);
            }
            for (int i = n - 1; i >= 0; --i) {
                if (seq_set.find(last_seq[i]) != seq_set.end()){
                    result |= (0x01 << i);
                }
            }
            printf("%d\n", result);
        }
        
    }
}
