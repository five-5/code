/*
 * @Author: five-5
 * @Date: 2019-07-11 22:42:26
 * @Description: implementation of RBTree
 * @LastEditTime: 2019-07-12 00:33:56
 */

#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>

enum COLOR{
  RED,
  BLACK
};

template <typename K, typename V>
class RBTree {
 private:
    class Node {
        public:
            COLOR color;
            K key_;
            V val_;
            Node *left, *right;
        
        Node(K key, V value):key_(key), val_(value), left(nullptr), right(nullptr), color(RED) {}
        ~Node() {
            if (left != nullptr) {
                delete left;
            }
            if (right != nullptr) {
                delete right;
            }
        }
    };
    Node *root_;
    int size_;

 public:

    RBTree() {
        root_ = nullptr;
        size_ = 0;
    }

    int size() {
        return size_;
    }

    bool empty() {
        return size_ == 0;
    }

    // 向红黑树中添加新的元素(key, value)
    void add(K key, V value) {
        root_ = add(root_, key, value);
        root_->color = BLACK;  // 最终根节点为黑色结点
    }

     // 看二分搜索树是否包含元素
    bool Contains(K key) {
        return Contains(root_, key);
    }

    // set value
    void set(K key, V value) {
        add(root_, key, value);
    }

    // get value
    V get(K key) {
        Node *node = getNode(root_, key);
        if (node == nullptr) {
            return V();
        } else {
            return node->val_;
        }
    }
     
    // 查找最小值结点递归版
    K Minimum(){
        if (size_ == 0){
            std::cout << "Error delete. There is no node in the bst." << std::endl;
            return K();
        }
        return Minimum(root_)->key_;
    }

    // 查找最小值结点非递归版
    K MinimumNR(){
        if (size_ == 0){
            std::cout << "Error delete. There is no node in the bst." << std::endl;
            return K();
        }
        Node *pre = root_;
        Node *cur = root_;
        while (cur->left){
            pre = cur;
            cur = cur->left;
        }
        return cur->key_;
    }

    // 查找最大值递归版
    K Maximum(){
        if (size_ == 0) {
            std::cout << "Error delete. There is no node in the bst." << std::endl;
            return K();
        }
        return Maximum(root_)->key_;        
    }

    // 查找最大值非递归版
    K MaximumNR(){
        if (size_ == 0){
            std::cout << "Error delete. There is no node in the bst." << std::endl;
            return K();
        }
        Node *pre = root_;
        Node *cur = root_;
        while (cur->right){
            pre = cur;
            cur = cur->right;
        }
        return cur->key_;
    }

    // 从二分搜索树中删除最大值所在结点
    K RemoveMin() {
        K ret = Minimum();
        root_ = RemoveMin(root_);
        return ret;
    }

    // 从二分搜索树中删除最小值所在结点
    K RemoveMax() {
        K ret = Maximum();
        root_ = RemoveMax(root_);
        return ret;
    }
    
    // 从二分搜索树中删除元素k的结点
    V Remove(K key) {
       Node *node = remove(root_, key);
       if (node == nullptr) {
           return V();
       } else {
           return node->val_;
       }
    }

    friend std::ostream & operator<< (std::ostream &out, const RBTree &rbt) {
        std::string res;
        rbt.GengerateBSTString(rbt.root_, 0, res);
        out << res;
        return out;
    }
  
  private:
   // 向以node为根的红黑树中插入元素(key, value)，递归算法
   // 返回插入新节点后红黑树的根
    Node *add(Node *node, K key, V value) {

        if (node == nullptr) {
            ++size_;
            return new Node(key, value); // 默认插入红色结点
        }    
        
        if (key < node->key_) {
            node->left = add(node->left, key, value);
        } else if (key > node->key_) {
            node->right = add(node->right, key, value);
        } else {
            node->val_ = value;
        }

        if (isRed(node->right) && !isRed(node->left))
            node = leftRotate(node);
        
        if (isRed(node->left) && isRed(node->left->left)) {
            rightRoate(node);
        }

        if (isRed(node->left) && isRed(node->right)) {
            flipColors(node);
        }

        return node;
    }

    /*
         node                     x
         /  \      左旋转        /  \
        T1   x   -------->    node  T3
            /  \              /  \
           T2  T3            T1  T2
    */

