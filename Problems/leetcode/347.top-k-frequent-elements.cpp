/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-04-17
 * @LastEditTime: 2019-04-17
 */
/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (54.00%)
 * Total Accepted:    192K
 * Total Submissions: 354.1K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
/*#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;*/

class Solution {
private:
struct freq {
        int e_, fre_;
        freq(int e, int fre):e_(e),fre_(fre){}
        friend bool operator< (const freq & one, const freq & another) {
            return one.fre_ < another.fre_;
        }
        friend bool operator> (const freq & one, const freq & another) {
            return one.fre_ > another.fre_;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            if (frequency.find(nums[i]) != frequency.end()) {
                ++frequency[nums[i]];
            } else {
                frequency[nums[i]] = 1;
            }
        }
        
        // 小顶堆
        priority_queue<freq, vector<freq>, greater<freq>> q;
        
        for (auto it = frequency.begin(); it != frequency.end(); ++it) {
            if (q.size() < k) {
                q.push(freq(it->first,it->second));
            } else if (q.top().fre_ < it->second) {
                q.pop();
                q.push(freq(it->first,it->second));
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            auto it = result.begin();
            result.insert(it, q.top().e_);
            q.pop();
        }
       
        return result;
    }
};

/*int main() {
    vector<int> test_data {1,1,1,2,3,3};
    Solution solu;
    vector<int> result = solu.topKFrequent(test_data, 2);
    cout << "ans : " << endl;
    for(auto num : result) {
        cout << num << endl;
    }
}*/

