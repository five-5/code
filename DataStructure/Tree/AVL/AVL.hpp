/*
 * @Author: five-5
 * @Description: avl
 * @Date: 2019-03-30
 * @LastEditTime: 2019-07-10 22:26:12
 */
#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>

namespace AVL_tree{
template<class src_type>
std::string Type2Str(src_type src) {
    std::stringstream ss;
    ss << src;
    std::string ret;
    ss >> ret;

    return ret;
}
template <typename K, typename V>
class AVL{
 private :
    class Node {
        public :
            K key_;
            V val_;
            Node *left, *right;
            int height;
            
        Node(K key, V value):key_(key), val_(value), left(nullptr), right(nullptr), height(1) {}
        ~Node() {
            if (left != nullptr) {
                delete left;
            }
            if (right != nullptr) {
                delete right;
            }
        }
    };
    Node *root;
    int size_;
    
 public:
    AVL(){
        root = nullptr;
        size_ = 0;
    }

    int size() {
        return size_;
    }

    bool empty() {
        return size_ == 0;
    }

    // 向sbt中添加新的元素e
    void Add(K key, V value) {
        root = Add(root, key, value);
    }

    // 看二分搜索树是否包含元素
    bool Contains(K key) {
        return Contains(root, key);
    }

    // set value
    void set(K key, V value) {
        Add(root, key, value);
    }

    // get value
    V get(K key) {
        Node *node = getNode(root, key);
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
        return Minimum(root)->key_;
    }

    // 查找最小值结点非递归版
    K MinimumNR(){
        if (size_ == 0){
            std::cout << "Error delete. There is no node in the bst." << std::endl;
            return K();
        }
        Node *pre = root;
        Node *cur = root;
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
        return Maximum(root)->key_;        
    }

    // 查找最大值非递归版
    K MaximumNR(){
        if (size_ == 0){
            std::cout << "Error delete. There is no node in the bst." << std::endl;
            return K();
        }
        Node *pre = root;
        Node *cur = root;
        while (cur->right){
            pre = cur;
            cur = cur->right;
        }
        return cur->key_;
    }

    // 从二分搜索树中删除最大值所在结点
    K RemoveMin() {
        K ret = Minimum();
        root = RemoveMin(root);
        return ret;
    }

    // 从二分搜索树中删除最小值所在结点
    K RemoveMax() {
        K ret = Maximum();
        root = RemoveMax(root);
        return ret;
    }
    
    // 从二分搜索树中删除元素k的结点
    V Remove(K key) {
       Node *node = remove(root, key);
       if (node == nullptr) {
           return V();
       } else {
           return node->val_;
       }
    }

    friend std::ostream & operator<< (std::ostream &out, const AVL &avl) {
        std::string res;
        avl.GengerateBSTString(avl.root, 0, res);
        out << res;
        return out;
    }

    // 中序遍历结果是升序
    bool isBST() {
        std::vector<K> keys;
        InOrder(root, keys);
        for (std::size_t i = 1; i < keys.size(); ++i) {
            if (keys[i] < keys[i-1]) {
                return false;
            }
        }

        return true;
    } 
    
    // 判断该二叉树是否是一棵平衡二叉树
    bool isBalanced() {
        return isBalanced(root);
    }

 private:
    // 判断以node为根的二叉树是否是一棵平衡二叉树，递归算法
    bool isBalanced(Node *node) {

        if (node == nullptr)
            return true;
        
        int balanceFactor = getBalanceFactor(node);
        if (abs(balanceFactor) > 1) {
            return false;
        } else {
            return isBalanced(node->left) && isBalanced(node->right);
        }
    }

    // isBST辅助函数
    void InOrder(Node *node, std::vector<K> &keys) {
        if (node == nullptr)
            return;
        
        InOrder(node->left, keys);
        keys.push_back(node->key_);
        InOrder(node->right, keys);
    }
    
