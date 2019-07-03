/*
 * @Author: five-5
 * @Date: 2019-07-03 21:54:34
 * @Description: 
 * @LastEditTime: 2019-07-03 22:06:54
 */
/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */
#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

class NumArray {
template <typename T>
class SegmentTree{
 public:
    SegmentTree(T* arr, int lenth, const std::function<T (T , T)>& merge) {
       
        this->merge = merge;

        data_ = new T[lenth];
        data_lenth_ = lenth;
        for (int i = 0; i < lenth; ++i) {
            data_[i] = arr[i];
        }

        tree_ = new T[ 4 * lenth];
        tree_lenth_ = 4 * lenth;
        
        tree_flag_ = new bool[4 * tree_lenth_];
        for (int i = 0; i < tree_lenth_; ++i) {
            tree_flag_[i] = false;
        }

        BuildSegmentTree(0, 0, data_lenth_ - 1);
    }

    int size() {
        return data_lenth_;
    }

    T get(int index) {
        if (index < 0 || index >= data_lenth_) {
            throw  std::runtime_error("Index is illegal.");
        }
        return data_[index];
    }

    // 查询[queryL, queryR]的数据
    T query(int queryL, int queryR)
    {
        // 判断边界问题
        if (queryL < 0 || queryL >= data_lenth_ || queryR >= data_lenth_ || queryL > queryR) 
        {
            throw std::runtime_error("Invalid range.");
        }

        return query(0, 0, data_lenth_ - 1, queryL, queryR);
    }

    std::string toString()
    {
        std::string res = "[";
        for (int i = 0; i < tree_lenth_; ++i)
        {
            if (tree_flag_[i])
            {
                res += std::to_string(tree_[i]);
            } else {
                res += "nullptr";
            }
            if (i != tree_lenth_ - 1)
                res += " ";
        }
        res += "]";

        return res;
    }

    ~SegmentTree()
    {
        delete data_;
        delete tree_;
        delete tree_flag_;
    }
    
 private:
    // 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子结点的索引
    int LeftChild(int index) {
        return 2 * index + 1;
    }
    // 返回完全二叉树的数组表示张，一个索引所表示的元素的右孩子结点的索引
    int RightChild(int index) {
        return 2 * index + 2;
    }
    // 在tree_index的位置创建表示区间[l...r]的线段树
    void BuildSegmentTree(int tree_index, int l, int r) {
        
        if (l == r) {
            tree_[tree_index] = data_[l];
            tree_flag_[tree_index] = true;
            return;
        }

        int left_child_index = LeftChild(tree_index);
        int right_child_index = RightChild(tree_index);
       

        int mid = l + (r - l) / 2;
        BuildSegmentTree(left_child_index, l, mid);
        BuildSegmentTree(right_child_index, mid + 1, r);

        // 业务相关
        tree_[tree_index] = merge(tree_[left_child_index], tree_[right_child_index]);
        tree_flag_[tree_index] = true;

    }

    // 在范围为(l,r) index为tree_index的结点中查询范围queryL, queryR
    T query(int tree_index, int l, int r, int queryL, int queryR)
    {
        if ( l == queryL && r == queryR)
        {
            return tree_[tree_index];
        }

        int left_tree_index = LeftChild(tree_index);
        int right_tree_index = RightChild(tree_index);
        int mid = l + (r - l) / 2;

        if ( queryR <= mid)
        {
            return query(left_tree_index, l, mid, queryL, queryR);
        } else if (queryL >= mid + 1) {
            return query(right_tree_index, mid + 1, r, queryL, queryR);
        } else {
            T lResult = query(left_tree_index, l, mid, queryL, mid);
            T rResult = query(right_tree_index, mid + 1, r, mid + 1, queryR);
            return merge(lResult, rResult);
        }
    }

 private:
    T* data_;
    int data_lenth_;
    T* tree_;
    int tree_lenth_;
    bool* tree_flag_;
    std::function<T (T, T)> merge;
};
    
public:

    NumArray(std::vector<int>& nums) {
        if (nums.size() > 0){
            seg = new SegmentTree<int>(nums.data(), nums.size(), [](int a, int b){return a + b;});
        } else {
            seg = nullptr;
        }
    }
    
    int sumRange(int i, int j) {
        if (seg == nullptr) {
            throw std::runtime_error("invalid");
        } else {
            return seg->query(i, j);
        }
    }
    
private: SegmentTree<int> *seg;

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

