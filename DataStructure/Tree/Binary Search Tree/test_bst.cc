/*
 * @Author: five-5
 * @Description: test for bstrecur
 * @Date: 2019-03-30
 * @LastEditTime: 2019-03-30
 */

#include <random>
#include <vector>
#include "BSTRecur.hpp"

int main()
{
    BST<int> bst = BST<int>();
 /*   int num[] = {5, 3, 2, 6, 8};
    for(auto i : num) {
        bst.Add(i);
    }
    std::cout << bst << std::endl;
    std::cout << bst.RemoveMin() << std::endl;
    std::cout << bst << std::endl;*/
    

    int n = 50;
    int flag = 1;
    for (int i = 0; i < n; ++i) {
        bst.Add(i * flag);
        flag = -flag;
    }

    std::vector<int> nums;
    while (!bst.empty()) {
        nums.push_back(bst.RemoveMin());
    }

    for(auto num : nums) {
        std::cout << num << ",";
    }
    std::cout << std::endl;
  /*  for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] > nums[i]){
            std::cout << "Error min." << std::endl;
        }
    }

    std::cout << "Remove min test completed." << std::endl;*/

    bst.Remove(1);
    bst.Remove(2);
    std::cout << bst;

    // for (int i = 0; i < n; ++i) {
    //     bst.Add(i * flag);
    //     flag = -flag;
    // }

    // std::vector<int> nums_max;
    // while (!bst.empty()) {
    //     nums_max.push_back(bst.RemoveMax());
    // }

    // for(auto num : nums_max) {
    //     std::cout << num << ",";
    // }

    // for (size_t i = 1; i < nums_max.size(); ++i) {
    //     if (nums_max[i - 1] <  nums_max[i]){
    //         std::cout << "Error max." << std::endl;
    //         break;
    //     }
    // }

    // std::cout << "Remove max test completed." << std::endl;
    
    return 0;
}