    Node *leftRotate(Node *node) {
        Node *x = node->right;
        
        // 左旋转
        node->right = x->left;
        x->left = node;

        x->color = node->color;
        node->color = RED;

        return x;
    }

    /*
            node                    x
            /  \      右旋转       /  \
           x   T2    ------->    y   node
          / \                        /  \   
         y  T1                      T1  T2
    */
   Node *rightRoate(Node *node) {
       
       Node *x = node->left;

       // 右旋转
       node->left = x->right;
       x->right = node;
       
       x->color = node->color;
       node->color = RED;

       return x;
   }

    // 判断结点node的颜色
    bool isRed(Node *node) {
        if (node == nullptr) {
            return BLACK;
        } 
        return node->color == RED;
    }

    // 颜色翻转
    void flipColors(Node *node) {

        node->color = RED;
        node->left->color = BLACK;
        node->right->color = BLACK;
    }


    // remove辅助函数
    Node* remove(Node *node, K key) {
        if (node == nullptr) {
            return nullptr;
        }

    
        if (key < node->key_) {
            node->left = remove(node->left, key);
            return node;
        } else if (key > node->key_) {
            node->right = remove(node->right, key);
            return node;
        } else {
            // 待删除结点左子树为空的情况
            if (node->left == nullptr) {
                Node *rightNode = node->right;
                node->right = nullptr;
                --size_;
                return rightNode;
            }

            // 待删除结点右子树为空的情况
            else if (node->right == nullptr) {
                Node *leftNode = node->left;
                node->left = nullptr;
                --size_;
                return leftNode;
            } else {
                // 待删除结点左右子树均不为空的情况

                // 找到比待删除结点大的最小结点， 即待删除点右子树的最小结点
                // 用这个结点替代待删除结点的位置
                Node *successor = Minimum(node->right);
                successor->right = remove(node->right, successor->key_);
                successor->left = node->left;
                node->left = node->right = nullptr;
                return successor;
            }
        }
    }


    // 看node为根的二分搜索树是否包含元素，递归算法
    bool Contains(Node *node, K key) {
        if (node == nullptr) {
            return false;
        }

        if (node->key_ == key) {
            return true;
        } else if (node->key_ > key) {
            return Contains(node->left, key);
        } else {
            return Contains(node->right, key);
        }
    }

    Node* getNode(Node *node, K key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->key_ == key) {
            return node;
        } else if (node->key_ > key) {
            return getNode(node->left, key);
        } else {
            return getNode(node->right, key);
        }
    }

    // 生成depth长度的字符串（表示递归调用的层次）
    std::string DepthString(int depth) const{
        std::string str;
        for (int i = 0; i < depth + 1; ++i) {
            str += '-';
        }
        return str;
    }

    // 生成以node为根节点，深度为depth的描述二叉树的字符串
    void GengerateBSTString(Node *node, int depth, std::string &res) const{
        if (node == nullptr) {
            res += DepthString(depth) + "nullptr\n";
            return;
        }

        res += DepthString(depth) + "k:" + Type2Str(node->key_) + " v:" + Type2Str(node->val_)  + "\n";
        GengerateBSTString(node->left, depth+1, res);
        GengerateBSTString(node->right, depth+1, res);
    }
    
    // 寻找二分搜索树的最小元素
    Node* Minimum(Node *node) {
        if (node->left == nullptr) {
            return node;
        } else {
            return Minimum(node->left);
        }
    }

    // 寻找二分搜索树的最大元素
    Node* Maximum(Node *node) {
        if (node->right == nullptr) {
            return node;
        } else {
            return Maximum(node->right);
        }
    }

    // 删除掉以node为根的二分搜索树中的最小结点
    // 返回删除结点后新的二分搜索树的根
    Node* RemoveMin(Node *node) {
        if (node->left == nullptr) {
            Node *right_node = node->right;
            delete node;
            --size_;
            return right_node;
        }

        node->left = RemoveMin(node->left);
        return node;
    }

    // 删除掉以node为根的二分搜索树中的最小结点
    // 返回删除结点后新的二分搜索树的根
    Node* RemoveMax(Node *node) {
        if (node->right == nullptr) {
            Node *left_node = node->left;
            delete node;
            --size_;
            return left_node;
        }

        node->right = RemoveMax(node->right);
        return node;
    }
};

#endif 