/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-04-04
 * @LastEditTime: 2019-04-04
 */
/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (47.17%)
 * Total Accepted:    188K
 * Total Submissions: 398.5K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0) {
            return result;
        }

        map<int, int> res;
        for (auto num1 : nums1) {
            if (res.find(num1) == res.end()) {
                res[num1] = 1;
            } else {
                ++res[num1];
            }
        }

        for (auto num2: nums2) {
            if (res.find(num2) != res.end()) {
                result.push_back(num2);
                --res[num2];
                if (res[num2] == 0) {
                    res.erase(num2);
                }
            }
        }

        return result;
    }
};

