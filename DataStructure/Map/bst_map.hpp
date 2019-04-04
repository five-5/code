/*
 * @Author: five-5
 * @Description: implementation of map with bst
 * @Date: 2019-04-04
 * @LastEditTime: 2019-04-04
 */

#ifndef BST_MAP_H
#define BST_MAP_H

#include <iostream>

#include "map.h"
#include "../Tree/Binary Search Tree/BSTRecur.hpp"

using namespace std;
template <typename K, typename V>
class BSTMap: public Map<K,V> {
 public:
   BSTMap() {
       root_ = nullptr;
       size_ = 0;
   } 

    int size() override {
        return size_;
    }

    bool empty() override {
        return size_ == 0;
    }

    // 向二分搜索树中添加新的元素
    void add(K key, V value) override {
        root_ = add(root_, key, value);
    }

    // 查找key是否存在
    bool contains(K key) {
        return  GetNode(root_, key) != nullptr;
    }

    // 查找key对应的value
    V get(K key) {
        Node *node = GetNode(root_, key);
        return (node == nullptr)? V(): node->value_;
    }
    
    // 设置key对应的value
    void set(K key, V value) {
        Node *node = GetNode(root_, key);
        if (node == nullptr) {
            return;
        }

        node->value_ = value;
    }

    // 删除
    V remove(K key) {
        Node *node = GetNode(root_ , key);
        if (node == nullptr) {
            root_ = remove(root_, key);
            return node->value_;
        }

        return V();
    }

 private:
    class Node {
        public:
            K key_;
            V value_;
            Node *left_, *right_;
            Node(K key, V value):key_(key), value_(value), left_(nullptr), right_(nullptr){}
            
        friend std::ostream & operator<< (std::ostream &out, const Node &e) {
            out << "[" << e.key_ << "] = " << e.value_;
            return out;
        }
    };
    Node *root_;
    int size_;

    // 向以node为根的二分搜索树中插入元素，递归算法
    // 返回插入新节点后二分搜索树的根
    Node* add(Node *node, K key, V value) {
        if (node == nullptr) {
            ++size_;
            return new Node(key, value);
        }

        if (key < node->key_) {
            node->left_ = add(node->left_, key, value);
        } else if (key > node->key_) {
            node->right_ = add(node->right_, key, value);
        } else {
            node->value_ = value;
        }
        
        return node;
    }

    // 查询以node为二分搜索树根的树中是否有key_为key的结点
    Node* GetNode(Node *node, K key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key == node->key_) {
            return node;
        } else if (key < node->key_) {
            return GetNode(node->left_, key);
        } else {
            return GetNode(node->right_, key);
        } 
    }

    // 返回以node为根的二分搜索树的最小值所在的结点
    Node* minimum(Node *node) {
        if (node->left_ == nullptr) 
            return node;
        
        return minimum(node->left_);
    }

    // 删除以node为根的二分搜索树中的最小结点
    // 返回删除结点后新的二分搜索树的根
    Node* removeMin(Node *node) {
        if (node->left_ == nullptr) {
            Node *right_node = node->right_;
            delete node;
            --size_;
            return right_node;
        }

        node->left_ = removeMin(node->left_);
        return node;
    }

    // 删掉以node为根的二分搜索树中键值为key的结点，递归算法
    // 返回删除结点后新的二分搜索树的根
    Node* remove(Node *node, K key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->key_) {
            return remove(node->left_, key);
        } else if (key > node->key_) {
            return remove(node->right_, key);
        } else {
            // 待删除结点左子树为空的情况
            if (node->left_ == nullptr) {
                Node *right_node = node->right_;
                delete node;
                --size_;
                return right_node;
            }

            if (node->right_ == nullptr) {
                Node *left_node = node->left_;
                delete node;
                --size_;
                return left_node;
            }

            // 找到比待删结点大的最小结点，即待删结点的右子树的最小结点
            // 用这个结点顶替待删除结点的位置
            Node* successor = minimum(node->right_);
            successor->right_ = removeMin(node->right_);
            successor->left_ = node->left_;
            
            delete node;
            return successor;
        }


    }
};

#endif