    /* 对结点y进行向右旋转操作，返回旋转后新的根节点x
             y                              x
            / \                            /  \
           x   T4                         z    y
          /\         向右旋转(y)          / \   / \
         z  T3     ------------->      T1 T2  T3 T4
        / \
      T1  T2
        
    */
    Node* rightRotate(Node *y) {
        Node *x = y->left;
        Node *T3 = x->right;
        
        // 向右旋转过程
        x->right = y;
        y->left = T3;

        // 更新height
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    /* 对结点y进行向右旋转操作，返回旋转后新的根节点x
             y                              x
            / \                            /  \
          T1   x                          y    z
              /\         向左旋转(y)      / \   / \
            T2  z       -------------> T1 T2  T3 T4
              / \
            T3  T4
        
    */
    Node* leftRotate(Node *y) {
        Node *x = y->right;
        Node *T2 = x->left;
        
        // 向左旋转过程
        x->left = y;
        y->right = T2;

        // 更新height
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }
    
    // 向node为根的sbt中插入元素e,递归算法
    // 返回插入新结点后二分搜索树的根
     Node* Add(Node *node, K key, V value) {
        if (node == nullptr) {
            ++size_;
            return new Node(key, value);
        }

        if (node->key_ > key) {
            node->left = Add(node->left, key, value);
        } else if (node->key_ < key){
            node->right = Add(node->right, key, value);
        } else {
            node->val_ = value;
        }

        // 更新height
        node->height = std::max(height(node->left), height(node->right));

        // 计算平衡因子
        int balanceFactor = getBalanceFactor(node);
        if (abs(balanceFactor) > 1) {
            printf("unbalanced : %d\n", balanceFactor);
        }

        // 平衡维护
        // LL
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
            return rightRotate(node);  
        } 
        // RR
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
            return leftRotate(node);   
        }
        // LR
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        } 
        // RL
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }


        return node; // 二分搜索树插入元素之后的根还是这个node
    }

    // remove辅助函数
    Node* remove(Node *node, K key) {
        if (node == nullptr) {
            return nullptr;
        }

        Node *retNode;
        if (key < node->key_) {
            node->left = remove(node->left, key);
            retNode = node;
        } else if (key > node->key_) {
            node->right = remove(node->right, key);
            retNode = node;
        } else {
            // 待删除结点左子树为空的情况
            if (node->left == nullptr) {
                Node *rightNode = node->right;
                node->right = nullptr;
                --size_;
                retNode = rightNode;
            }

            // 待删除结点右子树为空的情况
            else if (node->right == nullptr) {
                Node *leftNode = node->left;
                node->left = nullptr;
                --size_;
                retNode = leftNode;
            } else {
                // 待删除结点左右子树均不为空的情况

                // 找到比待删除结点大的最小结点， 即待删除点右子树的最小结点
                // 用这个结点替代待删除结点的位置
                Node *successor = Minimum(node->right);
                successor->right = remove(node->right, successor->key_);
                successor->left = node->left;
                node->left = node->right = nullptr;
                retNode = successor;
            }
        }

        if (retNode == nullptr)
            return nullptr;

         // 更新height
        retNode->height = std::max(height(retNode->left), height(retNode->right));

        // 计算平衡因子
        int balanceFactor = getBalanceFactor(retNode);
        if (abs(balanceFactor) > 1) {
            printf("unbalanced : %d\n", balanceFactor);
        }

        // 平衡维护
        // LL
        if (balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0) {
            return rightRotate(retNode);  
        } 
        // RR
        if (balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0) {
            return leftRotate(retNode);   
        }
        // LR
        if (balanceFactor > 1 && getBalanceFactor(retNode->left) < 0) {
            retNode->left = leftRotate(retNode->left);
            return rightRotate(retNode);
        } 
        // RL
        if (balanceFactor < -1 && getBalanceFactor(retNode->right) > 0) {
            retNode->right = rightRotate(retNode->right);
            return leftRotate(retNode);
        }

        return retNode;
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

    // 获取结点node的高度
    int height(Node *node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // 获得结点node的平衡因子
    int getBalanceFactor(Node *node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

};
    
}

#endif