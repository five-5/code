/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-04-04
 * @LastEditTime: 2019-04-04
 */
/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (53.66%)
 * Total Accepted:    206.4K
 * Total Submissions: 384.6K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0) {
            return result;
        }

        set<int> num1_set(nums1.begin(), nums1.end());
        
        for(auto num2 : nums2) {
            if (num1_set.find(num2) != num1_set.end()) {
                result.push_back(num2);
                num1_set.erase(num2);// 防止num2中有重复数
            }
        }
        
        return result;
    }
};

